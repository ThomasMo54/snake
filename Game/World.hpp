#ifndef SNAKE_WORLD_HPP
#define SNAKE_WORLD_HPP

#include <utility>
#include <vector>
#include <memory>
#include "Math/Vector2i.hpp"
#include "Game.hpp"
#include "GameObject/Snake.hpp"
#include "GameObject/Apple.hpp"
#include "GameObject/Obstacles.hpp"

class World : public std::enable_shared_from_this<World> {
public:
    explicit World(Game *game, int width, int height);

    inline int getWidth() const {
        return width;
    }

    inline int getHeight() const {
        return height;
    }

    inline Snake& getSnake() const {
        return *snake;
    }

    /**
     * Get a vector containing every free positions
     * @return the vector
     */
    std::vector<Vector2i> getFreePositions() const;

    /**
     * Check if the given position is free (= no obstacle or snake body part).
     * @param position the position to check
     * @return true if free, false otherwise
     */
    bool isFreePosition(const Vector2i &position) const;

    /**
     * Spawn an apple at a random position in the world
     */
    void randomlySpawnApple();

    /**
     * Check if the given position contains an apple
     * @param position the position to check
     * @return true if it contains an apple, false otherwise
     */
    bool isApple(const Vector2i &position) const;

private:
    int width, height;
    Game *game;
    std::shared_ptr<Snake> snake;
    std::shared_ptr<Apple> apple;
    std::shared_ptr<Obstacles> obstacles;
};

#endif //SNAKE_WORLD_HPP
