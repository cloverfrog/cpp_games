#ifndef PLAYER_H
#define PLAYER_H

#include <graphics.h> 

#include "core/types.h"
#include "animation.h"

namespace PlantsVs {

class Player {
public:
    enum class KeyBoard {
        Left_Down,
        Left_Up,
        Right_Down, 
        Right_Up
    };
public:
    Player() = default;
    virtual ~Player() = default;

    virtual void OnUpdate(float delta);
    virtual void OnDraw() const;
    virtual void OnEvent(const KeyBoard& key);

    void SetPosition(const Vector2& pos) { position_ = pos; }
protected:
    Vector2 position_;

    Animation animation_idle_left_;
    Animation animation_idle_right_;
    Animation animation_run_left_;
    Animation animation_run_right_;

    Animation* current_animation_ = nullptr;

    int is_left_key_down_ = 0;
    int is_right_key_down_ = 0;

    bool is_facing_right_ = true;
};
}

#endif // PLAYER_H