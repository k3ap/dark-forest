#ifndef INFORMATION_HPP
#define INFORMATION_HPP

class Star;

class Information {
private:
    const Star* star;
    bool has_civilization;
    unsigned int technology_level;

public:
    bool get_has_civilization() { return has_civilization; }
    void set_has_civilization(bool civilization) { has_civilization = civilization; }

    unsigned int get_technology_level() { return technology_level; }
    void set_technology_level(unsigned int level) { technology_level = level; }
};

#endif
