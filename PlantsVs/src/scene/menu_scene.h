#ifndef MENU_SCENE_H
#define MENU_SCENE_H

#include <graphics.h>

#include "scene/scene.h"
#include "animation.h"
#include "camera.h"

namespace PlantsVs {
class MenuScene final: public Scene {
public:
    MenuScene() = default;
    ~MenuScene() = default;

    void OnEnter() override;
    void OnUpdate(float delta) override;
    void OnDraw() const override;
    void OnEvent(const ExMessage& msg) override;
    void OnExit() override;
private:
    Animation animation_peashooter_run_right_;
    Camera camera_;
};
}

#endif // MENU_SCENE_H