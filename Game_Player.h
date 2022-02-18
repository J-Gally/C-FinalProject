#include "Game_Generator.h"

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

class Game_Player {
public:
    void play_level(Window_Generator & window, Player & player,
                   Obstacle_Manager & all_obstacles,
                   Enemy_Manager & all_enemies,
                   Collectible_Manager & all_collectibles) const;
                   
    void play_game(Window_Generator & window, Player & player,
                   Obstacle_Manager & all_obstacles,
                   Enemy_Manager & all_enemies,
                   Collectible_Manager & all_collectibles) const;
};

#endif //GAME_PLAYER_H
