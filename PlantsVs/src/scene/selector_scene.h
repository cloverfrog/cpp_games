#ifndef SELECTOR_SCENE_H
#define SELECTOR_SCENE_H

#include "scene/scene.h"
#include "scene/scene_type.h"

class SelectorScene : public Scene {
public:
    SelectorScene() = default;
    ~SelectorScene() = default;

    void OnEnter() override;
    void OnUpdate() override;
    void OnDraw() override;
    void OnEvent(const ExMessage& msg) override;
    void OnExit() override;
};

#endif // SELECTOR_SCENE_H