#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <graphics.h>

#include "scene/scene.h"
#include "platform.h"

namespace PlantsVs {
class GameScene final: public Scene {
public:
    GameScene() = default;
    ~GameScene() = default;

    void OnEnter() override;
    void OnUpdate(float delta) override;
    void OnDraw() const override;
    void OnEvent(const ExMessage& msg) override;
    void OnExit() override;
private:
    std::vector<Platform> platform_list_;

    bool is_debug_ = false; // 是否开启调试模式
};
}

#endif // GAME_SCENE_H