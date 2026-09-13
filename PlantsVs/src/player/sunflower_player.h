#ifndef SUNFLOWER_PLAYER_H
#define SUNFLOWER_PLAYER_H

#include "player.h"

namespace PlantsVs {
class SunflowerPlayer : public Player {
public:
    SunflowerPlayer();
    ~SunflowerPlayer() = default;

    void OnUpdate(float delta) override;
    void OnDraw() const override;
    void OnEvent(const Player::KeyBoard& msg) override;
};
}

#endif // SUNFLOWER_PLAYER_H