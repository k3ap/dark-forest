#ifndef GAMECONFIG_HPP
#define GAMECONFIG_HPP

#include "civilization.hpp"
#include "star.hpp"

class GameConfig {
public:
    // The speed of information (speed of light), measured in units of
    // [distance] / [time]
    virtual double c() = 0;

    // How many [time] units are in a time step
    virtual double turn_time() = 0;

    // The probability that a civilization's technology level will increase
    // in a given turn.
    virtual double prob_tech_increase(
        const Civilization& civilization,
        double current_time) = 0;

    // The probability that a new civilization will spawn around the given
    // star system in the given turn.
    // If the result is greater than 1, always add floor(result) to tech level,
    // and roll for result-floor(result)
    virtual double prob_civ_spawn(const Star& star, double current_time) = 0;
};

#endif
