#include "scene/menu_scene.h"

#include <iostream>

namespace PlantsVs {
void MenuScene::OnEnter() {
    animation_peashooter_run_right_.Init(GetResourceManager().GetAtlas("atlas_peashooter_run_right"), 100, true);
    camera_.Reset();
}

void MenuScene::OnUpdate(double delta) {
    animation_peashooter_run_right_.OnUpdate(delta);
}

void MenuScene::OnDraw() const {
    const Vector2& pos_camera = camera_.GetPosition();
    animation_peashooter_run_right_.OnDraw(static_cast<int>(100.-pos_camera.x), static_cast<int>(100.-pos_camera.y));
}

void MenuScene::OnEvent(const ExMessage& msg) {
    if(msg.message == WM_KEYDOWN) {
        if(change_scene_callback_) change_scene_callback_(SceneType::Selector);
    }
}

void MenuScene::OnExit() {
    std::cout << "ÍË³öÖ÷²Ëµ¥" << std::endl;
    animation_peashooter_run_right_.Reset();
}
}