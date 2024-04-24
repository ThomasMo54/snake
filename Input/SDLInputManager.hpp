#ifndef SNAKE_SDLINPUTMANAGER_HPP
#define SNAKE_SDLINPUTMANAGER_HPP

#include <SDL2/SDL.h>
#include "InputManager.hpp"

class SDLInputManager : public InputManager {
public:
    inline bool isKeyDown(int keyCode) const override {
        return SDL_GetKeyboardState(nullptr)[keyCode];
    }
};

#endif //SNAKE_SDLINPUTMANAGER_HPP
