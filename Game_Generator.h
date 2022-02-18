#include "Room_Generator.h"
#include "Window_Generator.h"
#include "Obstacle_Manager.h"
#include "Enemy_Manager.h"
#include "Collectible_Manager.h"
#include "Player.h"

#ifndef GAME_GENERATOR_H
#define GAME_GENERATOR_H

class Game_Generator {
public:
    void generate_room(const Room_Generator & room) const;
    void generate_initial_window(Window_Generator & window) const;
    void generate_player(Player & player) const;
    void generate_obstacles(Obstacle_Manager & all_obstacles, Player & player)
                                                                          const;
    void generate_enemies(Enemy_Manager & all_enemies, Player & player) const;
    
    void generate_collectibles(Collectible_Manager & all_collectibles,
                                   Player & player, Enemy_Manager & all_enemies,
                                        Obstacle_Manager & all_obstacles) const;

    void generate_latter_window(Window_Generator & window,
           Enemy_Manager & all_enemies, Obstacle_Manager & all_obstacles) const;

    void generate_game(Room_Generator & room, Window_Generator & window,
                              Player & player, Obstacle_Manager & all_obstacles,
                              Enemy_Manager & all_enemies,
                              Collectible_Manager & all_collectibles) const;
};

#endif //GAME_GENERATOR_H
