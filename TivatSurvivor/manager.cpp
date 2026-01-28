#include "manager.h"

#include "utils.h"

#include <cmath>

Manager::Manager(RECT a, double interval) :
    area(a),
    frame_interval(interval)
{
    Player::Init(area);
    Enemy::Init(area);

    Position init_player_pos = {
        (double)(area.left + area.right)/2,
        (double)(area.top + area.bottom)/2
    };
    player.emplace(init_player_pos, 0.3);
}

void Manager::ProcessKey(const Key& key) {
    int dir_x = key.right - key.left;
    int dir_y = key.down - key.up;
    
    player->Move(dir_x, dir_y, frame_interval);
}

void Manager::Update() {
    GenerateEnemy();
    Position player_pos = player->GetPosition();

    for(auto& enemy : enemies) {
        Position enemy_pos = enemy.GetPosition();
        enemy.Move(player_pos.x - enemy_pos.x, player_pos.y - enemy_pos.y, frame_interval);
    }
}

void Manager::Draw() {
    player->Draw(frame_interval);
    for(auto& enemy : enemies) enemy.Draw(frame_interval);
}

void Manager::GenerateEnemy() {
    enemy_generate_timer += frame_interval;
    if(enemies.size() < ENEMY_MAX && enemy_generate_timer > ENEMY_INTERVAL) {
        RECT limit = Enemy::GetLimitArea();
        int width = limit.right - limit.left;
        int height = limit.bottom - limit.top;
        int perimeter = 2 * (width + height);

        int pos = Random::Instance().Int(0, perimeter - 1);

        Position p;
        p.x = limit.left + std::max(0, std::min(std::min(pos, width), perimeter - height - pos));
        p.y = limit.top + std::max(0, std::min(std::min(pos - width, height), perimeter - pos));

        enemies.emplace_back(p, 0.06 + Random::Instance().Double(-0.006, 0.006));

        enemy_generate_timer -= ENEMY_INTERVAL;
    }
}