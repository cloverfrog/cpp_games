#include "scene/selector_scene.h"

#include <iostream>

#include "utils/graphics_util.h"
#include "resource_manager.h"

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
}
void SelectorScene::OnEnter() {
    animation_peashooter_.Init(GetResourceManager().GetAtlas("atlas_peashooter_idle_right"), 100);
    animation_sunflower_.Init(GetResourceManager().GetAtlas("atlas_sunflower_idle_right"), 100);

    pos_img_VS.x = getwidth() / 2;
    pos_img_VS.y = getheight() / 2;
    pos_img_tip.x = getwidth() / 2;
    pos_img_tip.y = getheight() - 125 + GetResourceManager().GetImage("img_selector_tip")->getheight() / 2;

    pos_img_1P.x = getwidth() / 4 - OFFSET;
    pos_img_1P.y = 35 + GetResourceManager().GetImage("img_1P")->getheight() / 2;
    pos_img_2P.x = getwidth() / 4 * 3 + OFFSET;
    pos_img_2P.y = pos_img_1P.y;
    pos_img_1P_desc.x = pos_img_1P.x;
    pos_img_1P_desc.y = getheight() - 150 + GetResourceManager().GetImage("img_1P_desc")->getheight() / 2;
    pos_img_2P_desc.x = pos_img_2P.x;
    pos_img_2P_desc.y = pos_img_1P_desc.y;
    pos_img_1P_gravestone.x = pos_img_1P.x;
    pos_img_1P_gravestone.y = pos_img_1P.y + GetResourceManager().GetImage("img_1P")->getheight() / 2 + GetResourceManager().GetImage("img_gravestone_right")->getheight() / 2 + 35;
    pos_img_2P_gravestone.x = pos_img_2P.x;
    pos_img_2P_gravestone.y = pos_img_1P_gravestone.y;
    // pos_animation_1P.x = pos_img_1P.x;
    // pos_animation_1P.y = pos_img_1P_gravestone.y + 80;
    // pos_animation_2P.x = pos_img_2P.x;
    // pos_animation_2P.y = pos_animation_1P.y;
    // // pos_img_1P_name.x = getwidth() / 2 - OFFSET;
    // pos_img_1P_name.y = pos_animation_1P.y + 155;
    // // pos_img_2P_name.x = getwidth() / 2 + OFFSET;
    // pos_img_2P_name.y = pos_img_1P_name.y;
    // pos_1P_selector_btn_left.x = getwidth() / 2 - OFFSET;
    // pos_1P_selector_btn_left.y = getheight() - 50;
    // pos_1P_selector_btn_right.x = getwidth() / 2 - OFFSET;
    // pos_1P_selector_btn_right.y = getheight() - 50;
    // pos_2P_selector_btn_left.x = getwidth() / 2 + OFFSET;
    // pos_2P_selector_btn_left.y = pos_1P_selector_btn_left.y;
    // pos_2P_selector_btn_right.x = getwidth() / 2 + OFFSET;
    // pos_2P_selector_btn_right.y = pos_1P_selector_btn_right.y;
}

void SelectorScene::OnUpdate(float delta) {
    std::cout << "选择界面运行中……" << delta << std::endl;
}

void SelectorScene::OnDraw() const {
    putimage(0, 0, GetResourceManager().GetImage("img_selector_background"));

    putimage_alpha_center(pos_img_VS.x, pos_img_VS.y, GetResourceManager().GetImage("img_VS"));

    putimage_alpha_center(pos_img_1P.x, pos_img_1P.y, GetResourceManager().GetImage("img_1P"));
    putimage_alpha_center(pos_img_2P.x, pos_img_2P.y, GetResourceManager().GetImage("img_2P"));
    putimage_alpha_center(pos_img_1P_gravestone.x, pos_img_1P_gravestone.y, GetResourceManager().GetImage("img_gravestone_right"));
    putimage_alpha_center(pos_img_2P_gravestone.x, pos_img_2P_gravestone.y, GetResourceManager().GetImage("img_gravestone_left"));

    putimage_alpha_center(pos_img_1P_desc.x, pos_img_1P_desc.y, GetResourceManager().GetImage("img_1P_desc"));
    putimage_alpha_center(pos_img_2P_desc.x, pos_img_2P_desc.y, GetResourceManager().GetImage("img_2P_desc"));
    
    putimage_alpha_center(pos_img_tip.x, pos_img_tip.y, GetResourceManager().GetImage("img_selector_tip"));
}

void SelectorScene::OnEvent(const ExMessage& msg) {
    if(msg.message == WM_KEYUP) {
        if(change_scene_callback_) change_scene_callback_(SceneType::Game);
    }
}

void SelectorScene::OnExit() {
    std::cout << "退出选择界面" << std::endl;
}
}