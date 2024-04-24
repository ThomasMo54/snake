#ifndef SNAKE_SDLEXCEPTION_H
#define SNAKE_SDLEXCEPTION_H

#include <string>
#include <utility>

class SDLException : public std::exception {
    std::string message;
public:
    explicit SDLException(std::string message): message(std::move(message)) {}

    inline const std::string getMessage() const {
        return message;
    }
};

#endif //SNAKE_SDLEXCEPTION_H
