#ifndef BULLET_H
#define BULLET_H

#include <graphics.h>

class Bullet {
public:
    Bullet() = default;
    ~Bullet() = default;

    void Draw() const;
private:
    const int RADIUS = 10;
private:
    POINT position;
};

#endif // BULLET_H