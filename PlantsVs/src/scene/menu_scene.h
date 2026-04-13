#ifndef MENU_SCENE_H
#define MENU_SCENE_H

#include "scene/scene.h"
#include "scene/scene_type.h"

class MenuScene : public Scene {
public:
    MenuScene() = default;
    ~MenuScene() = default;

    void on_enter() override;
    void on_update() override;
    void on_draw() override;
    void on_event(const ExMessage& msg) override;
    void on_exit() override;
};

#endif // MENU_SCENE_H