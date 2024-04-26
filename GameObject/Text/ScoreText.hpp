#ifndef SNAKE_SCORETEXT_HPP
#define SNAKE_SCORETEXT_HPP

#include <memory>
#include <utility>
#include <sstream>
#include "Text.hpp"

/**
 * A text that handles a prefix followed by an integer value.
 */
class ScoreText : public Text {
public:
    /**
     * Create a score text by giving its position, prefix and score.
     * @param position the position of the text
     * @param prefix the prefix
     * @param score the score
     */
    explicit ScoreText(const Vector2i &position, std::string prefix, int* score):
        Text(position), prefix(std::move(prefix)), score(score) {};

    std::string get() const override {
        std::ostringstream oss;
        oss << prefix << *score;
        return oss.str();
    }

private:
    std::string prefix;
    int* score;
};

#endif //SNAKE_SCORETEXT_HPP
