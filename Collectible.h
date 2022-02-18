#include "Player.h"
#include "Obstacle_Manager.h"
#include "Enemy_Manager.h"
#include "Window_Generator.h"

#include <cstddef>

#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H

class Collectible {
public:
    Collectible();
    void collectible_placement(const Player & player, Enemy_Manager & all_enemies,
                               Obstacle_Manager & all_obstacles);

    void entity_interaction(const Player & player, Enemy_Manager & all_enemies,
                            Window_Generator & window);
private:
    void placement_control(const Player & player, Enemy_Manager & all_enemies,
                                              Obstacle_Manager & all_obstacles);
    void player_interaction(Window_Generator & window);
    void enemy_interaction();
    size_t _x;
    size_t _y;
};

#endif //COLLECTIBLE_H
