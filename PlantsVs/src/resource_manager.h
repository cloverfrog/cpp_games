#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <string>
#include <unordered_map>

#include <graphics.h>

#include <atlas.h>

class ResourceManager {
public:
    ResourceManager() = default;
    ~ResourceManager() = default;

    void LoadResouces();
private:
    void LoadImageFromFile(std::string name, std::string path);
    void FlipImage(std::string src_name, std::string dst_name);
    void LoadAtlas(std::string name, std::string path, int num);
    void FlipAtlas(std::string src_name, std::string dst_name);
private:
    std::unordered_map<std::string, Atlas> atlas_list_;
    std::unordered_map<std::string, std::unique_ptr<IMAGE>> img_list_;
};


#endif // RESOURCE_MANAGER_H