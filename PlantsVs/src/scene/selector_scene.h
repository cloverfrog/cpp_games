#ifndef SELECTOR_SCENE_H
#define SELECTOR_SCENE_H

#include <graphics.h>

#include "scene/scene.h"
#include "animation.h"

namespace PlantsVs {
class SelectorScene final: public Scene {
public:
    SelectorScene() = default;
    ~SelectorScene() = default;

    void OnEnter() override;
    void OnUpdate(float delta) override;
    void OnDraw() const override;
    void OnEvent(const ExMessage& msg) override;
    void OnExit() override;

private:
    enum class PlayerType {
        Peashooter,
        Sunflower,
        Invalid
    };

private:
    Animation animation_peashooter_;
    Animation animation_sunflower_;

    PlayerType player1_type_ = PlayerType::Peashooter;
    PlayerType player2_type_ = PlayerType::Sunflower;

    int selector_background_scroll_offset_ = 0;

    bool is_btn_1P_left_down_ = false;
    bool is_btn_1P_right_down_ = false;
    bool is_btn_2P_left_down_ = false;
    bool is_btn_2P_right_down_ = false;
};
}

#endif // SELECTOR_SCENE_H