#include "Game.hpp"
#include "Input/SDLInputManager.hpp"
#include "Game/State/MenuState.hpp"

Game::Game(std::shared_ptr<GraphicalInterface> &gui) {
    running = false;

    inputManager = std::make_unique<SDLInputManager>();
    this->gui = std::move(gui);

    setState(std::make_shared<MenuState>(MenuState()));
}

void Game::start() {
    running = true;

    // Start the game loop
    while (running) {
        // Handle inputs
        Input input = inputManager->handleInputs();
        std::shared_ptr<State> newState = state->handleInput(input);

        state->update();

        if (newState != nullptr) {
            setState(newState);
        }

        // Update screen
        gui->drawObjects();
    }
}

void Game::stop() {
    running = false;
    gui->destroy();
}

void Game::setState(std::shared_ptr<State> state) {
    this->state.reset();
    this->state = state;
    state->enter(gui);
}
