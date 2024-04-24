#ifndef SNAKE_SDLAPPLEDRAWER_HPP
#define SNAKE_SDLAPPLEDRAWER_HPP

#include <SDL2/SDL.h>
#include <memory>
#include <utility>
#include "SDLObjectDrawer.hpp"
#include "GameObject/Apple.hpp"

class SDLAppleDrawer : public SDLObjectDrawer {
public:
    explicit SDLAppleDrawer(const std::shared_ptr<Apple> &apple): apple(apple) {}

    void draw() const override;

private:
    std::shared_ptr<Apple> apple;
};

#endif //SNAKE_SDLAPPLEDRAWER_HPP
