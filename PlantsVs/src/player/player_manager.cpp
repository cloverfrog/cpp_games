#include "player_manager.h"

namespace PlantsVs {

void PlayerManager::OnEvent(const ExMessage& msg) {
    if(!player1_ && !player2_) return;
    switch(msg.message) {
    case WM_KEYDOWN:
        switch(msg.vkcode) {
        case 'A':
            player1_->OnEvent(Player::KeyBoard::Left_Down);
            break;
        case 'D':
            player1_->OnEvent(Player::KeyBoard::Right_Down);
            break;
        case VK_LEFT:
            player2_->OnEvent(Player::KeyBoard::Left_Down);
            break;
        case VK_RIGHT:
            player2_->OnEvent(Player::KeyBoard::Right_Down);
            break;
        default:
            break;
        }
        break;
        
    case WM_KEYUP:
        switch(msg.vkcode) {
        case 'A':
            player1_->OnEvent(Player::KeyBoard::Left_Up);
            break;
        case 'D':
            player1_->OnEvent(Player::KeyBoard::Right_Up);
            break;
        case VK_LEFT:
            player2_->OnEvent(Player::KeyBoard::Left_Up);
            break;
        case VK_RIGHT:
            player2_->OnEvent(Player::KeyBoard::Right_Up);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

}