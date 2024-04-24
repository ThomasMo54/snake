#include <SDL2/SDL.h>
#include "SDLObjectDrawer.hpp"

void SDLObjectDrawer::drawSquare(int x, int y, int size, int r, int g, int b, bool fill) const {
    // Set color
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);

    // Create square's bounds
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = size;
    rect.h = size;

    // Draw square
    if (fill) {
        SDL_RenderFillRect(renderer, &rect);
    } else {
        SDL_RenderDrawRect(renderer, &rect);
    }
}