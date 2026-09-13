#include "scene/game_scene.h"

#include <iostream>

#include "utils/graphics_util.h"
#include "resource_manager.h"
#include "camera.h"

namespace PlantsVs {
void GameScene::OnEnter() {
    GetCamera().Reset();

    platform_list_.reserve(4);
    platform_list_.emplace_back(PlatformLarge({640.f, 656.f}));
    platform_list_.emplace_back(PlatformSmall({299.f, 380.f}));
    platform_list_.emplace_back(PlatformSmall({979.f, 380.f}));
    platform_list_.emplace_back(PlatformSmall({639.f, 245.f}));

    player_manager_.SetPosition(PlayerId::P1, {248.f, 98.f});
    player_manager_.SetPosition(PlayerId::P2, {1023.f, 98.f});
}

void GameScene::OnUpdate(float delta) {
    player_manager_.OnUpdate(delta);
}

void GameScene::OnDraw() const {
    const Camera& camera = GetCamera();
    const Vector2& pos_camera = camera.GetPosition();

    putimage_alpha_center(GetResourceManager().GetImage("img_sky"), getwidth()/2 - static_cast<int>(pos_camera.x), getheight()/2 - static_cast<int>(pos_camera.y));
    putimage_alpha_center(GetResourceManager().GetImage("img_hills"), getwidth()/2 - static_cast<int>(pos_camera.x), getheight()/2 - static_cast<int>(pos_camera.y));

    for(const auto& platform : platform_list_) {
        platform.onDraw();
        if(is_debug_) {
            setlinecolor(RGB(255, 0, 0));
            line(static_cast<int>(platform.GetCollisionShape().left - pos_camera.x), static_cast<int>(platform.GetCollisionShape().y - pos_camera.y),
                 static_cast<int>(platform.GetCollisionShape().right - pos_camera.x), static_cast<int>(platform.GetCollisionShape().y - pos_camera.y));
        }
    }

    player_manager_.OnDraw();

    if(is_debug_) {
        settextcolor(RGB(255, 0, 0));
        outtextxy(15, 15, _T("已开启调试模式，按 Q 关闭"));
    }
}

void GameScene::OnEvent(const ExMessage& msg) {
    switch(msg.message) {
        case WM_KEYDOWN:
            switch(msg.vkcode) {
                case 'Q':
                    is_debug_ = !is_debug_;
                    break;
                default:
                    break;
            }
            break;
        case WM_KEYUP:
            switch(msg.vkcode) {
            case VK_ESCAPE:
                if(change_scene_callback_) change_scene_callback_(SceneType::Menu);
                default:
                    break;
            }
            break;
        default:
            break;
    }

    player_manager_.OnEvent(msg);
}

void GameScene::OnExit() {
    std::cout << "退出游戏" << std::endl;
}
}