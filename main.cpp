#include <iostream>
#include "GraphicalInterface/SDLGraphicalInterface.h"
#include "Game/Game.h"

int main() {
    try {
        std::unique_ptr<GraphicalInterface> gui = std::make_unique<SDLGraphicalInterface>(SDLGraphicalInterface());
        Game game(gui);
        game.start();
    } catch (SDLException &ex) {
        std::cout << "Error: " << ex.getMessage() << std::endl;
        return 1;
    }

    return 0;
}