#ifndef PLAYER_H
#define PLAYER_H

#include "animation.h"
#include "utils.h"

#include <graphics.h>
#include <optional>

class Player {
public:
    Player(Position pos, double speed);
    ~Player() = default;

    void Move(int dir_x, int dir_y, double delta);
    void Draw(double delta);

    void ResetLimitArea(RectArea limit) { 
        limit_area = {
            limit.left + FRAME_WIDTH / 2,
            limit.top + FRAME_HEIGHT / 2,
            limit.right - FRAME_WIDTH / 2,
            limit.bottom - FRAME_HEIGHT / 2
        };
    }

    Position GetPosition() { return position; }
    RectArea GetCollisionBox() { return {position.x - COLLISION_WIDTH / 2, position.y - COLLISION_HEIGHT / 2, position.x + COLLISION_WIDTH / 2, position.y + COLLISION_HEIGHT / 2}; }

    static void Init(RectArea limit);
    static RectArea GetLimitArea() { return limit_area; }
    static SIZE GetSize() { return {FRAME_WIDTH, FRAME_HEIGHT}; }

    void Hurt() { health = health > 0 ? health - 1 : 0; }
    bool Alive() { return health > 0; }
private:
    static inline constexpr int FRAME_WIDTH = 80;
    static inline constexpr int FRAME_HEIGHT = 80;
    static inline constexpr int FRAME_NUM = 6;
    static inline constexpr int FRAME_INTERVAL = 45;
    static inline constexpr int SHADOW_WIDTH = 32;
    static inline constexpr int SHADOW_HEIGHT = 20;

    static inline constexpr double COLLISION_WIDTH = 40;
    static inline constexpr double COLLISION_HEIGHT = 50;
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
    inline static RectArea limit_area;

    int health = 1;
};

#endif // PLAYER_H