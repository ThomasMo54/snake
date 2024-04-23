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
    /**
     * Clear the screen.
     */
    virtual void clear() = 0;

    /**
     * Destroy the screen.
     */
    virtual void destroy() = 0;

    /**
     * Draw a snake on the screen.
     * @param snake the snake
     */
    virtual void drawSnake(const Snake &snake) = 0;

    /**
     * Draw an apple on the screen.
     * @param apple the apple
     */
    virtual void drawApple(const Apple &apple) = 0;

    /**
     * Draw an obstacle on the screen.
     * @param obstacle the obstacle.
     */
    virtual void drawObstacle(const Obstacle &obstacle) = 0;
};

#endif //SNAKE_GRAPHICALINTERFACE_H
