#ifndef CIVILIZATION_HPP
#define CIVILIZATION_HPP

class Civilization {
private:
    unsigned int technology_level;

public:
    Civilization()
        : technology_level(0) {}

    void increase_technology_level(int value) {
        if (value < 0 && technology_level < -value) technology_level = 0;
        else technology_level += value;
    }

    unsigned int get_technology_level() const {
        return technology_level;
    }
};

#endif
