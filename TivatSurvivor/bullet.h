#ifndef BULLET_H
#define BULLET_H

#include "utils.h"

#include <graphics.h>

class Bullet {
public:
    Bullet() = default;
    ~Bullet() = default;

    void Draw() const;

    Position GetPosition() const { return position; }
    void SetPosition(Position pos) { position = pos; }
private:
    static inline constexpr int RADIUS = 10;
private:
    Position position;
};

#endif // BULLET_H