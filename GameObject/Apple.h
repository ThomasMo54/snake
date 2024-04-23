#ifndef SNAKE_APPLE_H
#define SNAKE_APPLE_H

#include "GameObject.h"

class Apple : public GameObject {
public:
    explicit Apple(const Vector2i &position): GameObject(position) {}
};

#endif //SNAKE_APPLE_H
