#ifndef SNAKE_VECTOR2I_H
#define SNAKE_VECTOR2I_H

#include <string>
#include <sstream>

using namespace std;

class Vector2i {
public:
    int x, y;

    explicit Vector2i(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Vector2i(const Vector2i &v) {
        x = v.x;
        y = v.y;
    }

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

    explicit operator string() const {
        ostringstream oss;
        oss << "(" << x << ", " << y << ")";
        return oss.str();
    }
};

#endif //SNAKE_VECTOR2I_H
