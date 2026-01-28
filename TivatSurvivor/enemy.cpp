#include "enemy.h"

#include <vector>
#include <cmath>

Enemy::Enemy(Position pos, double speed) : 
    position(pos), 
    speed(speed)
{
    animation.emplace(animation_atlas);
}

void Enemy::Move(int dir_x, int dir_y, double delta) {
    //调整角色动画方向
    if(dir_x > 0) animation_state = AnimationState::Right;
    else if(dir_x < 0) animation_state = AnimationState::Left;

    //移动
    double len_dir = sqrt(dir_x * dir_x + dir_y * dir_y);
    if (len_dir != 0) {
        position.x += dir_x / len_dir * speed * delta;
        position.y += dir_y / len_dir * speed * delta;
    }

    //限制区域
    if (position.x < limit_area.left) position.x = limit_area.left;
    if (position.x > limit_area.right) position.x = limit_area.right;
    if (position.y < limit_area.top) position.y = limit_area.top;
    if (position.y > limit_area.bottom) position.y = limit_area.bottom;
}

void Enemy::Draw(double delta) {
    //阴影
    int shadow_x = position.x - SHADOW_WIDTH / 2;
    int shadow_y = position.y + (FRAME_HEIGHT - SHADOW_HEIGHT) / 2 - 15;
    putimage_alpha(shadow_x, shadow_y, &img_shadow);

    //角色动画
    animation->Play(std::round(position.x), std::round(position.y), (size_t)animation_state, delta);
}

void Enemy::Init(RECT limit) {
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