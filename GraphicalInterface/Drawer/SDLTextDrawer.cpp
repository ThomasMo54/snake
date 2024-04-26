#include "SDLTextDrawer.hpp"

void SDLTextDrawer::draw() const {
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text->get().c_str(), color);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_Rect textRect;
    textRect.x = text->getPosition().x;
    textRect.y = text->getPosition().y;
    textRect.w = textSurface->w;
    textRect.h = textSurface->h;

    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}