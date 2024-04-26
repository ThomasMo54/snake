#ifndef SNAKE_SDLSNAKEDRAWER_HPP
#define SNAKE_SDLSNAKEDRAWER_HPP

#include <SDL2/SDL.h>
#include <memory>
#include <utility>
#include "SDLObjectDrawer.hpp"
#include "GameObject/Snake/Snake.hpp"

class SDLSnakeDrawer : public SDLObjectDrawer {
public:
    explicit SDLSnakeDrawer(const std::shared_ptr<Snake> &snake): snake(snake) {}

    void draw() const override;

private:
    std::shared_ptr<Snake> snake;
};

#endif //SNAKE_SDLSNAKEDRAWER_HPP
