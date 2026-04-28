#ifndef SELECTOR_SCENE_H
#define SELECTOR_SCENE_H

#include <graphics.h>

#include "scene/scene.h"

namespace PlantsVs {
class SelectorScene final: public Scene {
public:
    SelectorScene() = default;
    ~SelectorScene() = default;

    void OnEnter() override;
    void OnUpdate(float delta) override;
    void OnDraw() const override;
    void OnEvent(const ExMessage& msg) override;
    void OnExit() override;
};
}

#endif // SELECTOR_SCENE_H