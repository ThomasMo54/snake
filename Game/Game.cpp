#include "Game.hpp"
#include "Input/SDLInputManager.hpp"
#include "GraphicalInterface/Drawer/SDLAppleDrawer.hpp"
#include "Input/Control/UpControl.h"
#include "Input/Control/DownControl.h"
#include "Input/Control/LeftControl.h"
#include "Input/Control/RightControl.h"

Game::Game(std::unique_ptr<GraphicalInterface> &gui) {
    applesEaten = 0;
    steps = 0;
    running = false;

    inputs.insert({Input::UP, new UpControl()});
    inputs.insert({Input::DOWN, new DownControl()});
    inputs.insert({Input::LEFT, new LeftControl()});
    inputs.insert({Input::RIGHT, new RightControl()});

    inputManager = std::make_unique<SDLInputManager>();
    this->gui = std::move(gui);
    this->world = std::make_shared<World>(World(this, WORLD_WIDTH, WORLD_HEIGHT))
}

void Game::start() {
    running = true;

    // Start the game loop
    while (running) {
        // Handle inputs
        Input input = inputManager->handleInputs();
        if (input != Input::VOID) {
            inputs[input]->execute(world->getSnake());
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

void Game::addObject(ObjectDrawer *objectDrawer) {
    gui->addObject(objectDrawer);
}
