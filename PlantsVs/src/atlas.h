#ifndef ATLAS_H
#define ATLAS_H

#include <vector>
#include <string>
#include <memory>

#include <graphics.h>

class Atlas {
public:
    Atlas() = default;
    ~Atlas() = default;

    void LoadFromFile(std::string path, int num);
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

#endif // ATLAS_H