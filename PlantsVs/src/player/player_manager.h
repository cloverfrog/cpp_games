#ifndef PLAYER_MANAGER_H
#define PLAYER_MANAGER_H

#include <memory>

#include "base/singleton.h"
#include "player/player.h"

namespace PlantsVs {
enum class PlayerId {
    P1,
    P2
};

class PlayerManager : public Singleton<PlayerManager> {
    friend class Singleton<PlayerManager>;
public:
    PlayerManager() = default;
    ~PlayerManager() = default;

    void SetPlayer1(std::unique_ptr<Player> player) { player1_ = std::move(player); }
    void SetPlayer2(std::unique_ptr<Player> player) { player2_ = std::move(player); }
    void SetPosition(PlayerId player_id, const Vector2& pos) {
        if(player_id == PlayerId::P1 && player1_) {
            player1_->SetPosition(pos);
        }
        else if(player_id == PlayerId::P2 && player2_) {
            player2_->SetPosition(pos);
        }
    }
    void OnUpdate(float delta) {
        if(!player1_ && !player2_) return;
        player1_->OnUpdate(delta);
        player2_->OnUpdate(delta);
    }
    void OnDraw() const {
        if(!player1_ && !player2_) return;
        player1_->OnDraw();
        player2_->OnDraw();
    }
    void OnEvent(const ExMessage& msg);
private:
    std::unique_ptr<Player> player1_;
    std::unique_ptr<Player> player2_;
};
}

#endif // PLAYER_MANAGER_H