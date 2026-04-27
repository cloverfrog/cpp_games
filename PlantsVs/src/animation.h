#ifndef ANIMATION_H
#define ANIMATION_H

#include <functional>

#include <graphics.h>

#include "utils/graphics_util.h"
#include "atlas.h"
#include "resource_manager.h"

namespace PlantsVs {
class Animation {
public:
    Animation() = default;
    ~Animation() = default;

    void Reset() { timer_ = 0; idx_frame_ = 0; }
    void Init(const Atlas* atlas, double interval, bool is_loop=true, std::function<void()> callback=nullptr) { atlas_ = atlas; interval_ = interval; is_loop_ = is_loop; callback_ = callback; }

    void OnUpdate(double delta);
    void OnDraw(int x, int y) const { putimage_alpha_center(x, y, atlas_->GetImage(idx_frame_)); }

    int GetIdxFrame() const { return idx_frame_; }
    IMAGE* GetImage() const { return atlas_->GetImage(idx_frame_); }
    bool CheckFinish() const { return !is_loop_ && idx_frame_ == atlas_->size() - 1; }
private:
    double timer_ = 0.;
    size_t idx_frame_ = 0;
    double interval_ = 0;
    bool is_loop_ = false;
    const Atlas* atlas_ = nullptr;
    std::function<void()> callback_ = nullptr;
};
}

#endif // ANIMATION_H