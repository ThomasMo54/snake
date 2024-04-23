#ifndef SNAKE_SDLEXCEPTION_H
#define SNAKE_SDLEXCEPTION_H

#include <string>
#include <utility>

using namespace std;

class SDLException : public exception {
    string message;
public:
    explicit SDLException(string message): message(std::move(message)) {}

    inline const string getMessage() const {
        return message;
    }
};

#endif //SNAKE_SDLEXCEPTION_H
