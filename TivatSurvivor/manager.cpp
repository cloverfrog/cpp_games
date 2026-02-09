#include "manager.h"

#include <cmath>
#include <numbers>

Manager::Manager(RectArea a, double interval) :
    area(a),
    frame_interval(interval)
{
    Player::Init(area);
    Enemy::Init(area);

    player.emplace(area.GetCenter(), 0.3);

    for(int i = 0; i < BULLET_NUM; ++i) bullet_list.emplace_back(std::make_unique<Bullet>());
}

void Manager::ProcessKey(const Key& key) {
    int dir_x = key.right - key.left;
    int dir_y = key.down - key.up;
    
    player->Move(dir_x, dir_y, frame_interval);
}

bool Manager::Update() {
    GenerateEnemy();
    Position player_pos = player->GetPosition();

    UpdateBullets();

    //敌人移动以及与子弹的碰撞
    for(auto& enemy : enemies) {
        Position enemy_pos = enemy->GetPosition();
        enemy->Move(player_pos.x - enemy_pos.x, player_pos.y - enemy_pos.y, frame_interval);

        for(auto& bullet : bullet_list) {
            if (enemy->GetCollisionBox().IsCollision(bullet->GetPosition())) {
                enemy->Hurt();
                break;
            }
        }
    }

    //清除死亡的敌人
    for(size_t i = 0; i < enemies.size();) {
        if(!enemies[i]->Alive()) {
            std::swap(enemies[i], enemies.back());
            enemies.pop_back();
        }
        else i++;
    }

    //玩家与敌人的碰撞
    for(auto& enemy : enemies) {
        if (enemy->GetCollisionBox().IsCollision(player->GetCollisionBox())) player->Hurt();
    }

    return player->Alive();
}

void Manager::Draw() {
    player->Draw(frame_interval);
    for(auto& bullet : bullet_list) {
        bullet->Draw();
    }
    for(auto& enemy : enemies) enemy->Draw(frame_interval);
}

void Manager::GenerateEnemy() {
    enemy_generate_timer += frame_interval;
    if(enemies.size() < ENEMY_MAX && enemy_generate_timer > ENEMY_INTERVAL) {
        RectArea limit = Enemy::GetLimitArea();
        double width = limit.right - limit.left;
        double height = limit.bottom - limit.top;
        double perimeter = 2 * (width + height);

        double pos = Random::Instance().Double(0., perimeter - 1.);

        Position p;
        p.x = limit.left + std::max(0., std::min(std::min(pos, width), perimeter - height - pos));
        p.y = limit.top + std::max(0., std::min(std::min(pos - width, height), perimeter - pos));

        enemies.emplace_back(std::make_unique<Enemy>(p, 0.06 + Random::Instance().Double(-0.006, 0.006)));

        enemy_generate_timer -= ENEMY_INTERVAL;
    }
}

void Manager::UpdateBullets() {
    bullet_update_timer += frame_interval;

    double radian_interval = 2. * std::numbers::pi / static_cast<double>(BULLET_NUM);
    Position player_pos = player->GetPosition();

    double radius = BULLET_BASE_RADIUS + BULLET_AMPLITUDE * std::sin(bullet_update_timer * BULLET_RADIAL_SPEED);

    for (int i = 0; i < BULLET_NUM; ++i) {
        double radian = bullet_update_timer * BULLET_TANGENT_SPEED + i * radian_interval;
        bullet_list[i]->SetPosition({player_pos.x + radius * std::cos(radian), player_pos.y + radius * std::sin(radian)});
    }
}