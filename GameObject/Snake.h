#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <queue>
#include "GameObject.h"

/**
 * The snake object. Handles moving and growing.
 */
class Snake : public GameObject {
    static const int DEFAULT_SIZE;

    Vector2i direction;
    queue<Vector2i> parts;
    bool justGrew;

    void initialize() {
        // The position of the tail
        Vector2i tailPosition = position - direction * DEFAULT_SIZE;

        // Add all snake's body parts starting from its tail
        parts.push(tailPosition);
        for (int i = 0; i < DEFAULT_SIZE - 1; i++) {
            parts.push(parts.front() + direction);
        }
    }

public:
    /**
     * Create a snake giving its head's position.
     * @param position the head's position
     */
    explicit Snake(const Vector2i &position): GameObject(position) {
        direction = Vector2i(1, 0);
        justGrew = false;
        initialize();
    }

    /**
     * Set the current direction the snake is going to.
     * @param direction the direction
     */
    inline void setDirection(const Vector2i &direction) {
        this->direction = direction;
    }

    /**
     * Move the snake toward its current direction.
     */
    void move() {
        // Retreive the snake's head position
        Vector2i head = parts.front();

        // Compute the next head position
        Vector2i nextHead = head + direction;

        // Add the next head position to the body parts
        parts.push(nextHead);

        // If the snake did not just grow then we remove its tail
        if (justGrew) {
            justGrew = false;
        } else {
            parts.pop();
        }
    }

    /**
     * Add one body part to the snake.
     */
    inline void grow() {
        justGrew = true;
    }
};

#endif //SNAKE_SNAKE_H
