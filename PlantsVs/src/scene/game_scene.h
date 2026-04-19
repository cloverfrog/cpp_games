#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "scene/scene.h"

namespace PlantsVs {
class GameScene : public Scene {
public:
    GameScene() = default;
    ~GameScene() = default;

    void OnEnter() override;
    void OnUpdate() override;
    void OnDraw() const override;
    void OnEvent(const ExMessage& msg) override;
    void OnExit() override;
};
}

#endif // GAME_SCENE_H