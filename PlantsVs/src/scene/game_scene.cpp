#include "scene/game_scene.h"

#include <iostream>

namespace PlantsVs {
void GameScene::OnEnter() {
    std::cout << "进入游戏" << std::endl;
}

void GameScene::OnUpdate(float delta) {
    std::cout << "游戏运行中……" << delta << std::endl;
}

void GameScene::OnDraw() const {
    outtextxy(100, 100, _T("游戏"));
}

void GameScene::OnEvent(const ExMessage& msg) {
    if(msg.message == WM_KEYDOWN) {
        if(change_scene_callback_) change_scene_callback_(SceneType::Menu);
    }
}

void GameScene::OnExit() {
    std::cout << "退出游戏" << std::endl;
}
}