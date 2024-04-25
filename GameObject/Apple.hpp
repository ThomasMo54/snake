#ifndef SNAKE_APPLE_HPP
#define SNAKE_APPLE_HPP

#include "GameObject.hpp"

class Apple : public GameObject {
public:
    explicit Apple(const Vector2i &position): GameObject(position) {}

    inline bool collision(const Vector2i &position) const override {
        return this->position == position;
    }
};

#endif //SNAKE_APPLE_HPP
