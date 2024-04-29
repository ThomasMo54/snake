#ifndef SNAKE_MENUSTATE_HPP
#define SNAKE_MENUSTATE_HPP

#include "State.hpp"

class MenuState : public State {
public:
    void enter(const std::shared_ptr<GraphicalInterface> &gui) override;

    void update() override;

    std::shared_ptr<State> handleInput(Input input) override;
};

#endif //SNAKE_MENUSTATE_HPP
