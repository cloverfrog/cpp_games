#ifndef SCENE_H
#define SCENE_H

#include <functional>

#include <graphics.h>

#include "base/i_observer.h"
#include "scene/scene_type.h"

namespace PlantsVs {
class Scene {
public:
    Scene() = default;
    ~Scene() = default;

    void SetChangeSceneCallback(std::function<void(SceneType)> callback) { change_scene_callback_ = callback; }

    virtual void OnEnter() {}
    virtual void OnUpdate(double delta) {}
    virtual void OnDraw() const{}
    virtual void OnEvent(const ExMessage& msg) {}
    virtual void OnExit() {}
protected:
    std::function<void(SceneType)> change_scene_callback_ = nullptr;
};
}

#endif // SCENE_H