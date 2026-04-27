#include "scene/selector_scene.h"

#include <iostream>

#include "scene/scene_type.h"

namespace PlantsVs {
void SelectorScene::OnEnter() {
    std::cout << "进入选择界面" << std::endl;
}

void SelectorScene::OnUpdate(double delta) {
    std::cout << "选择界面运行中……" << std::endl;
}

void SelectorScene::OnDraw() const {
    outtextxy(100, 100, _T("选择界面"));
}

void SelectorScene::OnEvent(const ExMessage& msg) {
    if(msg.message == WM_KEYDOWN) {
        if(observer_) observer_->Notify((int)SceneType::Game);
    }
}

void SelectorScene::OnExit() {
    std::cout << "退出选择界面" << std::endl;
}
}