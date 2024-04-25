#include "World.hpp"
#include "GameObject/Snake.hpp"
#include "GraphicalInterface/Drawer/SDLSnakeDrawer.hpp"
#include "GraphicalInterface/Drawer/SDLAppleDrawer.hpp"
#include "GraphicalInterface/Drawer/SDLObstacleDrawer.hpp"

#include <utility>
#include <random>

std::random_device dev;
std::mt19937 rng(dev());

World::World(Game *game, int width, int height) {
    this->game = game;
    this->width = width;
    this->height = height;

    // Spawn snake in the center of the world
    std::shared_ptr<World> sharedWorld = shared_from_this();
    Snake s(this, Vector2i(width / 2, height / 2));
    this->snake = std::make_unique<Snake>(s);

    // Randomly spawn an apple
    randomlySpawnApple();

    // Add some obstacles
    for (int i = 10; i < 30; i++) {
        obstacles->addObstacle(Obstacle(Vector2i(i, 5)));
    }

    game->addObject(new SDLSnakeDrawer(snake));
    game->addObject(new SDLAppleDrawer(apple));
    for (const auto &obstacle : obstacles->getObstacles()) {
        game->addObject(new SDLObstacleDrawer(std::make_shared<Obstacle>(obstacle)));
    }
}

std::vector<Vector2i> World::getFreePositions() const {
    std::vector<Vector2i> freePositions;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            const Vector2i position(x, y);

            // Check if there is a snake body part or an obstacle in this position, if not we add the position to the
            // vector
            if (!snake->hasPartInPosition(position) && !obstacles->isObstacleInPosition(position)) {
                freePositions.push_back(position);
            }
        }
    }

    return freePositions;
}

bool World::isFreePosition(const Vector2i &position) const {
    for (const auto &freePosition: getFreePositions())
        if (freePosition == position) return true;
    return false;
}

bool World::isApple(const Vector2i &position) const {
    return apple->getPosition() == position;
}

void World::randomlySpawnApple() {
    std::vector<Vector2i> freePositions = getFreePositions();

    // Select a random free position
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, freePositions.size() - 1);
    unsigned long positionIndex = dist6(rng);
    Vector2i position = freePositions[positionIndex];

    if (apple != nullptr) {
        *apple = Apple(position);
    } else {
        apple = std::make_shared<Apple>(Apple(position));
    }
}