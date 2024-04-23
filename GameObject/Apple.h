#ifndef SNAKE_APPLE_H
#define SNAKE_APPLE_H

#include "GameObject.h"

class Apple : public GameObject {
public:
    explicit Apple(const Vector2i &position): GameObject(position) {}

    void draw(const GraphicalInterface &gui) const override {
        gui.drawApple(*this);
    }
};

#endif //SNAKE_APPLE_H
