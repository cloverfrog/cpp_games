#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <string>
#include <unordered_map>

#include <graphics.h>

#include <atlas.h>

namespace PlantsVs {
class ResourceManager {
public:
    ResourceManager() = default;
    ~ResourceManager() = default;

    void LoadResouces();

    const Atlas* GetAtlas(std::string name) const { return atlas_list_.at(name).get(); }
    const IMAGE* GetImage(std::string name) const { return img_list_.at(name).get(); }
    void SoundPlay(std::string name, bool loop=false) const;
private:
    void LoadImageFromFile(std::string name, std::string path);
    void FlipImage(std::string src_name, std::string dst_name);
    void LoadAtlas(std::string name, std::string path, int num);
    void FlipAtlas(std::string src_name, std::string dst_name);
    void LoadSound(std::string name, std::string path) const;
private:
    std::unordered_map<std::string, std::unique_ptr<Atlas>> atlas_list_;
    std::unordered_map<std::string, std::unique_ptr<IMAGE>> img_list_;
};
}

#endif // RESOURCE_MANAGER_H