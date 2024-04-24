#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <queue>
#include <iterator>
#include "GameObject.h"

/**
 * The snake object. Handles moving and growing.
 */
class Snake : public GameObject {
    static const int DEFAULT_SIZE = 3;

    Vector2i direction;
    std::deque<Vector2i> parts;
    bool justGrew;

    void initialize() {
        // The position of the tail
        Vector2i tailPosition = position - direction * DEFAULT_SIZE;

        // Add all snake's body parts starting from its tail
        parts.push_front(tailPosition);
        for (int i = 0; i < DEFAULT_SIZE - 1; i++) {
            parts.push_front(parts.front() + direction);
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

    inline const Vector2i& getHead() const {
        return parts.front();
    }

    inline void setHead(const Vector2i &head) {
        parts.pop_front();
        parts.push_front(head);
    }

    inline const Vector2i& getDirection() const {
        return direction;
    }

    /**
     * Set the current direction the snake is going to.
     * @param direction the direction
     */
    inline void setDirection(const Vector2i &direction) {
        this->direction = direction;
    }

    /**
     * Get the snake's body parts position.
     * @return the dequeue containing the positions
     */
    inline std::deque<Vector2i> getParts() const {
        return parts;
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
        parts.push_front(nextHead);

        // If the snake did not just grow then we remove its tail
        if (justGrew) {
            justGrew = false;
        } else {
            parts.pop_back();
        }
    }

    /**
     * Add one body part to the snake.
     */
    inline void grow() {
        justGrew = true;
    }

    void draw(const GraphicalInterface &gui) const override {
        gui.drawSnake(*this);
    }
};

#endif //SNAKE_SNAKE_H
