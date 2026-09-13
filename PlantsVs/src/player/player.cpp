#include "player/player.h"

namespace PlantsVs {

void Player::OnUpdate(float delta) {
    int direction = is_right_key_down_ - is_left_key_down_;
    if(direction != 0) {
        is_facing_right_ = direction > 0;
        current_animation_ = is_facing_right_ ? &animation_run_right_ : &animation_run_left_;
    }
    else {
        current_animation_ = is_facing_right_ ? &animation_idle_right_ : &animation_idle_left_;
    }

    current_animation_->OnUpdate(delta);
}

void Player::OnDraw() const {
    if(current_animation_) {
        current_animation_->OnDraw(static_cast<int>(position_.x), static_cast<int>(position_.y));
    }
}

void Player::OnEvent(const KeyBoard& key) {
    switch(key) {
        case KeyBoard::Left_Down:
            is_left_key_down_ = true;
            break;
        case KeyBoard::Left_Up:
            is_left_key_down_ = false;
            break;
        case KeyBoard::Right_Down:
            is_right_key_down_ = true;
            break;
        case KeyBoard::Right_Up:
            is_right_key_down_ = false;
            break;
    }
}

}