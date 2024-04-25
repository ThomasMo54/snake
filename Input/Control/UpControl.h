#ifndef SNAKE_UPCONTROL_H
#define SNAKE_UPCONTROL_H

#include "Control.hpp"

class UpControl : public Control {
public:
    void execute(Snake &snake) override {
        snake.move(Vector2i(0, -1));
    }
};

#endif //SNAKE_UPCONTROL_H
