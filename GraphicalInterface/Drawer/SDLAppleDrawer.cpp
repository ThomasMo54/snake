#include "SDLAppleDrawer.hpp"
#include "Game/Game.hpp"

void SDLAppleDrawer::draw() const {
    const Vector2i &position = apple->getPosition();
    drawSquare(position.x * Game::SQUARE_SIZE, position.y * Game::SQUARE_SIZE, Game::SQUARE_SIZE, 255, 0, 0, true);
}
