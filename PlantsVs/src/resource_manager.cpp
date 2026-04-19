#include "resource_manager.h"

#include "utils/graphics_util.h"

namespace PlantsVs {
void ResourceManager::LoadResouces() {
    AddFontResourceEx(_T("resources/IPix.ttf"), FR_PRIVATE, NULL);

    LoadImageFromFile("img_menu_background", "resources/menu_background.png");

    LoadImageFromFile("img_VS", "resources/VS.png");
    LoadImageFromFile("img_1P", "resources/1P.png");
    LoadImageFromFile("img_2P", "resources/2P.png");
    LoadImageFromFile("img_1P_desc", "resources/1P_desc.png");
    LoadImageFromFile("img_2P_desc", "resources/2P_desc.png");
    LoadImageFromFile("img_gravestone_right", "resources/gravestone.png");
    FlipImage("img_gravestone_right", "img_gravestone_left");
    LoadImageFromFile("img_selector_tip", "resources/selector_tip.png");
    LoadImageFromFile("img_selector_background", "resources/selector_background.png");
    LoadImageFromFile("img_1P_selector_btn_idle_right", "resources/1P_selector_btn_idle.png");
    FlipImage("img_1P_selector_btn_idle_right", "img_1P_selector_btn_idle_left");
    LoadImageFromFile("img_1P_selector_btn_down_right", "resources/1P_selector_btn_down.png");
    FlipImage("img_1P_selector_btn_down_right", "img_1P_selector_btn_down_left");
    LoadImageFromFile("img_2P_selector_btn_idle_right", "resources/2P_selector_btn_idle.png");
    FlipImage("img_2P_selector_btn_idle_right", "img_2P_selector_btn_idle_left");
    LoadImageFromFile("img_2P_selector_btn_down_right", "resources/2P_selector_btn_down.png");
    FlipImage("img_2P_selector_btn_down_right", "img_2P_selector_btn_down_left");
    LoadImageFromFile("img_peashooter_selector_background_right", "resources/peashooter_selector_background.png");
    FlipImage("img_peashooter_selector_background_right", "img_peashooter_selector_background_left");
    LoadImageFromFile("img_sunflower_selector_background_right", "resources/sunflower_selector_background.png");
    FlipImage("img_sunflower_selector_background_right", "img_sunflower_selector_background_left");

    LoadImageFromFile("img_sky", "resources/sky.png");
    LoadImageFromFile("img_hills", "resources/hills.png");
    LoadImageFromFile("img_platform_large", "resources/platform_large-png");
    LoadImageFromFile("img_platform_small", "resources/platform_small.png");

    LoadImageFromFile("img_1P_cursor", "resources/1P_cursor.png");
    LoadImageFromFile("img_2P_cursor", "resources/2P_cursor.png");

    LoadAtlas("atlas_peashooter_idle_right", "resources/peashooter_idle", 9);
    FlipAtlas("atlas_peashooter_idle_right", "atlas_peashooter_idle_left");
    LoadAtlas("atlas_peashooter_run_right", "resources/peashooter_run", 5);
    FlipAtlas("atlas_peashooter_run_right", "atlas_peashooter_run_left");
    LoadAtlas("atlas_peashooter_attack_ex_right", "resources/peashooter_attack_ex", 3);
    FlipAtlas("atlas_peashooter_attack_ex_right", "atlas_peashooter_attack_ex_left");
    LoadAtlas("atlas_peashooter_die_right", "resources/peashooter_die", 4);
    FlipAtlas("atlas_peashooter_die_right", "atlas_peashooter_die_left");

    LoadAtlas("atlas_sunflower_idle_right", "resources/sunflower_idle", 8);
    FlipAtlas("atlas_sunflower_idle_right", "atlas_sunflower_idle_left");
    LoadAtlas("atlas_sunflower_run_right", "resources/sunflower_run", 5);
    FlipAtlas("atlas_sunflower_run_right", "atlas_sunflower_run_left");
    LoadAtlas("atlas_sunflower_attack_ex_right", "resources/sunflower_attack_ex", 9);
    FlipAtlas("atlas_sunflower_attack_ex_right", "atlas_sunflower_attack_ex_left");
    LoadAtlas("atlas_sunflower_die_right", "resources/sunflower_die", 2);
    FlipAtlas("atlas_sunflower_die_right", "atlas_sunflower_die_left");

    LoadImageFromFile("img_pea", "resources/pea.png");
    LoadAtlas("atlas_pea_break", "resources/pea_break", 3);
    LoadAtlas("atlas_sun", "resources/sun", 5);
    LoadAtlas("atlas_sun_explode", "resources/sun_explode", 5);
    LoadAtlas("atlas_sun_ex", "resources/sun_ex", 5);
    LoadAtlas("atlas_sun_ex_explode", "resources/sun_ex_explode", 5);
    LoadAtlas("atlas_sun_text", "resources/sun_text", 6);

    LoadAtlas("atlas_run_effect", "resources/run_effect", 4);
    LoadAtlas("atlas_jump_effect", "resources/jump_effect", 5);
    LoadAtlas("atlas_land_effect", "resources/land_effect", 2);

    LoadImageFromFile("img_1P_winnner", "resources/1P_winner.png");
    LoadImageFromFile("img_2P_winnner", "resources/2P_winner.png");
    LoadImageFromFile("img_winnner_bar", "resources/winnner_bar.png");
    LoadImageFromFile("img_avatar_peashooter", "resources/avatar_peashooter.png");
    LoadImageFromFile("img_avatar_sunflower", "resources/avatar_sunflower.png");

    LoadSound("bgm_game", "resources/bgm_game.mp3");
    LoadSound("bgm_menu", "resources/bgm_menu.mp3");
    LoadSound("pea_break_1", "resources/pea_break_1.mp3");
    LoadSound("pea_break_2", "resources/pea_break_2.mp3");
    LoadSound("pea_break_3", "resources/pea_break_3.mp3");
    LoadSound("pea_shoot_1", "resources/pea_shoot_1.mp3");
    LoadSound("pea_shoot_2", "resources/pea_shoot_2.mp3");
    LoadSound("pea_shoot_ex", "resources/pea_shoot_ex.mp3");
    LoadSound("sun_explode", "resources/sun_explode.mp3");
    LoadSound("sun_explode_ex", "resources/sun_explode_ex.mp3");
    LoadSound("sun_text", "resources/sun_text.mp3");
    LoadSound("ui_confirm", "resources/ui_confirm.wav");
    LoadSound("ui_switch", "resources/ui_switch.wav");
    LoadSound("ui_win", "resources/ui_win.wav");
}

void ResourceManager::LoadImageFromFile(std::string name, std::string path) {
    img_list_[name] = std::make_unique<IMAGE>();
    loadimage_safe(img_list_[name].get(), path.c_str());
}

void ResourceManager::FlipImage(std::string src_name, std::string dst_name) {
    img_list_[dst_name] = std::make_unique<IMAGE>();
    flipimage(img_list_[src_name].get(), img_list_[dst_name].get());
}

void ResourceManager::LoadAtlas(std::string name, std::string path, int num) {
    atlas_list_[name] = std::make_unique<Atlas>();
    atlas_list_[name]->LoadFromFile(path, num);
}

void ResourceManager::FlipAtlas(std::string src_name, std::string dst_name) {
    atlas_list_[dst_name] = std::make_unique<Atlas>();
    atlas_list_[dst_name]->LoadfromAtlas(*atlas_list_[src_name], true);
}

void ResourceManager::LoadSound(std::string name, std::string path) const {
    std::string command = "open " + path + " alias " + name;
    mciSendString(_T(command.c_str()), NULL, 0, NULL);
}

void ResourceManager::SoundPlay(std::string name, bool loop) const {
    std::string command = "play " + name + " from 0";
    if (loop) command += " repeat";
    mciSendString(_T(command.c_str()), NULL, 0, NULL);
}
}