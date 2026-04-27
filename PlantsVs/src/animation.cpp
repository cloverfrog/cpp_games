#include "animation.h"

namespace PlantsVs {
void Animation::OnUpdate(double delta) {
    timer_ += delta;
    if (timer_ >= interval_) {
        timer_ -= interval_;
        idx_frame_++;
        if(idx_frame_ >= atlas_->size()) {
            idx_frame_ = is_loop_ ? 0 : atlas_->size() - 1;
            if(!is_loop_ && callback_) callback_();
        }
    }
}
}