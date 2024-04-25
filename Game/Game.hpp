#ifndef SNAKE_GAME_HPP
#define SNAKE_GAME_HPP

#include <SDL2/SDL.h>
#include <memory>
#include <map>
#include "Input/InputManager.hpp"
#include "GraphicalInterface/GraphicalInterface.hpp"
#include "World.hpp"
#include "Input/Control/Control.hpp"

class Game {
public:
    static const int SQUARE_SIZE = 20;

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

    /**
     * Add a drawable object to the game
     * @param objectDrawer the drawable object
     */
    void addObject(ObjectDrawer *objectDrawer);

private:
    static const int WORLD_WIDTH = 40;
    static const int WORLD_HEIGHT = 20;

    int applesEaten;
    int steps;
    bool running;
    std::map<Input, Control*> inputs;
    std::unique_ptr<InputManager> inputManager;
    std::unique_ptr<GraphicalInterface> gui;
    std::shared_ptr<World> world;
};

#endif //SNAKE_GAME_HPP
