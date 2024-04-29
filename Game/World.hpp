#ifndef SNAKE_WORLD_HPP
#define SNAKE_WORLD_HPP

#include <utility>
#include <vector>
#include <memory>
#include "Math/Vector2i.hpp"
#include "GameObject/Snake/Snake.hpp"
#include "GameObject/Apple.hpp"
#include "GameObject/Obstacles.hpp"

class World {
public:
    explicit World(int width, int height): width(width), height(height) {}

    inline int getWidth() const {
        return width;
    }

    inline int getHeight() const {
        return height;
    }

    void randomlySpawnObstacles(const Snake& snake, std::shared_ptr<Obstacles>& obstacles, int amount);

    /**
     * Spawn an apple at a random free position in the world
     */
    void randomlySpawnApple(const Snake& snake, const Obstacles& obstacles, std::shared_ptr<Apple>& apple);

private:
    int width, height;

    /**
     * Get a vector containing every free positions
     * @return the vector
     */
    std::vector<Vector2i> getFreePositions(const Snake& snake, const Obstacles& obstacles) const;

};

#endif //SNAKE_WORLD_HPP
