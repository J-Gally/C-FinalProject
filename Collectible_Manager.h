#include "Player.h"
#include "Enemy_Manager.h"
#include "Window_Generator.h"
#include "Collectible.h"

#include <cstddef>
#include "constants.h"

#ifndef COLLECTIBLE_MANAGER_H
#define COLLECTIBLE_MANAGER_H

class Collectible_Manager {
public:
    Collectible_Manager();
    void collectible_interaction(const Player & player,
                          Enemy_Manager all_enemies, Window_Generator & window);
                          
    void add_collectible(const Collectible & collectible);
    Collectible * get_collectible_list();
    size_t get_num_obstacles() const;
private:
    size_t _num_collectibles;
    Collectible _collectible_list[MAX_COLLECTIBLE_NUMBER];
};

#endif //COLLECTIBLE_MANAGER_H
