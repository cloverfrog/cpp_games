#include "enemy.h"

#include <vector>
#include <cmath>

Enemy::Enemy(Position pos, double speed) : 
    position(pos), 
    speed(speed)
{
    animation.emplace(animation_atlas);
}

void Enemy::Move(Vec2 dir, double delta) {
    //调整角色动画方向
    if(dir.x > 0) animation_state = AnimationState::Right;
    else if(dir.x < 0) animation_state = AnimationState::Left;

    //移动
    dir.Normalize();
    position += dir * speed * delta;

    //限制区域
    position.Restrict(limit_area);
}

void Enemy::Draw(double delta) {
    //阴影
    int shadow_x = position.x - SHADOW_WIDTH / 2;
    int shadow_y = position.y + (FRAME_HEIGHT - SHADOW_HEIGHT) / 2 - 15;
    putimage_alpha(shadow_x, shadow_y, &img_shadow);

    //角色动画
    animation->Play(std::round(position.x), std::round(position.y), (size_t)animation_state, delta);

    //碰撞箱测试
    rectangle(position.x - COLLISION_WIDTH / 2, position.y - COLLISION_HEIGHT / 2, position.x + COLLISION_WIDTH / 2, position.y + COLLISION_HEIGHT / 2);
}

void Enemy::Init(RectArea limit) {
    limit_area = {
        limit.left - FRAME_WIDTH / 2,
        limit.top - FRAME_HEIGHT / 2,
        limit.right + FRAME_WIDTH / 2,
        limit.bottom + FRAME_HEIGHT / 2
    };

    std::vector<AnimationConfig> animation_config = {
        { "img/enemy_left_", FRAME_WIDTH, FRAME_HEIGHT, FRAME_NUM, FRAME_INTERVAL },
        { "img/enemy_right_", FRAME_WIDTH, FRAME_HEIGHT, FRAME_NUM, FRAME_INTERVAL }
    };
    animation_atlas = std::make_shared<Atlas>(animation_config);

    loadimage_safe(&img_shadow, _T("img/shadow_enemy.png"));
}