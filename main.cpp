#include <iostream>
#include "Exception/SDLException.hpp"
#include "GraphicalInterface/SDLGraphicalInterface.hpp"
#include "Game/Game.hpp"

int main() {
    try {
        std::unique_ptr<GraphicalInterface> gui;
        gui = std::make_unique<SDLGraphicalInterface>(SDLGraphicalInterface());
        Game game(gui);
        game.start();
    } catch (SDLException &ex) {
        std::cout << "Error: " << ex.getMessage() << std::endl;
        return 1;
    }

    return 0;
}