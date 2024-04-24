#ifndef SNAKE_GAMEOBJECT_HPP
#define SNAKE_GAMEOBJECT_HPP

#include "Math/Vector2i.hpp"
#include "GraphicalInterface/GraphicalInterface.hpp"

/**
 * The default any game object superclass.
 */
class GameObject {
protected:
    Vector2i position;

public:
    /**
     * Create a game object by giving its initial position.
     * @param position
     */
    explicit GameObject(const Vector2i &position) {
        this->position = Vector2i(position);
    }

    /**
     * Get the current position of this game object.
     * @return the position
     */
    inline const Vector2i& getPosition() const {
        return position;
    }

    /**
     * Draw this game object on the screen.
     * @param gui the graphical interface
     */
    virtual void draw(const GraphicalInterface &gui) const = 0;
};

#endif //SNAKE_GAMEOBJECT_HPP
