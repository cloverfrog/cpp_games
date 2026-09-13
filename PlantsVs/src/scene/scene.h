#ifndef SCENE_H
#define SCENE_H

#include <functional>

#include <graphics.h>

#include "scene/scene_type.h"

namespace PlantsVs {
class Scene {
public:
    Scene() = default;
    ~Scene() = default;

    void SetChangeSceneCallback(std::function<void(SceneType)> callback) { change_scene_callback_ = callback; }

    virtual void OnEnter() = 0;
    virtual void OnUpdate(float /*delta*/) = 0;
    virtual void OnDraw() const = 0;
    virtual void OnEvent(const ExMessage& /*msg*/) = 0;
    virtual void OnExit() = 0;
protected:
    std::function<void(SceneType)> change_scene_callback_ = nullptr;
};
}

#endif // SCENE_H