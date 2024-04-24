#ifndef SNAKE_GRAPHICALINTERFACE_HPP
#define SNAKE_GRAPHICALINTERFACE_HPP

class Snake;
class Apple;
class Obstacle;

/**
 * The default superclass declaring the graphical user interface's necessary features.
 */
class GraphicalInterface {
public:
    /**
     * Clear the screen.
     */
    virtual void clear() const = 0;

    /**
     * Destroy the screen.
     */
    virtual void destroy() = 0;

    /**
     * Update screen.
     */
    virtual void update() = 0;

    /**
     * Draw a snake on the screen.
     * @param snake the snake
     */
    virtual void drawSnake(const Snake &snake) const = 0;

    /**
     * Draw an apple on the screen.
     * @param apple the apple
     */
    virtual void drawApple(const Apple &apple) const = 0;

    /**
     * Draw an obstacle on the screen.
     * @param obstacle the obstacle.
     */
    virtual void drawObstacle(const Obstacle &obstacle) const = 0;
};

#endif //SNAKE_GRAPHICALINTERFACE_HPP
