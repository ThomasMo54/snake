#ifndef SNAKE_SDLGRAPHICALINTERFACE_HPP
#define SNAKE_SDLGRAPHICALINTERFACE_HPP

#include <SDL2/SDL.h>
#include "GraphicalInterface.hpp"
#include "GameObject/Snake.hpp"
#include "GameObject/Apple.hpp"
#include "GameObject/Obstacle.hpp"

class SDLGraphicalInterface : public GraphicalInterface {
public:
    SDLGraphicalInterface();

    void clear() const override;

    void destroy() override;

    void update() override;

    void drawSnake(const Snake &snake) const override;

    void drawApple(const Apple &apple) const override;

    void drawObstacle(const Obstacle &obstacle) const override;

private:
    static const int SQUARE_SIZE = 20;

    SDL_Window *window;
    SDL_Renderer *renderer;

    void drawSquare(int x, int y, int size, int r, int g, int b, bool fill) const;
};

#endif //SNAKE_SDLGRAPHICALINTERFACE_HPP
