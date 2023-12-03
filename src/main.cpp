#include "game.hpp"
#include "gameconfig.hpp"
#include "galaxymap.hpp"

#include <iostream>

const unsigned int NUM_STARS = 2000;

// The default config. Distances are mesured in light-years, and time in years.
class DefaultConfig : public GameConfig {
    double c() {
        return 1;
    }

    double turn_time() {
        return 20;
    }

    // We regard technological growth to be exponential
    double prob_tech_increase(const Civilization& civ, double time) {
        return 5e-3 + 1e-2 * civ.get_technology_level();
    }

    double prob_civ_spawn(const Star& star, double time) {
        if (time < 1) return 2.0 / (double)NUM_STARS;
        else return 1e-8;
    }

} defaultconfig;

int main() {
    GalaxyMap map = GalaxyMap::get_random_map(NUM_STARS, 500);
    Game game(defaultconfig, map);

    while (true) {
        game.run(100, std::cout);
        int t;
        std::cin >> t;
    }

    return 0;
}
