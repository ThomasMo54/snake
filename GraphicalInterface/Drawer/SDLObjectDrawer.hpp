#ifndef SNAKE_SDLOBJECTDRAWER_HPP
#define SNAKE_SDLOBJECTDRAWER_HPP

#include <SDL2/SDL.h>
#include <memory>
#include "ObjectDrawer.hpp"

class SDLObjectDrawer : public ObjectDrawer {
public:
    inline void setRenderer(SDL_Renderer *sdlRenderer) {
        this->renderer = sdlRenderer;
    }

protected:
    SDL_Renderer *renderer = nullptr;

    void drawSquare(int x, int y, int size, int r, int g, int b, bool fill) const;
};

#endif //SNAKE_SDLOBJECTDRAWER_HPP
