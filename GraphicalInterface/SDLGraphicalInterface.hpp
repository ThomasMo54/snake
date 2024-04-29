#ifndef SNAKE_SDLGRAPHICALINTERFACE_HPP
#define SNAKE_SDLGRAPHICALINTERFACE_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <list>
#include "GraphicalInterface.hpp"
#include "GameObject/Snake/Snake.hpp"
#include "GameObject/Apple.hpp"
#include "GameObject/Obstacle.hpp"
#include "GraphicalInterface/Drawer/SDLObjectDrawer.hpp"

class SDLGraphicalInterface : public GraphicalInterface {
public:
    SDLGraphicalInterface();

    void clear() const override;

    void destroy() override;

    void drawObjects() const override;

    void addObject(ObjectDrawer *objectDrawer) override;

    void clearObjects() override;

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    std::list<SDLObjectDrawer*> objects;
};

#endif //SNAKE_SDLGRAPHICALINTERFACE_HPP
