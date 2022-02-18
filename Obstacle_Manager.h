#include "Player.h"
#include "Enemy_Manager.h"
#include "Obstacle.h"
#include <cstddef>
#include "constants.h"

#ifndef OBSTACLE_MANAGER_H
#define OBSTACLE_MANAGER_H

class Obstacle_Manager {
public:
    Obstacle_Manager();
    bool obstacle_not_touched_player(const Player & player) const;
    void obstacle_enemy_attack_interaction(const Player & player,
                                                   Enemy_Manager & all_enemies);
    size_t count_valid_obstacles() const;
    void remove_obstacle(const size_t index);
    void add_obstacle(const Obstacle & obstacle);
    Obstacle * get_obstacle_list();
    size_t get_num_obstacles() const;
private:
    size_t _num_obstacles;
    Obstacle _obstacle_list[MAX_OBSTACLES];
};

#endif //OBSTACLE_MANAGER_H
