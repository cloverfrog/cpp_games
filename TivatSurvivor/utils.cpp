#include "utils.h"

Position Position::operator+(const Vec2& v) const { return {x + v.x, y + v.y}; }
Position Position::operator+=(const Vec2& v) { x += v.x; y += v.y; return *this; }
Position Position::operator-(const Vec2& v) const { return {x - v.x, y - v.y}; }
Position Position::operator-=(const Vec2& v) { x -= v.x; y -= v.y; return *this; }
void Position::Restrict(const RectArea& r) {
    if(x < r.left) x = r.left;
    if(x > r.right) x = r.right;
    if(y < r.top) y = r.top;
    if(y > r.bottom) y = r.bottom;
}

bool RectArea::IsCollision(const Position& p) const {
    return p.x >= left && p.x <= right && p.y >= top && p.y <= bottom;
}
bool RectArea::IsCollision(const RectArea& r) const {
    return ((left - r.right)*(right - r.left) < 0) && ((top - r.bottom)*(bottom - r.top) < 0);
}