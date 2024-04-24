#ifndef SNAKE_GAME_HPP
#define SNAKE_GAME_HPP

#include <SDL2/SDL.h>
#include <memory>
#include <vector>
#include "GraphicalInterface/GraphicalInterface.hpp"
#include "GameObject/Snake.hpp"
#include "GameObject/Apple.hpp"
#include "GameObject/Obstacle.hpp"

class Game {
public:
    /**
     * Create a new game by giving the graphical interface that will be used
     * @param gui the graphical interface
     */
    explicit Game(std::unique_ptr<GraphicalInterface> &gui);

    /**
     * Start the game
     */
    void start();

    /**
     * Stop the game
     */
    void stop();

private:
    static const int WORLD_WIDTH = 40;
    static const int WORLD_HEIGHT = 20;

    int applesEaten;
    int steps;
    bool running;
    std::unique_ptr<GraphicalInterface> gui;
    std::unique_ptr<Snake> snake;
    std::unique_ptr<Apple> apple;
    std::vector<Obstacle> obstacles;

    void randomlySpawnApple();
};

#endif //SNAKE_GAME_HPP
