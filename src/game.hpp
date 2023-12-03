#ifndef GAME_HPP
#define GAME_HPP

#include "gameconfig.hpp"
#include "galaxymap.hpp"

#include <iostream>
#include <random>


class Game {
private:
    GameConfig& config;
    GalaxyMap galaxymap;
    unsigned int turn_counter;
    double current_time;

    // The generator and distribution for checking probability
    std::mt19937 rng;
    std::uniform_real_distribution<> distribution;

#define ROLL(X) ((distribution(rng)) < (X))

public:
    Game(GameConfig& config, GalaxyMap galaxymap)
        : config(config), galaxymap(galaxymap), turn_counter(0), current_time(0),
          rng(), distribution(0.0, 1.0)
        {}

    // Perform a single turn and report any events to the given stream
    void turn(std::ostream& stream) {

        // Check for any new civilization spawns
        for (Star& star : galaxymap.stars) {
            if (star.civilization != nullptr) continue;
            double prob = config.prob_civ_spawn(star, current_time);
            if (ROLL(prob)) {
                star.spawn_new_civilization();
                stream << "New civilization spawned at star " << star << std::endl;
            }
        }

        // Check for tech increases
        for (Star& star : galaxymap.stars) {
            if (star.civilization == nullptr) continue;
            double prob = config.prob_tech_increase(
                *star.civilization,
                current_time
                );

            bool increased = false;

            // If the probability is greater than 1, we're assured to
            // increase
            if (prob > 1) {
                star.civilization->increase_technology_level(int(prob));
                prob -= int(prob);
                increased = true;
            }

            if (ROLL(prob - int(prob))) {
                star.civilization->increase_technology_level(1);
                increased = true;
            }

            if (increased)
                stream << "Civilization at star " << star
                       << " is now of technology level "
                       << star.civilization->get_technology_level()
                       << std::endl;
        }

        current_time += config.turn_time();
    }

    // Run the game for the specified number of turns
    void run(unsigned int turns, std::ostream& stream) {
        for (int i = 0; i < turns; i++) turn(stream);
    }
};

#endif
