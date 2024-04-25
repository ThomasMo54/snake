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

void Snake::move(const Vector2i &direction) {
    // Change current direction
    if (direction != currentDirection * -1) {
        currentDirection = direction;
    }

    // Retreive the snake's head position
    Vector2i head = parts.front();

    // Compute the next head position
    Vector2i nextHead = head + direction;

    // Check if it collides an obstacle
    if (!world->isFreePosition(nextHead)) {
        exit(0);
    }

    // Check if snake reached a world edge
    if (nextHead.x < 0) {
        nextHead.x = world->getWidth() - 1;
    } else if (nextHead.x >= world->getWidth()) {
        nextHead.x = 0;
    } else if (nextHead.y < 0) {
        nextHead.y = world->getHeight() - 1;
    } else if (nextHead.y >= world->getHeight()) {
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

    // If snake is now on an apple then make it grow
    if (world->isApple(nextHead)) {
        grow();
        world->randomlySpawnApple();
    }
}

void Snake::grow() {
    justGrew = true;
}
