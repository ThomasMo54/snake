#ifndef SNAKE_SDLTEXTDRAWER_HPP
#define SNAKE_SDLTEXTDRAWER_HPP

#include <SDL2/SDL_ttf.h>
#include <memory>
#include <string>
#include <iostream>
#include "SDLObjectDrawer.hpp"
#include "GameObject/Text/Text.hpp"
#include "GraphicalInterface/Color.hpp"

class SDLTextDrawer : public SDLObjectDrawer {
public:
    explicit SDLTextDrawer(const std::shared_ptr<Text>& text, const char* fontName, int size, Color color): text(text) {
        font = TTF_OpenFont(fontName, size);
        std::cout << TTF_GetError() << std::endl;
        this->color = { color.r, color.g, color.b, color.a };
    }

    void draw() const override;

private:
    std::shared_ptr<Text> text;
    TTF_Font* font;
    SDL_Color color;
};

#endif //SNAKE_SDLTEXTDRAWER_HPP
