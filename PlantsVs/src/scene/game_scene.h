#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "scene/scene.h"
#include "scene/scene_type.h"

class GameScene : public Scene {
public:
    GameScene() = default;
    ~GameScene() = default;

    void on_enter() override;
    void on_update() override;
    void on_draw() override;
    void on_event(const ExMessage& msg) override;
    void on_exit() override;
};

#endif // GAME_SCENE_H