#ifndef MENU_SCENE_H
#define MENU_SCENE_H

#include "scene/scene.h"
#include "scene/scene_type.h"

class MenuScene : public Scene {
public:
    MenuScene() = default;
    ~MenuScene() = default;

    void OnEnter() override;
    void OnUpdate() override;
    void OnDraw() override;
    void OnEvent(const ExMessage& msg) override;
    void OnExit() override;
};

#endif // MENU_SCENE_H