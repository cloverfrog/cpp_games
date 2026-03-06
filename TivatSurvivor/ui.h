#ifndef UI_H
#define UI_H

#include "graphics.h"
#include "utils.h"
#include "button.h"

#include <optional>

class UI {
public:
    UI();
    ~UI() = default;

    void ProcessEvent(const ExMessage& msg);
    void Update();
    void Draw();

    bool Start() { if(start) { start = false; return true; } return false;  }
    bool Quit() { if(quit) { quit = false; return true; } return false;  }
private:
    static inline constexpr int BUTTON_WIDTH = 192;
    static inline constexpr int BUTTON_HEIGHT = 75;

    static inline constexpr int BUTTON1_X = 544;
    static inline constexpr int BUTTON1_Y = 430;
    static inline constexpr int BUTTON2_X = 544;
    static inline constexpr int BUTTON2_Y = 550;
private:
    IMAGE image_background;
    std::optional<Button> button_start;
    std::optional<Button> button_quit;

    bool start = false;
    bool quit = false;
};

#endif