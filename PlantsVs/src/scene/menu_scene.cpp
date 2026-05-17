#include "scene/menu_scene.h"

#include "resource_manager.h"

namespace PlantsVs {
void MenuScene::OnEnter() {
    // timer_.Init(1000.0f, false, []() {
    //     std::cout << "Timer triggered!" << std::endl;
    // });
    // camera_.Reset();
    // animation_peashooter_run_right_.Init(GetResourceManager().GetAtlas("atlas_peashooter_run_right"), 100, true);
    GetResourceManager().SoundPlay("bgm_menu", true);
}

void MenuScene::OnUpdate(float delta) {
    // timer_.OnUpdate(delta);
    // camera_.OnUpdate(delta);
    // animation_peashooter_run_right_.OnUpdate(delta);
}

void MenuScene::OnDraw() const {
    // const Vector2& pos_camera = camera_.GetPosition();
    // animation_peashooter_run_right_.OnDraw(static_cast<int>(100.-pos_camera.x), static_cast<int>(100.-pos_camera.y));
    putimage(0, 0, GetResourceManager().GetImage("img_menu_background"));
}

void MenuScene::OnEvent(const ExMessage& msg) {
    if(msg.message == WM_KEYUP) {
        GetResourceManager().SoundPlay("ui_confirm");
        if(change_scene_callback_) change_scene_callback_(SceneType::Selector);
    }
}

void MenuScene::OnExit() {
    // animation_peashooter_run_right_.Reset();
}
}