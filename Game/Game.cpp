#include "Game.hpp"
#include "Input/SDLInputManager.hpp"
#include "GraphicalInterface/Drawer/SDLAppleDrawer.hpp"
#include "GraphicalInterface/Drawer/SDLObstacleDrawer.hpp"
#include "GraphicalInterface/Drawer/SDLSnakeDrawer.hpp"
#include "GraphicalInterface/Drawer/SDLTextDrawer.hpp"
#include "GameObject/Text/ScoreText.hpp"

Game::Game(std::unique_ptr<GraphicalInterface> &gui) {
    applesEaten = 0;
    steps = 0;
    running = false;

    inputManager = std::make_unique<SDLInputManager>();
    this->gui = std::move(gui);

    // Create objects
    this->world = std::make_shared<World>(World(WORLD_WIDTH, WORLD_HEIGHT));
    this->snake = std::make_shared<Snake>(Snake(Vector2i(world->getWidth() / 2, world->getHeight() / 2)));
    this->obstacles = std::make_shared<Obstacles>(Obstacles());
    // Add some obstacles
    for (int i = 10; i < 30; i++) {
        obstacles->addObstacle(Obstacle(Vector2i(i, 5)));
    }

    // Spawn apple randomly
    world->randomlySpawnApple(*snake, *obstacles, apple);

    // Create texts
    ScoreText applesEatenText(Vector2i(0, 0), "Pommes: ", &applesEaten);
    ScoreText stepsText(Vector2i(0, 20), "Pas: ", &steps);
    ScoreText scoreText(Vector2i(0, 40), "Score: ", &score);
    ScoreText energyText(Vector2i(650, 0), "Energie: ", snake->getEnergy());

    // Add objects to the GUI
    this->gui->addObject(new SDLTextDrawer(std::make_shared<ScoreText>(applesEatenText), "Font/OpenSans.ttf", 20, Color(255, 255, 255, 255)));
    this->gui->addObject(new SDLTextDrawer(std::make_shared<ScoreText>(stepsText), "Font/OpenSans.ttf", 20, Color(255, 255, 255, 255)));
    this->gui->addObject(new SDLTextDrawer(std::make_shared<ScoreText>(scoreText), "Font/OpenSans.ttf", 20, Color(255, 255, 255, 255)));
    this->gui->addObject(new SDLTextDrawer(std::make_shared<ScoreText>(energyText), "Font/OpenSans.ttf", 20, Color(255, 255, 255, 255)));
    this->gui->addObject(new SDLSnakeDrawer(snake));
    this->gui->addObject(new SDLAppleDrawer(apple));
    for (const auto &obstacle : obstacles->getObstacles()) {
        this->gui->addObject(new SDLObstacleDrawer(std::make_shared<Obstacle>(obstacle)));
    }
}

void Game::start() {
    running = true;
    snake->setWorldSize(world->getWidth(), world->getHeight());

    // Start the game loop
    while (running) {
        // Handle inputs
        Input input = inputManager->handleInputs();

        // Make snake move
        snake->move(input);

        // Check collisions
        if (snake->collision(snake->getHead()) || obstacles->collision(snake->getHead())) {
            stop();
            gui->destroy();
            return;
        }

        // Check apple collision
        if (apple->collision(snake->getHead())) {
            snake->grow();
            world->randomlySpawnApple(*snake, *obstacles, apple);
            applesEaten++;
        }

        // Check snake energy
        if (!snake->hasEnergyLeft()) {
            stop();
            gui->destroy();
            return;
        }

        steps++;
        score = steps + 50 * applesEaten;

        // Update screen
        gui->drawObjects();
    }
}

void Game::stop() {
    running = false;
    gui->destroy();
}
