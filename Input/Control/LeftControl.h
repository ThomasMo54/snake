#ifndef SNAKE_LEFTCONTROL_H
#define SNAKE_LEFTCONTROL_H

#include "Control.hpp"

class LeftControl : public Control {
public:
    void execute(Snake &snake) override {
        snake.move(Vector2i(-1, 0));
    }
};

#endif //SNAKE_LEFTCONTROL_H
