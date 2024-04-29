#ifndef SNAKE_STATE_HPP
#define SNAKE_STATE_HPP

#include <memory>
#include "Input/Input.hpp"
#include "GraphicalInterface/GraphicalInterface.hpp"

class State {
public:
    virtual void enter(const std::shared_ptr<GraphicalInterface> &gui) = 0;
    virtual void update() = 0;
    virtual std::shared_ptr<State> handleInput(Input input) = 0;
};

#endif //SNAKE_STATE_HPP
