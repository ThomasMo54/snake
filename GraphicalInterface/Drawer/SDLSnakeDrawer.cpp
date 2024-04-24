#include "SDLSnakeDrawer.hpp"
#include "Game/Game.hpp"

void SDLSnakeDrawer::draw() const {
    Vector2i head = snake->getParts()[0];
    drawSquare(head.x * Game::SQUARE_SIZE + 1, head.y * Game::SQUARE_SIZE + 1, Game::SQUARE_SIZE - 2, 0, 0, 255, true);
    for (int i = 1; i < snake->getParts().size(); i++) {
        Vector2i part = snake->getParts()[i];
        drawSquare(part.x * Game::SQUARE_SIZE + 1, part.y * Game::SQUARE_SIZE + 1, Game::SQUARE_SIZE - 2, 0, 255, 0, true);
    }
}