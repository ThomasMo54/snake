#include <iostream>
#include "GraphicalInterface/SDLGraphicalInterface.h"
#include "Game/Game.h"

using namespace std;

int main() {
    try {
        unique_ptr<GraphicalInterface> gui = make_unique<SDLGraphicalInterface>(SDLGraphicalInterface());
        Game game(gui);
        game.start();
    } catch (SDLException &ex) {
        cout << "Error: " << ex.getMessage() << endl;
        return 1;
    }

    return 0;
}