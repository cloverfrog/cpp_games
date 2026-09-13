#include "player/sunflower_player.h"

#include "resource_manager.h"

namespace PlantsVs {

SunflowerPlayer::SunflowerPlayer() {
    animation_idle_left_.Init(GetResourceManager().GetAtlas("atlas_sunflower_idle_left"), 75);
    animation_idle_right_.Init(GetResourceManager().GetAtlas("atlas_sunflower_idle_right"), 75);
    animation_run_left_.Init(GetResourceManager().GetAtlas("atlas_sunflower_run_left"), 75);
    animation_run_right_.Init(GetResourceManager().GetAtlas("atlas_sunflower_run_right"), 75);

    current_animation_ = &animation_idle_right_;
}

void SunflowerPlayer::OnUpdate(float delta) {
    Player::OnUpdate(delta);
}

void SunflowerPlayer::OnDraw() const {
    Player::OnDraw();
}

void SunflowerPlayer::OnEvent(const Player::KeyBoard& msg) {
    Player::OnEvent(msg);
}

}