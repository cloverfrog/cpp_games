#ifndef CAMERA_H
#define CAMERA_H

#include <cstdlib>

#include "base/singleton.h"
#include "core/types.h"
#include "core/timer.h"

namespace PlantsVs {
class Camera : public Singleton<Camera> {
    friend class Singleton<Camera>;
public:
    void OnUpdate(float delta) {
        timer_shake_.OnUpdate(delta);
        if (is_shaking) {
            position_.x = static_cast<float>(rand() % 100 - 50) / 50.0f * shake_strength;
            position_.y = static_cast<float>(rand() % 100 - 50) / 50.0f * shake_strength;
        }
    }

    void Shake(float strength, float duration) {
        is_shaking = true;
        shake_strength = strength;
        timer_shake_.SetWaitTime(duration);
        timer_shake_.Restart();
    }

    const Vector2& GetPosition() const { return position_; }
    void Reset() { position_ = Vector2(0, 0); is_shaking = false; }
private:
    Camera() {
        timer_shake_.Init(0.0f, false, [&]() { Reset(); });
    }
    ~Camera() = default;
private:
    Vector2 position_;

    Timer timer_shake_; //摄像机抖动计时器
    bool is_shaking = false;    //摄像机是否抖动
    float shake_strength = 0.0f;    //抖动强度
};

inline Camera& GetCamera() { return Camera::GetInstance(); }
}

#endif // CAMERA_H