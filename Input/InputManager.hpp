#ifndef SNAKE_INPUTMANAGER_HPP
#define SNAKE_INPUTMANAGER_HPP

#include "Input.hpp"

class InputManager {
public:
    virtual Input handleInputs() const = 0;

private:
    /**
     * Check if the given key is currently pressed or not
     * @param keyCode the key code
     * @return true if pressed, false otherwise
     */
    virtual bool isKeyDown(int keyCode) const = 0;
};

#endif //SNAKE_INPUTMANAGER_HPP
