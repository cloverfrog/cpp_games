#include "scene/game_scene.h"

#include<iostream>

void GameScene::on_enter() {
    std::cout << "进入游戏" << std::endl;
}

void GameScene::on_update() {
    std::cout << "游戏运行中……" << std::endl;
}

void GameScene::on_draw() {
    outtextxy(100, 100, _T("游戏"));
}

void GameScene::on_event(const ExMessage& msg) {
    if(msg.message == WM_KEYDOWN) {
        if(observer) observer->notify((int)SceneType::Menu);
    }
}

void GameScene::on_exit() {
    std::cout << "退出游戏" << std::endl;
}