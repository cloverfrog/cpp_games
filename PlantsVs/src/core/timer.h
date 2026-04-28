#ifndef TIMER_H
#define TIMER_H

#include <functional>

namespace PlantsVs {
class Timer {
public:
    Timer() = default;
    ~Timer() = default;

    void OnUpdate(float delta);

    void Init(float wait_time, bool one_shot, std::function<void()> callback) {
        wait_time_ = wait_time;
        one_shot_ = one_shot;
        callback_ = callback;
        Restart();
    }
    void Restart() { pass_time_ = 0.0f; shotted_ = false; }
    void Pause() { puased_ = true; }
    void Resume() { puased_ = false; }

private:
    float pass_time_ = 0.0f;    // 已经过去的时间
    float wait_time_ = 0.0f;    // 等待的时间
    bool puased_ = false;       // 是否暂停
    bool shotted_ = false;      // 是否触发
    bool one_shot_ = false;     // 是否只触发一次
    std::function<void()> callback_; // 回调函数
};
}

#endif // TIMER_H