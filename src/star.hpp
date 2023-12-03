#ifndef STAR_HPP
#define STAR_HPP

#include "civilization.hpp"

#include <iostream>

class Star {
private:
    // The position of the star in 3D space
    double x, y, z;

    // The civilization currently living here.
    // nullptr if none is present
    Civilization* civilization;

public:
    Star(double x, double y, double z)
        : x(x), y(y), z(z), civilization(nullptr) {}

    // Create a new civilization here
    void spawn_new_civilization() {
        civilization = new Civilization();
    }

    double get_x() const { return x; }
    double get_y() const { return y; }
    double get_z() const { return z; }

    friend class Game;
};

std::ostream& operator<<(std::ostream& stream, const Star& star) {
    stream << "[" << star.get_x() << " " << star.get_y() << " " << star.get_z() << "]";
    return stream;
}

#endif
