#include "Color.hpp"
#include <iostream>

using std::istream;

namespace prog {
    Color::~Color(){}
    Color::Color() {
        this->r = 0;
        this->g = 0;
        this->b = 0;
    }

    Color::Color(const Color &other) {
        this->r = other.r;
        this->g = other.g;
        this->b = other.b;
    }

    Color::Color(rgb_value red, rgb_value green, rgb_value blue) {
        this->r = red;
        this->g = green;
        this->b = blue;
    }

    rgb_value Color::red() const {
        return r;
    }

    rgb_value Color::green() const {
        return g;
    }

    rgb_value Color::blue() const {
        return b;
    }


    rgb_value &Color::red() {
        return r;
    }

    rgb_value &Color::green() {
        return g;
    }

    rgb_value &Color::blue() {
        return b;
    }
}


// Use to read color values from a script file.
istream &operator>>(istream &input, prog::Color &c) {
    int r, g, b;
    input >> r >> g >> b;
    c.red() = r;
    c.green() = g;
    c.blue() = b;
    return input;
}

std::ostream &operator<<(std::ostream &output, const prog::Color &c) {
    output << (int) c.red() << ":" << (int) c.green() << ":" << (int) c.blue();
    return output;
}
