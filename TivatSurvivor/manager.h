#ifndef MANAGER_H
#define MANAGER_H

#include "graphics.h"
#include "player.h"
#include "enemy.h"

#include <vector>
#include <optional>

struct Key {
    bool left;
    bool right;
    bool up;
    bool down;
};

class Manager {
public:
    Manager(RECT area);
    ~Manager() = default;

    void ProcessKey(const Key& key);
    void Update();
    void Draw();
private:
    void GenerateEnemy();
private:
    static inline constexpr int ENEMY_INTERVAL = 1e3;
    static inline constexpr int ENEMY_MAX = 20;
private:
    RECT area;
    std::optional<Player> player;
    std::vector<Enemy> enemies;

    DWORD tick = 0;
};

#endif // MANAGER_H