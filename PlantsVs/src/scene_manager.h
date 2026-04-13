#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "base/i_observer.h"
#include "scene/scene.h"
#include "scene/scene_type.h"
#include "scene/menu_scene.h"
#include "scene/game_scene.h"
#include "scene/selector_scene.h"

#include <memory>

class SceneManager : public IObserver {
public:
    SceneManager();
    ~SceneManager() = default;

    void onEvent(const ExMessage& msg) { current_scene->on_event(msg); }
    void onUpdate() { current_scene->on_update(); }
    void onDraw() { current_scene->on_draw(); }

    void notify(int code) override { changeScene((SceneType)code); }
private:
    void changeScene(SceneType type);
private:
    std::shared_ptr<Scene> current_scene = nullptr;
    std::shared_ptr<MenuScene> menu_scene;
    std::shared_ptr<GameScene> game_scene;
    std::shared_ptr<SelectorScene> selector_scene;
};

#endif // SCENE_MANAGER_H