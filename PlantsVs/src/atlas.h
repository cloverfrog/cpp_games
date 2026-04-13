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
private:
    std::vector<IMAGE*> img_list;
};

#endif // ATLAS_H