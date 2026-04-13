#include "scene/selector_scene.h"

#include <iostream>

void SelectorScene::on_enter() {
    std::cout << "进入选择界面" << std::endl;
}

void SelectorScene::on_update() {
    std::cout << "选择界面运行中……" << std::endl;
}

void SelectorScene::on_draw() {
    outtextxy(100, 100, _T("选择界面"));
}

void SelectorScene::on_event(const ExMessage& msg) {
    if(msg.message == WM_KEYDOWN) {
        if(observer) observer->notify((int)SceneType::Game);
    }
}

void SelectorScene::on_exit() {
    std::cout << "退出选择界面" << std::endl;
}