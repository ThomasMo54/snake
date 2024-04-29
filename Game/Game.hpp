#ifndef SNAKE_GAME_HPP
#define SNAKE_GAME_HPP

#include <SDL2/SDL.h>
#include <memory>
#include <map>
#include "Input/InputManager.hpp"
#include "GraphicalInterface/GraphicalInterface.hpp"
#include "World.hpp"
#include "Game/State/State.hpp"

class Game {
public:
    static const int SQUARE_SIZE = 20;

    /**
     * Create a new game by giving the graphical interface that will be used
     * @param gui the graphical interface
     */
    explicit Game(std::shared_ptr<GraphicalInterface> &gui);

    /**
     * Start the game
     */
    void start();

    /**
     * Stop the game
     */
    void stop();

private:
    bool running;
    std::unique_ptr<InputManager> inputManager;
    std::shared_ptr<GraphicalInterface> gui;
    std::shared_ptr<State> state;

    void setState(std::shared_ptr<State> state);
};

#endif //SNAKE_GAME_HPP
