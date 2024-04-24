#include <random>
#include <iostream>
#include "Game.hpp"
#include "Input/SDLInputManager.hpp"
#include "Math/Vector2i.hpp"
#include "GraphicalInterface/Drawer/SDLAppleDrawer.hpp"
#include "GraphicalInterface/Drawer/SDLSnakeDrawer.hpp"
#include "GraphicalInterface/Drawer/SDLObstacleDrawer.hpp"

std::random_device dev;
std::mt19937 rng(dev());

Game::Game(std::unique_ptr<GraphicalInterface> &gui) {
    applesEaten = 0;
    steps = 0;
    running = false;
    inputManager = std::make_unique<SDLInputManager>();
    this->gui = std::move(gui);

    // Add some obstacles
    for (int i = 10; i < 30; i++) {
        obstacles.emplace_back(Vector2i(i, 5));
    }

    // Spawn snake in the center of the world
    this->snake = std::make_unique<Snake>(Snake(Vector2i(WORLD_WIDTH / 2, WORLD_HEIGHT / 2)));

    // Randomly spawn an apple
    randomlySpawnApple();

    this->gui->addObject(new SDLAppleDrawer(apple));
    for (const auto obstacle : obstacles) {
        this->gui->addObject(new SDLObstacleDrawer(std::make_shared<Obstacle>(obstacle)));
    }
    this->gui->addObject(new SDLSnakeDrawer(snake));
}

void Game::start() {
    running = true;

    // Start the game loop
    while (running) {
        // Handle movement
        if (inputManager->isKeyDown(SDL_SCANCODE_LEFT) && snake->getDirection() != Vector2i(1, 0)) {
            snake->setDirection(Vector2i(-1, 0));
        } else if (inputManager->isKeyDown(SDL_SCANCODE_RIGHT) && snake->getDirection() != Vector2i(-1, 0)) {
            snake->setDirection(Vector2i(1, 0));
        } else if (inputManager->isKeyDown(SDL_SCANCODE_UP) && snake->getDirection() != Vector2i(0, 1)) {
            snake->setDirection(Vector2i(0, -1));
        } else if (inputManager->isKeyDown(SDL_SCANCODE_DOWN) && snake->getDirection() != Vector2i(0, -1)) {
            snake->setDirection(Vector2i(0, 1));
        }
        snake->move();

        // Spawn snake at the opposite of the world if it hits one edge
        Vector2i head = snake->getHead();
        if (head.x >= WORLD_WIDTH) {
            snake->setHead(Vector2i(0, head.y));
        } else if (head.x < 0) {
            snake->setHead(Vector2i(WORLD_WIDTH - 1, head.y));
        } else if (head.y >= WORLD_HEIGHT) {
            snake->setHead(Vector2i(head.x, 0));
        } else if (head.y < 0){
            snake->setHead(Vector2i(head.x, WORLD_HEIGHT - 1));
        }

        // Check if the snake is eating an apple
        if (snake->getHead() == apple->getPosition()) {
            applesEaten++;
            snake->grow();
            randomlySpawnApple();
        }

        // Check if snake is hitting an obstacle
        for (const auto &obstacle : obstacles) {
            if (snake->getHead() == obstacle.getPosition()) {
                stop();
                return;
            }
        }

        // Check if snake is hitting himself
        for (int i = 1; i < snake->getParts().size(); i++) {
            if (snake->getHead() == snake->getParts()[i]) {
                stop();
                return;
            }
        }

        steps++;

        // Update screen
        gui->drawObjects();
    }
}

void Game::stop() {
    running = false;
    gui->destroy();
}

void Game::randomlySpawnApple() {
    // Initialize a vector containing all the free positions
    std::vector<Vector2i> freePositions;

    // Iterate over all the world's positions to find every free positions
    for (int y = 0; y < WORLD_HEIGHT; y++) {
        for (int x = 0; x < WORLD_WIDTH; x++) {
            Vector2i position = Vector2i(x, y);
            bool free = true;

            // Check if the current position is an obstacle
            for (const auto & obstacle : obstacles) {
                if (obstacle.getPosition() == position) {
                    free = false;
                    break;
                }
            }
            if (!free) {
                continue;
            }

            // Check if the current position is a snake's body part
            for (const auto & part : snake->getParts()) {
                if (part == position) {
                    free = false;
                    break;
                }
            }
            if (!free) {
                continue;
            }

            // If the current position is free then add it to the free positions vector
            freePositions.push_back(position);
        }
    }

    // Select a random free position
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, freePositions.size() - 1);
    unsigned long positionIndex = dist6(rng);
    Vector2i position = freePositions[positionIndex];

    if (apple != nullptr) {
        *apple = Apple(position);
    } else {
        apple = std::make_shared<Apple>(Apple(position));
    }
}