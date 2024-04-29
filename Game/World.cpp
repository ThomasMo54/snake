#include "World.hpp"
#include "GameObject/Snake/Snake.hpp"

#include <random>

std::random_device dev;
std::mt19937 rng(dev());

std::vector<Vector2i> World::getFreePositions(const Snake& snake, const Obstacles& obstacles) const {
    std::vector<Vector2i> freePositions;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            const Vector2i position(x, y);

            // Check if there is a snake body part or an obstacle in this position, if not we add the position to the
            // vector
            if (!snake.collision(position) && !obstacles.collision(position)) {
                freePositions.push_back(position);
            }
        }
    }

    return freePositions;
}

void World::randomlySpawnObstacles(const Snake& snake, std::shared_ptr<Obstacles>& obstacles, int amount) {
    for (int i = 0; i < amount; i++) {
        std::vector<Vector2i> freePositions = getFreePositions(snake, *obstacles);

        // Select a random free position
        std::uniform_int_distribution<std::mt19937::result_type> dist6(0, freePositions.size() - 1);
        unsigned long positionIndex = dist6(rng);
        Vector2i position = freePositions[positionIndex];
        obstacles->addObstacle(Obstacle(position));
    }
}

void World::randomlySpawnApple(const Snake& snake, const Obstacles& obstacles, std::shared_ptr<Apple>& apple) {
    std::vector<Vector2i> freePositions = getFreePositions(snake, obstacles);

    // Select a random free position
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, freePositions.size() - 1);
    unsigned long positionIndex = dist6(rng);
    Vector2i position = freePositions[positionIndex];

    if (apple == nullptr) {
        apple = std::make_shared<Apple>(Apple(position));
    } else {
        *apple = Apple(position);
    }
}