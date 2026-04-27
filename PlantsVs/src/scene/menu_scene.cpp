#include "scene/menu_scene.h"

#include <iostream>

namespace PlantsVs {
void MenuScene::OnEnter() {
    // std::cout << "进入主菜单" << std::endl;
    animation_peashooter_run_right_.Init(GetResourceManager().GetAtlas("atlas_peashooter_run_right"), 300, false, 
        [this](){ if(change_scene_callback_) change_scene_callback_(SceneType::Selector); });
}

void MenuScene::OnUpdate(double delta) {
    // std::cout << "主菜单运行中……" << std::endl;
    animation_peashooter_run_right_.OnUpdate(delta);
}

void MenuScene::OnDraw() const {
    // outtextxy(100, 100, _T("主菜单"));
    animation_peashooter_run_right_.OnDraw(100, 100);
}

void MenuScene::OnEvent(const ExMessage& msg) {
    if(msg.message == WM_KEYDOWN) {
        if(change_scene_callback_) change_scene_callback_(SceneType::Selector);
    }
}

void MenuScene::OnExit() {
    std::cout << "退出主菜单" << std::endl;
    animation_peashooter_run_right_.Reset();
}
}