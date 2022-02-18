#include "Game_Player.h"

/**
 * Plays one level of the game
 * @param window - the window the game stats are seen in
 * @param player - the player
 * @param all_obstacles - all the obstacles
 * @param all_enemies - all the enemies
 * @param all_collectibles - all the collectibles
 */
void Game_Player::play_level(Window_Generator & window,
                             Player & player,
                             Obstacle_Manager & all_obstacles,
                             Enemy_Manager & all_enemies,
                             Collectible_Manager & all_collectibles) const {

    while (all_enemies.count_alive_enemies() > 0
       && (all_enemies.enemy_not_touched_player(player)
       && all_obstacles.obstacle_not_touched_player(player))) {

        if (player.player_action())
            window.text_box();

        refresh();
        all_enemies.attack_hit(player);
        refresh();

        all_obstacles.obstacle_enemy_attack_interaction(player, all_enemies);

        for (size_t enemy_index = 0; enemy_index < all_enemies.get_num_enemies();
                                                                 enemy_index++) {
            all_enemies.get_enemy_list()[enemy_index].enemy_movement(player);
        }

        all_obstacles.obstacle_enemy_attack_interaction(player, all_enemies);
        window.enemy_obstacle_counter(all_enemies, all_obstacles);

        all_collectibles.collectible_interaction(player, all_enemies, window);
    }
}

/**
 * Plays the entire game
 * @param window - the window the game stats are seen in
 * @param player - the player
 * @param all_obstacles - all the obstacles
 * @param all_enemies - all the enemies
 * @param all_collectibles - all the collectibles
 */
void Game_Player::play_game(Window_Generator & window,
                            Player & player,
                            Obstacle_Manager & all_obstacles,
                            Enemy_Manager & all_enemies,
                            Collectible_Manager & all_collectibles) const {

    while (all_enemies.get_num_enemies() < STARTING_ENEMY_NUMBER +
                                                            ENEMY_NUMBER_CAP) {

        play_level(window, player, all_obstacles, all_enemies, all_collectibles);

        if (!all_enemies.enemy_not_touched_player(player) ||
            !all_obstacles.obstacle_not_touched_player(player)) {
            break;
        }

        player.attack_cleanup();
        all_enemies.add_enemy(Enemy());

        for (size_t index = 0; index < all_enemies.get_num_enemies(); index++) {
             all_enemies.get_enemy_list()[index].enemy_placement(player);
             all_enemies.get_enemy_list()[index].add_health();
        }

        window.enemy_obstacle_counter(all_enemies, all_obstacles);
    }
    window.game_over(all_enemies);
}
