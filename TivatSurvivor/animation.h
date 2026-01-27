#ifndef ANIMATION_H
#define ANIMATION_H

#include <graphics.h>
#include <vector>
#include <string>
#include <memory>

struct AnimationConfig{
    std::string suffix;
    unsigned int width;
    unsigned int height;
    unsigned int num;
    unsigned int interval;
};

struct Atlas {
    std::vector<std::vector<std::unique_ptr<IMAGE>>> frame_list;
    std::vector<AnimationConfig> config;

    Atlas(std::vector<AnimationConfig> cfg);
    ~Atlas() = default;
};

class Animation
{
public:
    Animation(std::shared_ptr<Atlas> ats) : atlas(ats) {};
    ~Animation() = default;

    void Play(int x, int y, size_t state);
private:
    std::shared_ptr<Atlas> atlas;

    size_t current_state = 0;
    int frame_bias = 0;
};

#endif // ANIMATION_H