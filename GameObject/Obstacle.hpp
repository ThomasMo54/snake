#ifndef SNAKE_OBSTACLE_HPP
#define SNAKE_OBSTACLE_HPP

#include "GameObject.hpp"

class Obstacle : public GameObject {
public:
    explicit Obstacle(const Vector2i &position): GameObject(position) {}

    bool collision(const Vector2i &position) const override {
        return this->position == position;
    }
};

#endif //SNAKE_OBSTACLE_HPP
