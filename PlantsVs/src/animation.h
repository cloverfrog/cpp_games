#ifndef ANIMATION_H
#define ANIMATION_H

#include <graphics.h>

#include "atlas.h"
#include "resource_manager.h"

namespace PlantsVs {
class Animation {
public:
    Animation() = default;
    ~Animation() = default;

    void Reset() { timer_ = 0; idx_frame_ = 0; }
    void Init(const Atlas* atlas, int interval, bool is_loop) { atlas_ = atlas; interval_ = interval; is_loop_ = is_loop; }

    int GetIdxFrame() const { return idx_frame_; }
    IMAGE* GetImage() const { return atlas_->GetImage(idx_frame_); }
    bool CheckFinish() const { return !is_loop_ && idx_frame_ == atlas_->size() - 1; }
private:
    double timer_;
    int idx_frame_;
    int interval_;
    bool is_loop_;
    const Atlas* atlas_ = nullptr;
};
}

#endif // ANIMATION_H