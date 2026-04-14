#ifndef ATLAS_H
#define ATLAS_H

#include <vector>
#include <string>
#include <memory>

#include <graphics.h>

namespace PlantsVs {
class Atlas {
public:
    Atlas() = default;
    ~Atlas() = default;
    Atlas(const Atlas&) = delete;
    Atlas& operator=(const Atlas&) = delete;

    void LoadFromFile(std::string path, int num, std::string suffix="png");
    void LoadfromAtlas(Atlas& atlas, bool flip);

    IMAGE* GetImage(int index) {
        if (index < 0 || index >= img_list_.size()) return nullptr;
        return img_list_[index].get();
    }
    void Clear() { img_list_.clear(); }

    size_t size() const { return img_list_.size(); }
private:
    std::vector<std::unique_ptr<IMAGE>> img_list_;
};
}

#endif // ATLAS_H