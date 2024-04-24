#include "SDLGraphicalInterface.hpp"
#include "Exception/SDLException.hpp"
#include "Math/Vector2i.hpp"

SDLGraphicalInterface::SDLGraphicalInterface() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw SDLException(SDL_GetError());
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
    this->update();
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

void SDLGraphicalInterface::update() {
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

void SDLGraphicalInterface::drawSnake(const Snake &snake) const {
    Vector2i head = snake.getParts()[0];
    drawSquare(head.x * SQUARE_SIZE + 1, head.y * SQUARE_SIZE + 1, SQUARE_SIZE - 2, 0, 0, 255, true);
    for (int i = 1; i < snake.getParts().size(); i++) {
        Vector2i part = snake.getParts()[i];
        drawSquare(part.x * SQUARE_SIZE + 1, part.y * SQUARE_SIZE + 1, SQUARE_SIZE - 2, 0, 255, 0, true);
    }
}

void SDLGraphicalInterface::drawApple(const Apple &apple) const {
    const Vector2i &position = apple.getPosition();
    drawSquare(position.x * SQUARE_SIZE, position.y * SQUARE_SIZE, SQUARE_SIZE, 255, 0, 0, true);
}

void SDLGraphicalInterface::drawObstacle(const Obstacle &obstacle) const {
    const Vector2i &position = obstacle.getPosition();
    drawSquare(position.x * SQUARE_SIZE, position.y * SQUARE_SIZE, SQUARE_SIZE, 255, 0, 255, false);
}

void SDLGraphicalInterface::drawSquare(int x, int y, int size, int r, int g, int b, bool fill) const {
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