#ifndef GALAXYMAP_HPP
#define GALAXYMAP_HPP

#include <vector>
#include <random>

#include "star.hpp"

class GalaxyMap {
private:
    std::vector<Star> stars;

public:
    GalaxyMap(std::vector<Star> stars)
        : stars(stars) {}

    // Generate a random GalaxyMap, with all stars positioned randomly uniformly
    // inside [-box_size/2, box_size/2]³.
    static GalaxyMap get_random_map(unsigned int num_stars, double box_size) {
        std::mt19937 gen;
        std::uniform_real_distribution<> dis(-box_size/2, box_size/2);
        std::vector<Star> stars;
        for (int i = 0; i < num_stars; i++) {
            stars.push_back(Star(dis(gen), dis(gen), dis(gen)));
        }
        return GalaxyMap(stars);
    }

    friend class Game;
};

#endif
