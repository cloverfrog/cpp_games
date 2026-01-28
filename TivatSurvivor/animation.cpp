#include "animation.h"

#include "utils.h"

Atlas::Atlas(std::vector<AnimationConfig> cfg):
    config(std::move(cfg))
{
    frame_list.reserve(config.size());
    for(std::size_t i = 0; i < config.size(); i++) {
        frame_list.emplace_back();
        frame_list[i].reserve(config[i].num);
        for(unsigned int j = 0; j < config[i].num; j++) {
            std::string path = config[i].suffix + std::to_string(j) + ".png";

            auto frame = std::make_unique<IMAGE>();
            loadimage_safe(frame.get(), path.c_str());
            frame_list[i].emplace_back(std::move(frame));
        }
    }
}

void Animation::Play(int x, int y, size_t state, double delta) {
    if (state < 0 || state >= atlas->config.size()) return;

    AnimationConfig cfg = atlas->config[state];

    timer += delta;
    if(timer >= static_cast<double>(cfg.interval)) {
        idx_frame = (idx_frame + 1) % cfg.num;
        timer -= static_cast<double>(cfg.interval);
    }

    if (state != current_state) {
        current_state = state;
        timer = 0;
        idx_frame = 0;
    }

    putimage_alpha(x - cfg.width / 2, y - cfg.height / 2, atlas->frame_list[state][idx_frame].get());
}