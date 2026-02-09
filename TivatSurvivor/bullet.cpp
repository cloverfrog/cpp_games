#include "bullet.h"

void Bullet::Draw() const {
    setlinecolor(RGB(255, 155, 50));
    setfillcolor(RGB(255, 75, 10));
    fillcircle(position.x, position.y, RADIUS);
}