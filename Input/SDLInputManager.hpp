#ifndef SNAKE_SDLINPUTMANAGER_HPP
#define SNAKE_SDLINPUTMANAGER_HPP

#include <SDL2/SDL.h>
#include "InputManager.hpp"

class SDLInputManager : public InputManager {
public:
    Input handleInputs() const override {
        if (isKeyDown(SDL_SCANCODE_LEFT)) {
            return Input::LEFT;
        }
        if (isKeyDown(SDL_SCANCODE_RIGHT)) {
            return Input::RIGHT;
        }
        if (isKeyDown(SDL_SCANCODE_UP)) {
            return Input::UP;
        }
        if (isKeyDown(SDL_SCANCODE_DOWN)) {
            return Input::DOWN;
        }
        return Input::VOID;
    }

private:
    inline bool isKeyDown(int keyCode) const override {
        return SDL_GetKeyboardState(nullptr)[keyCode];
    }
};

#endif //SNAKE_SDLINPUTMANAGER_HPP
