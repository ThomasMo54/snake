#ifndef SNAKE_GAMEOBJECT_H
#define SNAKE_GAMEOBJECT_H

#include "../Math/Vector2i.h"

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
};

#endif //SNAKE_GAMEOBJECT_H
