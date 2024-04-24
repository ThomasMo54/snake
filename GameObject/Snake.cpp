#include "Snake.hpp"

void Snake::initialize() {
    // The position of the tail
    Vector2i tailPosition = position - direction * DEFAULT_SIZE;

    // Add all snake's body parts starting from its tail
    parts.push_front(tailPosition);
    for (int i = 0; i < DEFAULT_SIZE - 1; i++) {
        parts.push_front(parts.front() + direction);
    }
}

void Snake::move() {
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

void Snake::grow() {
    justGrew = true;
}