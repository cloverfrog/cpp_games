#ifndef SCENE_H
#define SCENE_H

#include <graphics.h>

#include "base/i_observer.h"

namespace PlantsVs {
class Scene {
public:
    Scene() = default;
    ~Scene() = default;

    void SetObserver(IObserver* observer) { observer_ = observer; }

    virtual void OnEnter() {}
    virtual void OnUpdate(double delta) {}
    virtual void OnDraw() const{}
    virtual void OnEvent(const ExMessage& msg) {}
    virtual void OnExit() {}
protected:
    IObserver* observer_ = nullptr;
};
}

#endif // SCENE_H