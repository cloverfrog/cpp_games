#ifndef MANAGER_H
#define MANAGER_H

#include "graphics.h"
#include "utils.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"

#include <vector>
#include <optional>

class Manager {
public:
    Manager(RectArea area, double interval);
    ~Manager() = default;

    void ProcessEvent(const ExMessage& msg);
    void Update();
    void Draw();

    bool Running() { return player->Alive(); }
    int GetScore() { return score; }
private:
    void GenerateEnemy();
    void UpdateBullets();
private:
    static inline constexpr int ENEMY_INTERVAL = 1e3;
    static inline constexpr int ENEMY_MAX = 30;

    static inline constexpr int BULLET_NUM = 3;
    static inline constexpr double BULLET_RADIAL_SPEED = 0.0045;    //径向波动速度
    static inline constexpr double BULLET_BASE_RADIUS = 100.0;      //基础半径
    static inline constexpr double BULLET_AMPLITUDE = 25.0;         //径向波动幅度
    static inline constexpr double BULLET_TANGENT_SPEED = 0.0055;   //切向波动速度
private:
    RectArea area;
    std::optional<Player> player;
    std::vector<std::unique_ptr<Enemy>> enemies;
    std::vector<std::unique_ptr<Bullet>> bullet_list;

    struct Key {
        bool left;
        bool right;
        bool up;
        bool down;

        Key() : left(false), right(false), up(false), down(false) {}
        void Reset() { left = right = up = down = false; }
    } key;

    double frame_interval;

    double enemy_generate_timer = 0;
    double bullet_update_timer = 0;

    int score = 0;
};

#endif // MANAGER_H