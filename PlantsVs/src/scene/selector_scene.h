#ifndef SELECTOR_SCENE_H
#define SELECTOR_SCENE_H

#include "scene/scene.h"
#include "scene/scene_type.h"

class SelectorScene : public Scene {
public:
    SelectorScene() = default;
    ~SelectorScene() = default;

    void on_enter() override;
    void on_update() override;
    void on_draw() override;
    void on_event(const ExMessage& msg) override;
    void on_exit() override;
};

#endif // SELECTOR_SCENE_H