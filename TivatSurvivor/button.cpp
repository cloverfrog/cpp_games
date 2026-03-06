#include "button.h"

Button::Button(RECT rect, std::string path_img_idle, std::string path_img_hovered, std::string path_img_pushed, std::function<void()> callback):
    region(rect), on_click(callback) 
{
    loadimage(&img_idle, path_img_idle.c_str());
    loadimage(&img_hovered, path_img_hovered.c_str());
    loadimage(&img_pushed, path_img_pushed.c_str());
}

void Button::Draw() const {
    switch (status) {
    case Status::Idle:
        putimage(region.left, region.top, &img_idle);
        break;
    case Status::Hovered:
        putimage(region.left, region.top, &img_hovered);
        break;
    case Status::Pushed:
        putimage(region.left, region.top, &img_pushed);
        break;
    }
}

void Button::ProcessEvent(const ExMessage& msg) {
    switch (msg.message) {
    case WM_MOUSEMOVE:
        if(!CheckCursorHit(msg.x, msg.y))
            status = Status::Idle;
        else if(status == Status::Idle)
            status = Status::Hovered;
        break;
    case WM_LBUTTONDOWN:
        if (status == Status::Hovered)
            status = Status::Pushed;
        break;
    case WM_LBUTTONUP:
        if (status == Status::Pushed) {
            status = Status::Hovered;
            on_click();
        }
        break;
    default:
        break;
    }
}