#ifndef SNAKE_GRAPHICALINTERFACE_HPP
#define SNAKE_GRAPHICALINTERFACE_HPP

#include "Drawer/ObjectDrawer.hpp"

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
     * Draw every registered objects.
     */
    virtual void drawObjects() const = 0;

    /**
     * Add an object to draw.
     * @param objectDrawer the object to draw
     */
    virtual void addObject(ObjectDrawer *objectDrawer) = 0;

    /**
     * Remove all objects to draw.
     */
    virtual void clearObjects() = 0;

    /**
     * Destroy the screen.
     */
    virtual void destroy() = 0;
};

#endif //SNAKE_GRAPHICALINTERFACE_HPP
