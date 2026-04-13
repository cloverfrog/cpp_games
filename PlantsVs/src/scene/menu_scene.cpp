#include "scene/menu_scene.h"

#include <iostream>

void MenuScene::on_enter() {
    std::cout << "进入主菜单" << std::endl;
}

void MenuScene::on_update() {
    std::cout << "主菜单运行中……" << std::endl;
}

void MenuScene::on_draw() {
    outtextxy(100, 100, _T("主菜单"));
}

void MenuScene::on_event(const ExMessage& msg) {
    if(msg.message == WM_KEYDOWN) {
        if(observer) observer->notify((int)SceneType::Selector);
    }
}

void MenuScene::on_exit() {
    std::cout << "退出主菜单" << std::endl;
}