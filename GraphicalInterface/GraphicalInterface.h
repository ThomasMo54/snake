#ifndef SNAKE_GRAPHICALINTERFACE_H
#define SNAKE_GRAPHICALINTERFACE_H

#include "../GameObject/Snake.h"
#include "../GameObject/Apple.h"
#include "../GameObject/Obstacle.h"

/**
 * The default superclass declaring the graphical user interface's necessary features.
 */
class GraphicalInterface {
public:
    virtual void drawSnake(const Snake &snake) = 0;

    virtual void drawApple(const Apple &apple) = 0;

    virtual void drawObstacle(const Obstacle &obstacle) = 0;
};

#endif //SNAKE_GRAPHICALINTERFACE_H
