#include "SDLGraphicalInterface.hpp"
#include "Exception/SDLException.hpp"

SDLGraphicalInterface::SDLGraphicalInterface() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw SDLException(SDL_GetError());
    }

    if (TTF_Init() != 0) {
        throw SDLException(TTF_GetError());
    }

    window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 400, 0);
    if (window == nullptr) {
        throw SDLException(SDL_GetError());
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        throw SDLException(SDL_GetError());
    }

    this->clear();
    SDL_RenderPresent(renderer);
}

void SDLGraphicalInterface::clear() const {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void SDLGraphicalInterface::destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void SDLGraphicalInterface::drawObjects() const {
    clear();

    for (auto & object : objects) {
        object->draw();
    }

    SDL_RenderPresent(renderer);

    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        switch (event.type) {
            case SDL_QUIT:
                exit(0);
            default:
                break;
        }
    }

    // Sleep between frames to slow the game down
    SDL_Delay(150);
}

void SDLGraphicalInterface::addObject(ObjectDrawer *objectDrawer) {
    auto *sdlObjectDrawer = (SDLObjectDrawer*) objectDrawer;
    sdlObjectDrawer->setRenderer(renderer);
    objects.push_front(sdlObjectDrawer);
}

void SDLGraphicalInterface::clearObjects() {
    for (auto & object : objects) {
        delete object;
    }
    objects.clear();
}
