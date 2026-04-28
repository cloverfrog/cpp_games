#include "atlas.h"

#include "utils/graphics_util.h"

namespace PlantsVs {
void Atlas::LoadFromFile(std::string path, size_t num, std::string suffix) {
    img_list_.clear();
    img_list_.resize(num);
    for (size_t i = 0; i < num; i++) {
        img_list_[i] = std::make_unique<IMAGE>();
        std::string path_i = path + "_" + std::to_string(i+1) + "." + suffix;
        loadimage_safe(img_list_[i].get(), path_i.c_str());
    }
}

void Atlas::LoadfromAtlas(Atlas& atlas, bool flip) {
    img_list_.clear();
    img_list_.resize(atlas.size());
    for (size_t i = 0; i < atlas.size(); i++) {
        img_list_[i] = std::make_unique<IMAGE>();
        if (flip) flipimage(atlas.GetImage(i), img_list_[i].get());
        else *(img_list_[i]) = *(atlas.GetImage(i));
    }
}
}