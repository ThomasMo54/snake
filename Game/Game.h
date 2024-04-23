#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <memory>
#include <unistd.h>
#include <set>
#include <vector>
#include <random>
#include "../GraphicalInterface/GraphicalInterface.h"
#include "../Math/Vector2i.h"
#include "../GameObject/Snake.h"
#include "../GameObject/Apple.h"
#include "../GameObject/Obstacle.h"

using namespace std;

class Game {
    static const int DELAY_BETWEEN_FRAMES = 250000; // In microseconds (= 0.25s)
    static const int WORLD_WIDTH = 40;
    static const int WORLD_HEIGHT = 20;

    int applesEaten;
    int steps;
    bool running;
    unique_ptr<GraphicalInterface> gui;
    unique_ptr<Snake> snake;
    unique_ptr<Apple> apple;
    vector<Obstacle> obstacles;

    Apple randomlySpawnApple() const {
        // Initialize a vector containing all the free positions
        vector<Vector2i> freePositions;

        // Iterate over all the world's positions to find every free positions
        for (int y = 0; y < WORLD_HEIGHT; y++) {
            for (int x = 0; x < WORLD_WIDTH; x++) {
                Vector2i position = Vector2i(x, y);

                // Check if the current position is an obstacle
                for (const auto & obstacle : obstacles) {
                    if (obstacle.getPosition() == position) {
                        continue;
                    }
                }

                // Check if the current position is a snake's body part
                for (const auto & part : snake->getParts()) {
                    if (part == position) {
                        continue;
                    }
                }

                // If the current position is free then add it to the free positions vector
                freePositions.push_back(position);
            }
        }

        // Select a random free position
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(0,freePositions.size() - 1);
        unsigned long positionIndex = dist6(rng);
        Vector2i position = freePositions[positionIndex];

        return Apple(position);
    }

public:
    explicit Game(unique_ptr<GraphicalInterface> &gui) {
        applesEaten = 0;
        steps = 0;
        running = false;
        this->gui = std::move(gui);

        // Add some obstacles
        for (int i = 10; i < 30; i++) {
            obstacles.emplace_back(Vector2i(i, 5));
        }

        // Spawn snake in the center of the world
        this->snake = make_unique<Snake>(Snake(Vector2i(WORLD_WIDTH / 2, WORLD_HEIGHT / 2)));
        this->apple = make_unique<Apple>(randomlySpawnApple());
    }

    void start() {
        running = true;

        // Start the game loop
        while (running) {
            // Clear screen
            gui->clear();

            // Update screen
            gui->update();

            // Sleep between iterations of the loop to make the game run slower
            usleep(DELAY_BETWEEN_FRAMES);
        }
    }

    /**
     * Stop the game
     */
    void stop() {
        running = false;
        gui->destroy();
    }
};

#endif //SNAKE_GAME_H
