#ifndef SNAKE_SDLOBSTACLEDRAWER_HPP
#define SNAKE_SDLOBSTACLEDRAWER_HPP

#include <SDL2/SDL.h>
#include <memory>
#include <utility>
#include "SDLObjectDrawer.hpp"
#include "GameObject/Obstacle.hpp"

class SDLObstacleDrawer : public SDLObjectDrawer {
public:
    explicit SDLObstacleDrawer(const std::shared_ptr<Obstacle>  &obstacle): obstacle(obstacle) {}

    void draw() const override;

private:
    std::shared_ptr<Obstacle> obstacle;
};

#endif //SNAKE_SDLOBSTACLEDRAWER_HPP
