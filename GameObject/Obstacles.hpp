#ifndef SNAKE_OBSTACLES_HPP
#define SNAKE_OBSTACLES_HPP

#include <vector>
#include "Obstacle.hpp"

class Obstacles {
public:
    inline std::vector<Obstacle> getObstacles() const {
        return obstacles;
    }

    inline void addObstacle(const Obstacle &obstacle) {
        obstacles.push_back(obstacle);
    }

    /**
     * Check if there is an obstacle at the given position
     * @param position the position
     * @return true if there is an obstacle at the position, false otherwise
     */
    inline bool isObstacleInPosition(const Vector2i &position) const {
        for (const auto &obstacle : obstacles)
            if (obstacle.getPosition() == position) return true;
        return false;
    }

private:
    std::vector<Obstacle> obstacles;
};

#endif //SNAKE_OBSTACLES_HPP
