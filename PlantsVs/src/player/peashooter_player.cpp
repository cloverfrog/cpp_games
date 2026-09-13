#include "player/peashooter_player.h"

#include "resource_manager.h"

namespace PlantsVs {

PeashooterPlayer::PeashooterPlayer() {
    animation_idle_left_.Init(GetResourceManager().GetAtlas("atlas_peashooter_idle_left"), 75);
    animation_idle_right_.Init(GetResourceManager().GetAtlas("atlas_peashooter_idle_right"), 75);
    animation_run_left_.Init(GetResourceManager().GetAtlas("atlas_peashooter_run_left"), 75);
    animation_run_right_.Init(GetResourceManager().GetAtlas("atlas_peashooter_run_right"), 75);

    current_animation_ = &animation_idle_right_;
}

void PeashooterPlayer::OnUpdate(float delta) {
    Player::OnUpdate(delta);
}

void PeashooterPlayer::OnDraw() const {
    Player::OnDraw();
}

void PeashooterPlayer::OnEvent(const Player::KeyBoard& msg) {
    Player::OnEvent(msg);
}

}