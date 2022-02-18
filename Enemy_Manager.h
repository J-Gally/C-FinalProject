#include "Player.h"
#include "Enemy.h"
#include <cstddef>
#include "constants.h"

#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

class Enemy_Manager {
public:
    Enemy_Manager();
    void attack_hit(const Player & player);
    bool enemy_not_touched_player(const Player & player) const;
    size_t count_alive_enemies() const;
    void add_enemy(const Enemy & enemy);
    Enemy * get_enemy_list();
    size_t get_num_enemies() const;
    size_t get_dead_enemies() const;
private:
    size_t _num_enemies;
    size_t _dead_enemies;
    Enemy _enemy_list[STARTING_ENEMY_NUMBER + ENEMY_NUMBER_CAP];
};

#endif //ENEMY_MANAGER_H
