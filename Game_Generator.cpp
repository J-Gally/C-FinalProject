#include "Game_Generator.h"
#include "constants.h"

/**
 * Generates the Room
 * @param room - the room that the game is played in
 */
void Game_Generator::generate_room(const Room_Generator & room) const {
    room.background_generator();
    room.border_generator();
}

/**
 * Generates the tutorial window
 * @param window - the window that the game stats are seen in
 */
void Game_Generator::generate_initial_window(Window_Generator & window) const {
    window.generate_starting_window();
}

/**
 * Generates the Player
 * @param player - the player
 */
void Game_Generator::generate_player(Player & player) const {
    player.player_placement();
}

/**
 * Generates all the obstacles in the room
 * @param all_obstacles - all the obstacles
 * @param player - the player
 */
void Game_Generator::generate_obstacles(Obstacle_Manager & all_obstacles,
                                        Player & player) const {
    for (size_t obstacle = 0; obstacle < MAX_OBSTACLES; obstacle++) {
        all_obstacles.add_obstacle(Obstacle());
        all_obstacles.get_obstacle_list()[obstacle].obstacle_placement(player);
    }
}

/**
 * Generates all the enemies in the room
 * @param all_enemies - all the enemies
 * @param player - the player
 */
void Game_Generator::generate_enemies(Enemy_Manager & all_enemies,
                                      Player & player) const {
    for (size_t enemy = 0; enemy< STARTING_ENEMY_NUMBER; enemy++) {
        all_enemies.add_enemy(Enemy(player));
        all_enemies.get_enemy_list()[enemy].enemy_placement(player);
    }
}

/**
 * Generates all the collectibles in the room
 * @param all_collectibles - all the collectibles
 * @param player - the player
 * @param all_enemies - all the enemies
 * @param all_obstacles - all the obstacles
 */
void Game_Generator::generate_collectibles(Collectible_Manager & all_collectibles,
                                     Player & player, Enemy_Manager & all_enemies,
                                     Obstacle_Manager & all_obstacles) const {

    for (size_t collectible = 0; collectible < MAX_COLLECTIBLE_NUMBER;
                                                                collectible++) {
        all_collectibles.add_collectible(Collectible());

        all_collectibles.get_collectible_list()[collectible].
        collectible_placement(player, all_enemies, all_obstacles);
    }
}

/**
 * Generates the text boxes containing the stats
 * @param window - the window the game stats are seen in
 * @param all_enemies - all the enemies
 * @param all_obstacles - all the obstacles
 */
void Game_Generator::generate_latter_window(Window_Generator & window,
         Enemy_Manager & all_enemies, Obstacle_Manager & all_obstacles) const {

    window.enemy_obstacle_counter(all_enemies, all_obstacles);
    window.text_box();
    window.collectible_and_point_generator();
}

/**
 * Generates the game
 * @param room - the room the game is played in
 * @param window - the window the game stats are seen in
 * @param player - the player
 * @param all_obstacles - all the obstacles
 * @param all_enemies - all the enemies
 * @param all_collectibles - all the collectibles
 */
void Game_Generator::generate_game(Room_Generator & room,
                                   Window_Generator & window,
                                   Player & player,
                                   Obstacle_Manager & all_obstacles,
                                   Enemy_Manager & all_enemies,
                                   Collectible_Manager & all_collectibles) const {

    generate_room(room);
    generate_initial_window(window);
    generate_player(player);
    generate_obstacles(all_obstacles, player);
    generate_enemies(all_enemies, player);
    generate_collectibles(all_collectibles, player, all_enemies, all_obstacles);
    generate_latter_window(window, all_enemies, all_obstacles);

    refresh();
}
