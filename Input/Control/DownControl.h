#ifndef SNAKE_DOWNCONTROL_H
#define SNAKE_DOWNCONTROL_H

#include "Control.hpp"

class DownControl : public Control {
public:
    void execute(Snake &snake) override {
        snake.move(Vector2i(0, 1));
    }
};

#endif //SNAKE_DOWNCONTROL_H
