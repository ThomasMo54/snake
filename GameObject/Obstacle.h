#ifndef SNAKE_OBSTACLE_H
#define SNAKE_OBSTACLE_H

#include "GameObject.h"

class Obstacle : public GameObject {
public:
    explicit Obstacle(const Vector2i &position): GameObject(position) {}
};

#endif //SNAKE_OBSTACLE_H
