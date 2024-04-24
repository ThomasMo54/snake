#ifndef SNAKE_VECTOR2I_H
#define SNAKE_VECTOR2I_H

#include <string>
#include <sstream>

/**
 * A minimalistic 2D vector class with integer components.
 */
class Vector2i {
public:
    int x, y;

    /**
     * Construct a vector given its components.
     * @param x the x component
     * @param y the y component
     */
    explicit Vector2i(int x, int y) {
        this->x = x;
        this->y = y;
    }

    /**
     * Construct a new vector by copying the given one.
     * @param v the vector to copy
     */
    Vector2i(const Vector2i &v) {
        x = v.x;
        y = v.y;
    }

    /**
     * Construct a default vector with its components set to 0.
     */
    explicit Vector2i() {
        x = 0;
        y = 0;
    }

    Vector2i operator + (const Vector2i &v) const {
        return Vector2i(x + v.x, y + v.y);
    }

    const Vector2i& operator += (const Vector2i &v) {
        x += v.x;
        y += v.y;
        return *this;
    }

    Vector2i operator - (const Vector2i &v) const {
        return Vector2i(x - v.x, y - v.y);
    }

    const Vector2i& operator -= (const Vector2i &v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    Vector2i operator * (int i) const {
        return Vector2i(x * i, y * i);
    }

    const Vector2i& operator *= (int i) {
        x *= i;
        y *= i;
        return *this;
    }

    Vector2i operator / (int i) const {
        return Vector2i(x / i, y / i);
    }

    const Vector2i& operator /= (int i) {
        x /= i;
        y /= i;
        return *this;
    }

    bool operator == (const Vector2i &v) const {
        return x == v.x && y == v.y;
    }

    explicit operator std::string() const {
        std::ostringstream oss;
        oss << "(" << x << ", " << y << ")";
        return oss.str();
    }
};

#endif //SNAKE_VECTOR2I_H
