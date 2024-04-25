#ifndef SNAKE_RIGHTCONTROL_H
#define SNAKE_RIGHTCONTROL_H

#include "Control.hpp"

class RightControl : public Control {
public:
    void execute(Snake &snake) override {
        snake.move(Vector2i(1, 0));
    }
};

#endif //SNAKE_RIGHTCONTROL_H
