#include "LevelState.hpp"
#include "GameObject/Text/ScoreText.hpp"
#include "GraphicalInterface/Drawer/SDLTextDrawer.hpp"
#include "GraphicalInterface/Drawer/SDLSnakeDrawer.hpp"
#include "GraphicalInterface/Drawer/SDLAppleDrawer.hpp"
#include "GraphicalInterface/Drawer/SDLObstacleDrawer.hpp"
#include "MenuState.hpp"

void LevelState::enter(const std::shared_ptr<GraphicalInterface> &gui) {
    gui->clearObjects();

    // Create objects
    this->world = std::make_shared<World>(World(WORLD_WIDTH, WORLD_HEIGHT));
    this->snake = std::make_shared<Snake>(Snake(Vector2i(world->getWidth() / 2, world->getHeight() / 2), Snake::DEFAULT_SIZE + applesEaten));
    snake->setWorldSize(world->getWidth(), world->getHeight());
    this->obstacles = std::make_shared<Obstacles>(Obstacles());

    // Spawn obstacles randomly
    world->randomlySpawnObstacles(*snake, obstacles, level * 2 + 5);

    // Spawn apple randomly
    world->randomlySpawnApple(*snake, *obstacles, apple);

    // Create texts
    ScoreText applesEatenText(Vector2i(0, 0), "Pommes: ", &applesEaten);
    ScoreText stepsText(Vector2i(0, 20), "Pas: ", &steps);
    ScoreText scoreText(Vector2i(0, 40), "Score: ", &score);
    ScoreText energyText(Vector2i(650, 0), "Energie: ", snake->getEnergy());

    // Add objects to the GUI
    gui->addObject(new SDLTextDrawer(std::make_shared<ScoreText>(applesEatenText), "Font/OpenSans.ttf", 20, Color(255, 255, 255, 255)));
    gui->addObject(new SDLTextDrawer(std::make_shared<ScoreText>(stepsText), "Font/OpenSans.ttf", 20, Color(255, 255, 255, 255)));
    gui->addObject(new SDLTextDrawer(std::make_shared<ScoreText>(scoreText), "Font/OpenSans.ttf", 20, Color(255, 255, 255, 255)));
    gui->addObject(new SDLTextDrawer(std::make_shared<ScoreText>(energyText), "Font/OpenSans.ttf", 20, Color(255, 255, 255, 255)));
    gui->addObject(new SDLSnakeDrawer(snake));
    gui->addObject(new SDLAppleDrawer(apple));
    for (const auto &obstacle : obstacles->getObstacles()) {
        gui->addObject(new SDLObstacleDrawer(std::make_shared<Obstacle>(obstacle)));
    }
}

void LevelState::update() {

}

std::shared_ptr<State> LevelState::handleInput(Input input) {
    // Make snake move
    snake->move(input);

    // Check collisions
    if (snake->collision(snake->getHead()) || obstacles->collision(snake->getHead())) {
        return std::make_shared<MenuState>(MenuState());
    }

    // Check apple collision
    if (apple->collision(snake->getHead())) {
        snake->grow();
        world->randomlySpawnApple(*snake, *obstacles, apple);
        applesEaten++;
        if (applesEaten % APPLES_TO_PASS_LEVEL == 0) {
            return std::make_shared<LevelState>(LevelState(level + 1, steps + 1));
        }
    }

    // Check snake energy
    if (!snake->hasEnergyLeft()) {
        return std::make_shared<MenuState>(MenuState());
    }

    steps++;
    score = steps + 50 * applesEaten;
    return nullptr;
}