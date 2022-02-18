#include <cstddef>
#include "Player.h"

#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
public:
    Enemy(const Player & player);
    Enemy();
    void enemy_placement(const Player & player);
    void enemy_movement(const Player & player);
    size_t get_x() const;
    size_t get_y() const;
    void remove_health();
    void add_health();
    bool get_alive() const;

private:
    void enemy_type_movement();
    void enemy_dead(const size_t old_x, const size_t old_y);
    size_t _x;
    size_t _y;
    Player _player;
    bool _alive;
    unsigned short _enemy_type;
};

#endif //ENEMY_H
