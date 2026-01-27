#ifndef ENEMY_H
#define ENEMY_H

#include "animation.h"
#include "utils.h"

#include <graphics.h>
#include <optional>

class Enemy {
public:
    Enemy(Position pos, double speed);
    ~Enemy() = default;

    void Move(int dir_x, int dir_y);
    void Draw();

    Position GetPosition() { return position; }

    static void Init(RECT limit);
    static RECT GetLimitArea() { return limit_area; }
    static SIZE GetSize() { return {FRAME_WIDTH, FRAME_HEIGHT}; }
private:
    static inline constexpr int FRAME_WIDTH = 80;
    static inline constexpr int FRAME_HEIGHT = 80;
    static inline constexpr int FRAME_NUM = 6;
    static inline constexpr int FRAME_INTERVAL = 45;
    static inline constexpr int SHADOW_WIDTH = 48;
    static inline constexpr int SHADOW_HEIGHT = 30;
private:
    enum class AnimationState {
        Left=0,
        Right
    } animation_state = AnimationState::Left;
    Position position;
    double speed;
    std::optional<Animation> animation;
    inline static std::shared_ptr<Atlas> animation_atlas;
    inline static IMAGE img_shadow;
    inline static RECT limit_area;
};

#endif // ENEMY_H