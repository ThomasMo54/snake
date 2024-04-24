#ifndef SNAKE_APPLE_HPP
#define SNAKE_APPLE_HPP

#include "GameObject.hpp"

class Apple : public GameObject {
public:
    explicit Apple(const Vector2i &position): GameObject(position) {}

    void draw(const GraphicalInterface &gui) const override {
        gui.drawApple(*this);
    }
};

#endif //SNAKE_APPLE_HPP
