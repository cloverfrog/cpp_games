#ifndef PLATFORM_H
#define PLATFORM_H

#include "graphics.h"

#include "core/types.h"

namespace PlantsVs {
class Platform {
public:
    struct CollisionShape {
        float y; // 平台的y坐标
        float left, right; // 平台的左右边界
    };
public:
    Platform(const Point2D& position) : position_(position) {};
    ~Platform() = default;

    void onDraw() const;
    CollisionShape GetCollisionShape() const { return shape_; }
protected:
    CollisionShape shape_;
    const IMAGE* img_platform_ = nullptr;
    Point2D position_;
};

class PlatformLarge : public Platform {
public:
    PlatformLarge(const Point2D& position);
    ~PlatformLarge() = default;
};

class PlatformSmall : public Platform {
public:
    PlatformSmall(const Point2D& position);
    ~PlatformSmall() = default;
};
}

#endif // PLATFORM_H