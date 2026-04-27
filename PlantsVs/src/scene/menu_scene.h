#ifndef MENU_SCENE_H
#define MENU_SCENE_H

#include <graphics.h>

#include "scene/scene.h"
#include "animation.h"

namespace PlantsVs {
class MenuScene : public Scene {
public:
    MenuScene() = default;
    ~MenuScene() = default;

    void OnEnter() override;
    void OnUpdate(double delta) override;
    void OnDraw() const override;
    void OnEvent(const ExMessage& msg) override;
    void OnExit() override;
private:
    Animation animation_peashooter_run_right_;
};
}

#endif // MENU_SCENE_H