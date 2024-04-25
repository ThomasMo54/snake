#ifndef SNAKE_GAMEOBJECT_HPP
#define SNAKE_GAMEOBJECT_HPP

#include "Math/Vector2i.hpp"

/**
 * The default any game object superclass.
 */
class GameObject {
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
     * Check if the given position is in collision with this object.
     * @param position the position
     * @return true if there is a collision, false otherwise
     */
    virtual bool collision(const Vector2i &position) const = 0;

protected:
    Vector2i position;
};

#endif //SNAKE_GAMEOBJECT_HPP
