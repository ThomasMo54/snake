#ifndef SNAKE_OBSTACLE_HPP
#define SNAKE_OBSTACLE_HPP

#include "GameObject.hpp"

class Obstacle : public GameObject {
public:
    explicit Obstacle(const Vector2i &position): GameObject(position) {}

    void draw(const GraphicalInterface &gui) const override {
        gui.drawObstacle(*this);
    }
};

#endif //SNAKE_OBSTACLE_HPP
