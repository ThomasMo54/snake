#ifndef SNAKE_CONTROL_HPP
#define SNAKE_CONTROL_HPP

#include "GameObject/Snake.hpp"

class Control {
public:
    virtual void execute(Snake &snake) = 0;
};

#endif //SNAKE_CONTROL_HPP
