#include "manager.h"

#include "utils.h"

#include <cmath>

Manager::Manager(RECT a):
    area(a) 
{
    Player::Init(area);
    Enemy::Init(area);

    Position init_player_pos = {
        (double)(area.left + area.right)/2,
        (double)(area.top + area.bottom)/2
    };
    player.emplace(init_player_pos, 10.);
}

void Manager::ProcessKey(const Key& key) {
    int dir_x = key.right - key.left;
    int dir_y = key.down - key.up;
    
    player->Move(dir_x, dir_y);
}

void Manager::Update() {
    GenerateEnemy();
    Position player_pos = player->GetPosition();

    for(auto& enemy : enemies) {
        Position enemy_pos = enemy.GetPosition();
        enemy.Move(player_pos.x - enemy_pos.x, player_pos.y - enemy_pos.y);
    }
}

void Manager::Draw() {
    player->Draw();
    for(auto& enemy : enemies) enemy.Draw();
}

void Manager::GenerateEnemy() {
    DWORD new_tick = GetTickCount() / ENEMY_INTERVAL;
    if(enemies.size() < ENEMY_MAX && new_tick > tick) {
        RECT limit = Enemy::GetLimitArea();
        int width = limit.right - limit.left;
        int height = limit.bottom - limit.top;
        int perimeter = 2 * (width + height);

        int pos = Random::Instance().Int(0, perimeter - 1);

        Position p;
        p.x = limit.left + std::max(0, std::min(std::min(pos, width), perimeter - height - pos));
        p.y = limit.top + std::max(0, std::min(std::min(pos - width, height), perimeter - pos));

        enemies.emplace_back(p, 2. + Random::Instance().Double(-0.2, 0.2));
        tick = new_tick;
    }
}