#ifndef BUTTON_H
#define BUTTON_H

#include "graphics.h"
#include "utils.h"

#include <string>
#include <functional>

class Button {
public:
    Button(RECT rect, std::string path_img_idle, std::string path_img_hovered, std::string path_img_pushed, std::function<void()> on_click);
    ~Button() = default;

    void Draw() const;
    void ProcessEvent(const ExMessage& msg);
private:
    bool CheckCursorHit(int x, int y) const {
        return x >= region.left && x <= region.right && y >= region.top && y <= region.bottom;
    };
private:
    enum class Status {
        Idle,
        Hovered,
        Pushed
    };
private:
    RECT region;
    IMAGE img_idle;
    IMAGE img_hovered;
    IMAGE img_pushed;
    Status status = Status::Idle;
    std::function<void()> on_click;
};

#endif // BUTTON_H