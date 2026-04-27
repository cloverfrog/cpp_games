#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "base/i_observer.h"
#include "scene/scene.h"
#include "scene/scene_type.h"
#include "scene/menu_scene.h"
#include "scene/game_scene.h"
#include "scene/selector_scene.h"

#include <memory>

namespace PlantsVs {
class SceneManager : public IObserver {
public:
    SceneManager();
    ~SceneManager() = default;

    void OnEvent(const ExMessage& msg) { current_scene_->OnEvent(msg); }
    void OnUpdate(double delta) { current_scene_->OnUpdate(delta); }
    void OnDraw() const { current_scene_->OnDraw(); }

    void Notify(int code) override { ChangeScene((SceneType)code); }
private:
    void ChangeScene(SceneType type);
private:
    Scene* current_scene_ = nullptr;
    std::unique_ptr<MenuScene> menu_scene_;
    std::unique_ptr<GameScene> game_scene_;
    std::unique_ptr<SelectorScene> selector_scene_;
};
}

#endif // SCENE_MANAGER_H