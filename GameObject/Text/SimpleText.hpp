#ifndef SNAKE_SIMPLETEXT_HPP
#define SNAKE_SIMPLETEXT_HPP

#include "Text.hpp"

class SimpleText : public Text {
public:
    explicit SimpleText(const Vector2i &position, std::string text): Text(position), text(std::move(text)) {};

    std::string get() const override {
        return text;
    }

private:
    std::string text;
};

#endif //SNAKE_SIMPLETEXT_HPP
