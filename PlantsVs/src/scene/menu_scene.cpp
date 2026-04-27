#include "scene/menu_scene.h"

#include <iostream>

#include "scene/scene_type.h"

namespace PlantsVs {
void MenuScene::OnEnter() {
    // std::cout << "进入主菜单" << std::endl;
    animation_peashooter_run_right.Init(GetResourceManager().GetAtlas("atlas_peashooter_run_right"), 75);
}

void MenuScene::OnUpdate(double delta) {
    // std::cout << "主菜单运行中……" << std::endl;
    animation_peashooter_run_right.OnUpdate(delta);
}

void MenuScene::OnDraw() const {
    // outtextxy(100, 100, _T("主菜单"));
    animation_peashooter_run_right.OnDraw(100, 100);
}

void MenuScene::OnEvent(const ExMessage& msg) {
    if(msg.message == WM_KEYDOWN) {
        if(observer_) observer_->Notify((int)SceneType::Selector);
    }
}

void MenuScene::OnExit() {
    std::cout << "退出主菜单" << std::endl;
}
}