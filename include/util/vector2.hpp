// A strcut contains x and y.

#ifndef VECTOR2_H
#define VECTOR2_H

typedef struct Vector2 {
    int x;
    int y;

    bool IsZero() {
        return this->x == 0 && this->y == 0;
    }

    bool operator==(const Vector2& other) const {
        return this->x == other.x && this->y == other.y;
    }

    bool operator!=(const Vector2& other) const {
        return this->x != other.x || this->y != other.y;
    }

    bool operator<(const Vector2& other) const {
        return (this->x * 100 + this->y) < (other.x * 100 + other.y);
    }

    bool operator>(const Vector2& other) const {
        return (this->x * 100 + this->y) > (other.x * 100 + other.y);
    }
} Vector2;

#endif