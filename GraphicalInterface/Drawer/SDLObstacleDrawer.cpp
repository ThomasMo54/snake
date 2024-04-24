#include "SDLObstacleDrawer.hpp"
#include "Game/Game.hpp"

void SDLObstacleDrawer::draw() const {
    const Vector2i &position = obstacle->getPosition();
    drawSquare(position.x * Game::SQUARE_SIZE, position.y * Game::SQUARE_SIZE, Game::SQUARE_SIZE, 255, 0, 255, false);
}
