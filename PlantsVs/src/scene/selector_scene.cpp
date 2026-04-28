#include "scene/selector_scene.h"

#include <iostream>

namespace PlantsVs {
void SelectorScene::OnEnter() {
    std::cout << "进入选择界面" << std::endl;
}

void SelectorScene::OnUpdate(float delta) {
    std::cout << "选择界面运行中……" << delta << std::endl;
}

void SelectorScene::OnDraw() const {
    outtextxy(100, 100, _T("选择界面"));
}

void SelectorScene::OnEvent(const ExMessage& msg) {
    if(msg.message == WM_KEYDOWN) {
        if(change_scene_callback_) change_scene_callback_(SceneType::Game);
    }
}

void SelectorScene::OnExit() {
    std::cout << "退出选择界面" << std::endl;
}
}