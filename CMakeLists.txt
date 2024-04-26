cmake_minimum_required(VERSION 3.28)
project(snake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})

add_executable(snake main.cpp
        Math/Vector2i.hpp
        GameObject/GameObject.hpp
        GameObject/Snake.hpp
        GameObject/Apple.hpp
        GameObject/Obstacle.hpp
        GraphicalInterface/GraphicalInterface.hpp
        Game/Game.hpp
        GraphicalInterface/SDLGraphicalInterface.hpp
        Exception/SDLException.hpp
        Game/Game.cpp
        GraphicalInterface/SDLGraphicalInterface.cpp
        GameObject/Snake.cpp
        Input/InputManager.hpp
        Input/SDLInputManager.hpp
        GraphicalInterface/Drawer/ObjectDrawer.hpp
        GraphicalInterface/Drawer/SDLSnakeDrawer.hpp
        GraphicalInterface/Drawer/SDLSnakeDrawer.cpp
        GraphicalInterface/Drawer/SDLObjectDrawer.hpp
        GraphicalInterface/Drawer/SDLObjectDrawer.cpp
        GraphicalInterface/Drawer/SDLAppleDrawer.cpp
        GraphicalInterface/Drawer/SDLAppleDrawer.hpp
        GraphicalInterface/Drawer/SDLObstacleDrawer.cpp
        GraphicalInterface/Drawer/SDLObstacleDrawer.hpp
        Game/World.hpp
        Game/World.cpp
        GameObject/Obstacles.hpp
        Input/Input.hpp
        GraphicalInterface/Drawer/SDLTextDrawer.hpp
        GameObject/Text/Text.hpp
        GameObject/Text/ScoreText.hpp
        GraphicalInterface/Drawer/SDLTextDrawer.cpp
        GraphicalInterface/Color.hpp
)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES})
