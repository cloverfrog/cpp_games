#include "scene/game_scene.h"

#include<iostream>

void GameScene::OnEnter() {
    std::cout << "进入游戏" << std::endl;
}

void GameScene::OnUpdate() {
    std::cout << "游戏运行中……" << std::endl;
}

void GameScene::OnDraw() {
    outtextxy(100, 100, _T("游戏"));
}

void GameScene::OnEvent(const ExMessage& msg) {
    if(msg.message == WM_KEYDOWN) {
        if(observer_) observer_->Notify((int)SceneType::Menu);
    }
}

void GameScene::OnExit() {
    std::cout << "退出游戏" << std::endl;
}