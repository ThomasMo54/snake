#ifndef SNAKE_SNAKE_HPP
#define SNAKE_SNAKE_HPP

#include <queue>
#include <iterator>
#include "GameObject/GameObject.hpp"
#include "Input/Input.hpp"
#include "Energy.hpp"

/**
 * The snake object. Handles moving and growing.
 */
class Snake : public GameObject {
public:
    /**
     * Create a snake giving its head's position.
     * @param position the head's position
     */
    explicit Snake(const Vector2i &position): GameObject(position), energy(Energy(DEFAULT_ENERGY)) {
        currentDirection = Vector2i(1, 0);
        justGrew = false;
        initialize();
    }

    inline void setWorldSize(int width, int height) {
        this->worldWidth = width;
        this->worldHeight = height;
    }

    inline const Vector2i& getHead() const {
        return parts.front();
    }

    /**
     * Get the snake's body parts position.
     * @return the dequeue containing the positions
     */
    inline std::deque<Vector2i> getParts() const {
        return parts;
    }

    bool collision(const Vector2i &position) const override;

    /**
     * Move the snake toward the direction given by the input.
     */
    void move(Input input);

    /**
     * Make the snake grow.
     */
    void grow();

    const int* getEnergy();

    /**
     * Check if the snake has energy left.
     * @return true if it has energy, false otherwise
     */
    bool hasEnergyLeft();

private:
    static const int DEFAULT_SIZE = 3;
    static const int DEFAULT_ENERGY = 40;

    int worldWidth, worldHeight;
    Vector2i currentDirection;
    std::deque<Vector2i> parts;
    bool justGrew;
    Energy energy;

    void initialize();
};

#endif //SNAKE_SNAKE_HPP
