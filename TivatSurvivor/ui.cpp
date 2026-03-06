#include "ui.h"

UI::UI() {
    loadimage_safe(&image_background, "img/menu.png");
    button_start.emplace(RECT(BUTTON1_X, BUTTON1_Y, BUTTON1_X + BUTTON_WIDTH, BUTTON1_Y + BUTTON_HEIGHT), 
        "img/ui_start_idle.png", "img/ui_start_hovered.png", "img/ui_start_pushed.png", [this] { start = true; });
    button_quit.emplace(RECT(BUTTON2_X, BUTTON2_Y, BUTTON2_X + BUTTON_WIDTH, BUTTON2_Y + BUTTON_HEIGHT), 
        "img/ui_quit_idle.png", "img/ui_quit_hovered.png", "img/ui_quit_pushed.png", [this] { quit = true; });
}

void UI::ProcessEvent(const ExMessage& msg) {
    button_start->ProcessEvent(msg);
    button_quit->ProcessEvent(msg);
}

void UI::Update() {

}

void UI::Draw() {
    putimage(0, 0, &image_background);
    button_start->Draw();
    button_quit->Draw();
}