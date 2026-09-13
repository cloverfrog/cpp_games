#ifndef PEASHOOTER_PLAYER_H
#define PEASHOOTER_PLAYER_H

#include "player.h"

namespace PlantsVs {
class PeashooterPlayer : public Player {
public:
    PeashooterPlayer();
    ~PeashooterPlayer() = default;

    void OnUpdate(float delta) override;
    void OnDraw() const override;
    void OnEvent(const Player::KeyBoard& msg) override;
};
}

#endif // PEASHOOTER_PLAYER_H