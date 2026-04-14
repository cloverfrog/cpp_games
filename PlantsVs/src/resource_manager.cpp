#include "resource_manager.h"

#include "utils/graphics_util.h"

void ResourceManager::LoadResouces() {
    AddFontResourceEx(_T("resources/IPix.ttf"), FR_PRIVATE, NULL);

    LoadImageFromFile("img_menu_background", "resources/menu_background.png");

    LoadImageFromFile("img_1P", "resources/1P.png");
    LoadImageFromFile("img_2P", "resources/2P.png");
    LoadImageFromFile("img_1P_desc", "resources/1P_desc.png");
    LoadImageFromFile("img_2P_desc", "resources/2P_desc.png");
    LoadImageFromFile("img_gravestone_right", "resources/gravestone.png");
    FlipImage("img_gravestone_right", "img_gravestone_left");
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
    atlas_list_[name] = Atlas();
    atlas_list_[name].LoadFromFile(path, num);
}

void ResourceManager::FlipAtlas(std::string src_name, std::string dst_name) {
    atlas_list_[dst_name] = Atlas();
    atlas_list_[dst_name].LoadfromAtlas(atlas_list_[src_name], true);
}