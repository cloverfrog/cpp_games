#include "scene/selector_scene.h"

#include "utils/graphics_util.h"
#include "resource_manager.h"
#include "player/peashooter_player.h"
#include "player/sunflower_player.h"
#include "player/player_manager.h"

namespace PlantsVs {
namespace {
    POINT pos_img_VS = {0, 0}; // VS 艺术字图片位置
    POINT pos_img_tip = {0, 0}; // 提示信息文本图片位置
    POINT pos_img_1P = {0, 0}; // 1P 文本图片位置
    POINT pos_img_2P = {0, 0}; // 2P 文本图片位置
    POINT pos_img_1P_desc = {0, 0}; // 1P 键位描述图片位置
    POINT pos_img_2P_desc = {0, 0}; // 2P 键位描述图片位置
    POINT pos_img_1P_name = {0, 0}; // 1P 角色姓名文本位置
    POINT pos_img_2P_name = {0, 0}; // 2P 角色姓名文本位置
    POINT pos_animation_1P = {0, 0}; // 1P 角色动画位置
    POINT pos_animation_2P = {0, 0}; // 2P 角色动画位置
    POINT pos_img_1P_gravestone = {0, 0}; // 1P 墓碑图片位置
    POINT pos_img_2P_gravestone = {0, 0}; // 2P 墓碑图片位置
    POINT pos_1P_selector_btn_left = {0, 0}; // 1P 向左切换按钮位置
    POINT pos_1P_selector_btn_right = {0, 0}; // 1P 向右切换按钮位置
    POINT pos_2P_selector_btn_left = {0, 0}; // 2P 向左切换按钮位置
    POINT pos_2P_selector_btn_right = {0, 0}; // 2P 向右切换按钮位置

    constexpr int OFFSET = 50;
    constexpr int SCROLL_WIDTH = 560;
}
void SelectorScene::OnEnter() {
    animation_peashooter_.Init(GetResourceManager().GetAtlas("atlas_peashooter_idle_right"), 100);
    animation_sunflower_.Init(GetResourceManager().GetAtlas("atlas_sunflower_idle_right"), 100);

    pos_img_VS.x = getwidth() / 2;
    pos_img_VS.y = getheight() / 2;
    pos_img_tip.x = getwidth() / 2;
    // pos_img_tip.y = getheight() - 125 + GetResourceManager().GetImage("img_selector_tip")->getheight() / 2;
    pos_img_tip.y = getheight() - 105;

    pos_img_1P.x = getwidth() / 4 - OFFSET;
    // pos_img_1P.y = 35 + GetResourceManager().GetImage("img_1P")->getheight() / 2;
    pos_img_1P.y = 72;
    pos_img_2P.x = getwidth() / 4 * 3 + OFFSET;
    pos_img_2P.y = pos_img_1P.y;
    pos_img_1P_desc.x = pos_img_1P.x;
    // pos_img_1P_desc.y = getheight() - 150 + GetResourceManager().GetImage("img_1P_desc")->getheight() / 2;
    pos_img_1P_desc.y = getheight() - 112;
    pos_img_2P_desc.x = pos_img_2P.x;
    pos_img_2P_desc.y = pos_img_1P_desc.y;
    pos_img_1P_gravestone.x = pos_img_1P.x;
    // pos_img_1P_gravestone.y = pos_img_1P.y + GetResourceManager().GetImage("img_1P")->getheight() / 2 + GetResourceManager().GetImage("img_gravestone_right")->getheight() / 2 + 35;
    pos_img_1P_gravestone.y = pos_img_1P.y + 260;
    pos_img_2P_gravestone.x = pos_img_2P.x;
    pos_img_2P_gravestone.y = pos_img_1P_gravestone.y;
    pos_animation_1P.x = pos_img_1P.x;
    pos_animation_1P.y = pos_img_1P_gravestone.y - 60;
    pos_animation_2P.x = pos_img_2P.x;
    pos_animation_2P.y = pos_animation_1P.y;
    pos_img_1P_name.x = pos_img_1P.x;
    pos_img_1P_name.y = pos_animation_1P.y + 107;
    pos_img_2P_name.x = pos_img_2P.x;
    pos_img_2P_name.y = pos_img_1P_name.y;
    pos_1P_selector_btn_left.x = pos_img_1P.x - 151;
    pos_1P_selector_btn_left.y = pos_img_1P_gravestone.y;
    pos_1P_selector_btn_right.x = pos_img_1P.x + 151;
    pos_1P_selector_btn_right.y = pos_1P_selector_btn_left.y;
    pos_2P_selector_btn_left.x = pos_img_2P.x - 151;
    pos_2P_selector_btn_left.y = pos_1P_selector_btn_left.y;
    pos_2P_selector_btn_right.x = pos_img_2P.x + 151;
    pos_2P_selector_btn_right.y = pos_1P_selector_btn_left.y;
}

void SelectorScene::OnUpdate(float delta) {
    animation_peashooter_.OnUpdate(delta);
    animation_sunflower_.OnUpdate(delta);

    selector_background_scroll_offset_ = (selector_background_scroll_offset_ + 5) % SCROLL_WIDTH;
}

void SelectorScene::OnDraw() const {

    // 滚动背景选择
    const IMAGE *img_p1_selector_background = nullptr, *img_p2_selector_background = nullptr;
    switch(player1_type_) {
        case PlayerType::Peashooter:
            img_p2_selector_background = GetResourceManager().GetImage("img_peashooter_selector_background_left");
            break;
        case PlayerType::Sunflower:
            img_p2_selector_background = GetResourceManager().GetImage("img_sunflower_selector_background_left");
            break;
        default:
            break;
    }
    switch(player2_type_) {
        case PlayerType::Peashooter:
            img_p1_selector_background = GetResourceManager().GetImage("img_peashooter_selector_background_right");
            break;
        case PlayerType::Sunflower:
            img_p1_selector_background = GetResourceManager().GetImage("img_sunflower_selector_background_right");
            break;
        default:
            break;
    }

    putimage(0, 0, GetResourceManager().GetImage("img_selector_background"));

    // 绘制滚动背景
    putimage_alpha(img_p1_selector_background, selector_background_scroll_offset_ - SCROLL_WIDTH, 0, 0, 0, SCROLL_WIDTH - selector_background_scroll_offset_, 0);
    putimage_alpha(img_p1_selector_background, selector_background_scroll_offset_, 0, 0, 0, SCROLL_WIDTH - selector_background_scroll_offset_, 0);
    putimage_alpha(img_p2_selector_background, getwidth() - selector_background_scroll_offset_, 0, 0, 0, SCROLL_WIDTH - selector_background_scroll_offset_, 0);
    putimage_alpha(img_p2_selector_background, getwidth() - SCROLL_WIDTH , 0, selector_background_scroll_offset_, 0, SCROLL_WIDTH - selector_background_scroll_offset_, 0);

    putimage_alpha_center(GetResourceManager().GetImage("img_VS"), pos_img_VS.x, pos_img_VS.y);

    putimage_alpha_center(GetResourceManager().GetImage("img_1P"), pos_img_1P.x, pos_img_1P.y);
    putimage_alpha_center(GetResourceManager().GetImage("img_2P"), pos_img_2P.x, pos_img_2P.y);
    putimage_alpha_center(GetResourceManager().GetImage("img_gravestone_right"), pos_img_1P_gravestone.x, pos_img_1P_gravestone.y);
    putimage_alpha_center(GetResourceManager().GetImage("img_gravestone_left"), pos_img_2P_gravestone.x, pos_img_2P_gravestone.y);

    switch(player1_type_) {
        case PlayerType::Peashooter:
            animation_peashooter_.OnDraw(pos_animation_1P.x, pos_animation_1P.y);
            outtext_shaded(pos_img_1P_name.x - 56, pos_img_1P_name.y, "婉逗射手");
            break;
        case PlayerType::Sunflower:
            animation_sunflower_.OnDraw(pos_animation_1P.x, pos_animation_1P.y);
            outtext_shaded(pos_img_1P_name.x - 42, pos_img_1P_name.y, "龙日葵");
            break;
        default:
            break;
    }

    switch(player2_type_) {
        case PlayerType::Peashooter:
            animation_peashooter_.OnDraw(pos_animation_2P.x, pos_animation_2P.y);
            outtext_shaded(pos_img_2P_name.x - 56, pos_img_2P_name.y, "婉逗射手");
            break;
        case PlayerType::Sunflower:
            animation_sunflower_.OnDraw(pos_animation_2P.x, pos_animation_2P.y);
            outtext_shaded(pos_img_2P_name.x - 42, pos_img_2P_name.y, "龙日葵");
            break;
        default:
            break;
    }

    putimage_alpha_center(GetResourceManager().GetImage(is_btn_1P_left_down_ ? "img_1P_selector_btn_down_left" : "img_1P_selector_btn_idle_left"), pos_1P_selector_btn_left.x, pos_1P_selector_btn_left.y);
    putimage_alpha_center(GetResourceManager().GetImage(is_btn_1P_right_down_ ? "img_1P_selector_btn_down_right" : "img_1P_selector_btn_idle_right"), pos_1P_selector_btn_right.x, pos_1P_selector_btn_right.y);
    putimage_alpha_center(GetResourceManager().GetImage(is_btn_2P_left_down_ ? "img_2P_selector_btn_down_left" : "img_2P_selector_btn_idle_left"), pos_2P_selector_btn_left.x, pos_2P_selector_btn_left.y);
    putimage_alpha_center(GetResourceManager().GetImage(is_btn_2P_right_down_ ? "img_2P_selector_btn_down_right" : "img_2P_selector_btn_idle_right"), pos_2P_selector_btn_right.x, pos_2P_selector_btn_right.y);

    putimage_alpha_center(GetResourceManager().GetImage("img_1P_desc"), pos_img_1P_desc.x, pos_img_1P_desc.y);
    putimage_alpha_center(GetResourceManager().GetImage("img_2P_desc"), pos_img_2P_desc.x, pos_img_2P_desc.y);
    
    putimage_alpha_center(GetResourceManager().GetImage("img_selector_tip"), pos_img_tip.x, pos_img_tip.y);
}

void SelectorScene::OnEvent(const ExMessage& msg) {
    switch(msg.message) {
        case WM_KEYDOWN:
            switch(msg.vkcode) {
                case 'A':
                    is_btn_1P_left_down_ = true;
                    break;
                case 'D':
                    is_btn_1P_right_down_ = true;
                    break;
                case VK_LEFT:
                    is_btn_2P_left_down_ = true;
                    break;
                case VK_RIGHT:
                    is_btn_2P_right_down_ = true;
                    break;
                default:
                    break;
            }
            break;
        case WM_KEYUP:
            switch(msg.vkcode) {
                case 'A':
                    is_btn_1P_left_down_ = false;
                    player1_type_ = static_cast<PlayerType>((static_cast<int>(PlayerType::Invalid) + static_cast<int>(player1_type_) - 1) % static_cast<int>(PlayerType::Invalid));
                    GetResourceManager().SoundPlay("ui_switch");
                    break;
                case 'D':
                    is_btn_1P_right_down_ = false;
                    player1_type_ = static_cast<PlayerType>((static_cast<int>(player1_type_) + 1) % static_cast<int>(PlayerType::Invalid));
                    GetResourceManager().SoundPlay("ui_switch");
                    break;
                case VK_LEFT:
                    is_btn_2P_left_down_ = false;
                    player2_type_ = static_cast<PlayerType>((static_cast<int>(PlayerType::Invalid) + static_cast<int>(player2_type_) - 1) % static_cast<int>(PlayerType::Invalid));
                    GetResourceManager().SoundPlay("ui_switch");
                    break;
                case VK_RIGHT:
                    is_btn_2P_right_down_ = false;
                    player2_type_ = static_cast<PlayerType>((static_cast<int>(player2_type_) + 1) % static_cast<int>(PlayerType::Invalid));
                    GetResourceManager().SoundPlay("ui_switch");
                    break;
                case VK_RETURN:
                case VK_SPACE:
                    GetResourceManager().SoundPlay("ui_confirm");
                    if(change_scene_callback_) change_scene_callback_(SceneType::Game);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

void SelectorScene::OnExit() {
    switch(player1_type_) {
        case PlayerType::Peashooter:
            PlayerManager::GetInstance().SetPlayer1(std::make_unique<PeashooterPlayer>());
            break;
        case PlayerType::Sunflower:
            PlayerManager::GetInstance().SetPlayer1(std::make_unique<SunflowerPlayer>());
            break;
        default:
            break;
    }

    switch(player2_type_) {
        case PlayerType::Peashooter:
            PlayerManager::GetInstance().SetPlayer2(std::make_unique<PeashooterPlayer>());
            break;
        case PlayerType::Sunflower:
            PlayerManager::GetInstance().SetPlayer2(std::make_unique<SunflowerPlayer>());
            break;
        default:
            break;
    }
}
}