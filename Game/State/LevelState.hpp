#ifndef SNAKE_LEVELSTATE_HPP
#define SNAKE_LEVELSTATE_HPP

#include "State.hpp"
#include "GameObject/Obstacles.hpp"
#include "Game/World.hpp"

class LevelState : public State {
public:
    explicit LevelState(int level, int steps):
        State(), applesEaten((level - 1) * APPLES_TO_PASS_LEVEL), level(level), steps(steps), score(steps + 50 * applesEaten) {}

    void enter(const std::shared_ptr<GraphicalInterface> &gui) override;

    void update() override;

    std::shared_ptr<State> handleInput(Input input) override;

private:
    static const int WORLD_WIDTH = 40;
    static const int WORLD_HEIGHT = 20;
    static const int APPLES_TO_PASS_LEVEL = 3;

    int applesEaten;
    int steps;
    int score;
    int level;
    std::shared_ptr<World> world;
    std::shared_ptr<Snake> snake;
    std::shared_ptr<Apple> apple;
    std::shared_ptr<Obstacles> obstacles;
};

#endif //SNAKE_LEVELSTATE_HPP
