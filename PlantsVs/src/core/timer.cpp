#include "core/timer.h"

namespace PlantsVs {
void Timer::OnUpdate(float delta) {
    if (puased_ || (one_shot_ && shotted_))
        return;
    pass_time_ += delta;
    if (pass_time_ >= wait_time_) {
        if(callback_)
            callback_();
        shotted_ = true;
        pass_time_ -= wait_time_;
    }
}
}