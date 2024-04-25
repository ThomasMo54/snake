#include "Snake.hpp"

void Snake::initialize() {
    // The position of the tail
    Vector2i tailPosition = position - currentDirection * DEFAULT_SIZE;

    // Add all snake's body parts starting from its tail
    parts.push_front(tailPosition);
    for (int i = 0; i < DEFAULT_SIZE - 1; i++) {
        parts.push_front(parts.front() + currentDirection);
    }
}

bool Snake::collision(const Vector2i &position) const {
    for (int i = 1; i < parts.size(); i++) {
        if (parts[i] == position) return true;
    }
    return false;
}

void Snake::move(Input input) {
    // Change current direction if possible
    if (input == Input::UP && currentDirection != Vector2i(0, 1)) {
        currentDirection = Vector2i(0, -1);
    } else if (input == Input::DOWN && currentDirection != Vector2i(0, -1)) {
        currentDirection = Vector2i(0, 1);
    } else if (input == Input::LEFT && currentDirection != Vector2i(1, 0)) {
        currentDirection = Vector2i(-1, 0);
    } else if (input == Input::RIGHT && currentDirection != Vector2i(-1, 0)) {
        currentDirection = Vector2i(1, 0);
    }

    // Retreive the snake's head position
    Vector2i head = parts.front();

    // Compute the next head position
    Vector2i nextHead = head + currentDirection;

    // Check if snake reached a world edge
    if (nextHead.x < 0) {
        nextHead.x = worldWidth - 1;
    } else if (nextHead.x >= worldWidth) {
        nextHead.x = 0;
    } else if (nextHead.y < 0) {
        nextHead.y = worldHeight - 1;
    } else if (nextHead.y >= worldHeight) {
        nextHead.y = 0;
    }

    // Add the next head position to the body parts
    parts.push_front(nextHead);

    // If the snake did not just grow then we remove its tail
    if (justGrew) {
        justGrew = false;
    } else {
        parts.pop_back();
    }
}

void Snake::grow() {
    justGrew = true;
}
