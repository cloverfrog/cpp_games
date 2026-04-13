#ifndef SCENE_H
#define SCENE_H

#include "base/i_observer.h"

#include <graphics.h>

class Scene {
public:
    Scene() = default;
    ~Scene() = default;

    void setObserver(IObserver* observer) { this->observer = observer; }

    virtual void on_enter() {}
    virtual void on_update() {}
    virtual void on_draw() {}
    virtual void on_event(const ExMessage& msg) {}
    virtual void on_exit() {}
protected:
    IObserver* observer = nullptr;
};

#endif // SCENE_H