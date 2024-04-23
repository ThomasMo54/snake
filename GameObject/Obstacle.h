#ifndef SNAKE_OBSTACLE_H
#define SNAKE_OBSTACLE_H

#include "GameObject.h"

class Obstacle : public GameObject {
public:
    explicit Obstacle(const Vector2i &position): GameObject(position) {}

    void draw(const GraphicalInterface &gui) const override {
        gui.drawObstacle(this);
    }
};

#endif //SNAKE_OBSTACLE_H
