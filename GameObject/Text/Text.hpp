#ifndef SNAKE_TEXT_HPP
#define SNAKE_TEXT_HPP

#include <string>
#include "GameObject/GameObject.hpp"

/**
 * A text object that will be displayed on the screen.
 */
class Text : public GameObject {
public:
    explicit Text(const Vector2i &position): GameObject(position) {}

    virtual std::string get() const = 0;

    bool collision(const Vector2i &position) const override {
        return false;
    }

    inline explicit operator std::string() const {
        return get();
    }
};

#endif //SNAKE_TEXT_HPP
