#ifndef SNAKE_SNAKE_HPP
#define SNAKE_SNAKE_HPP

#include <queue>
#include <iterator>
#include "GameObject.hpp"
#include "Game/World.hpp"

/**
 * The snake object. Handles moving and growing.
 */
class Snake : public GameObject {
public:
    /**
     * Create a snake giving its head's position.
     * @param position the head's position
     */
    explicit Snake(World *world): GameObject(position) {
        this->world = std::make_shared<World>(*world);
        currentDirection = Vector2i(1, 0);
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
        return currentDirection;
    }

    /**
     * Set the current currentDirection the snake is going to.
     * @param direction the currentDirection
     */
    inline void setDirection(const Vector2i &direction) {
        this->currentDirection = direction;
    }

    /**
     * Get the snake's body parts position.
     * @return the dequeue containing the positions
     */
    inline std::deque<Vector2i> getParts() const {
        return parts;
    }

    /**
     * Check if the snake has a body part at the given position
     * @param position the position
     * @return true if has a body part at the position, false otherwise
     */
    inline bool hasPartInPosition(const Vector2i &position) const {
        for (const auto &part : parts)
            if (part == position) return true;
        return false;
    }

    /**
     * Move the snake toward the given direction.
     */
    void move(const Vector2i &direction);

    /**
     * Make the snake grow.
     */
    void grow();

private:
    static const int DEFAULT_SIZE = 3;

    std::shared_ptr<World> world;
    Vector2i currentDirection;
    std::deque<Vector2i> parts;
    bool justGrew;

    void initialize();
};

#endif //SNAKE_SNAKE_HPP
