#ifndef SNAKE_SNAKE_HPP
#define SNAKE_SNAKE_HPP

#include <queue>
#include <iterator>
#include "GameObject.hpp"

/**
 * The snake object. Handles moving and growing.
 */
class Snake : public GameObject {
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
    void move();

    /**
     * Add one body part to the snake.
     */
    void grow();

private:
    static const int DEFAULT_SIZE = 3;

    Vector2i direction;
    std::deque<Vector2i> parts;
    bool justGrew;

    void initialize();
};

#endif //SNAKE_SNAKE_HPP
