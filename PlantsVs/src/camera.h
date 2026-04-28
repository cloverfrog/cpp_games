#ifndef CAMERA_H
#define CAMERA_H

#include "core/types.h"

namespace PlantsVs {
class Camera {
public:
    Camera() = default;
    ~Camera() = default;

    void OnUpdate(float delta) {
        const Vector2 speed = { -0.35f, 0.0f };
        position_ += speed * static_cast<float>(delta);
    }

    const Vector2& GetPosition() const { return position_; }
    void Reset() { position_ = Vector2(0, 0); }
private:
    Vector2 position_;
};
}

#endif // CAMERA_H