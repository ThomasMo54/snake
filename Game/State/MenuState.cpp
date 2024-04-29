#include "MenuState.hpp"
#include "GraphicalInterface/Drawer/SDLTextDrawer.hpp"
#include "GameObject/Text/SimpleText.hpp"
#include "LevelState.hpp"

void MenuState::enter(const std::shared_ptr<GraphicalInterface> &gui) {
    gui->clearObjects();
    std::shared_ptr<SimpleText> title = std::make_shared<SimpleText>(SimpleText(Vector2i(100, 100), "SNAKE"));
    std::shared_ptr<SimpleText> pressKeyText = std::make_shared<SimpleText>(SimpleText(Vector2i(100, 200), "Appuyez sur ESPACE pour commencer"));
    gui->addObject(new SDLTextDrawer(title, "Font/OpenSans.ttf", 32, Color(255, 255, 255, 255)));
    gui->addObject(new SDLTextDrawer(pressKeyText, "Font/OpenSans.ttf", 24, Color(255, 255, 255, 255)));
}

void MenuState::update() {

}

std::shared_ptr<State> MenuState::handleInput(Input input) {
    if (input == Input::SPACE) {
        return std::make_shared<LevelState>(LevelState(1, 0));
    }
    return nullptr;
}