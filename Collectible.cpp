#include "Collectible.h"
#include <random>
#include <ncurses.h>
#include "constants.h"

/**
 * Constructs the Collectible class
 */
Collectible::Collectible() {
    _y = 0;
    _x = 0;
}

/**
 * Places the collectibles on the floor
 * @player - the player
 * @param all_enemies - all of the enemies on the floor
 * @param all_obstacles - all of the obstacles on the floor
 */
void Collectible::collectible_placement(const Player & player,
              Enemy_Manager & all_enemies, Obstacle_Manager & all_obstacles) {

    _y = (rand() % (PLACEMENT_Y)) + PLACEMENT_Y_CONTROL;
    _x = (rand() % (PLACEMENT_X)) + PLACEMENT_X_CONTROL;

    placement_control(player, all_enemies, all_obstacles);

    init_pair(COLLECTIBLE_COLOR_PAIR, COLOR_MAGENTA, COLOR_YELLOW);
    attron(COLOR_PAIR(COLLECTIBLE_COLOR_PAIR));

    mvprintw(_y, _x, "%s", "?");

    attroff(COLOR_PAIR(COLLECTIBLE_COLOR_PAIR));
}

/**
 * Ensures that the collectibles are not placed on top of player, enemies,
 * Or obstacles
 * @player - the player
 * @param all_enemies - all of the enemies on the floor
 * @param all_obstacles - all of the obstacles on the floor
 */
void Collectible::placement_control(const Player & player,
              Enemy_Manager & all_enemies, Obstacle_Manager & all_obstacles) {

    while (_y == player.get_y() && _x == player.get_x()) {
        _y = (rand() % (PLACEMENT_Y)) + PLACEMENT_Y_CONTROL;
        _x = (rand() % (PLACEMENT_X)) + PLACEMENT_X_CONTROL;
    }

    for (size_t index = 0; index < all_enemies.get_num_enemies(); index++) {
        while (_x == all_enemies.get_enemy_list()[index].get_x() &&
               _y == all_enemies.get_enemy_list()[index].get_y()) {
            _y = (rand() % (PLACEMENT_Y)) + PLACEMENT_Y_CONTROL;
            _x = (rand() % (PLACEMENT_X)) + PLACEMENT_X_CONTROL;
        }
    }

    for (size_t index = 0; index < all_obstacles.get_num_obstacles(); index++) {
        while (_x == all_obstacles.get_obstacle_list()[index].get_obstacle_x() &&
               _y == all_obstacles.get_obstacle_list()[index].get_obstacle_y()) {
            _y = (rand() % (PLACEMENT_Y)) + PLACEMENT_Y_CONTROL;
            _x = (rand() % (PLACEMENT_X)) + PLACEMENT_X_CONTROL;
        }
    }
}

/**
 * Updates the collectible counter in the window if a player touches it
 * @window - the window the game is seen on
 */
void Collectible::player_interaction(Window_Generator & window) {
    window.collectible_and_point_counter();
    _y = 0;
    _x = 0;
}

/**
 * Invalidates the collectible if an enemy comes into contact with it
 */
void Collectible::enemy_interaction() {
    _y = 0;
    _x = 0;
}

/**
 * Checks whether the collectible has encountered an enemy or a player
 * @player - the player
 * @param all_enemies - all of the enemies on the floor
 * @param window - the window the game is seen on
 */
void Collectible::entity_interaction(const Player & player,
                      Enemy_Manager & all_enemies, Window_Generator & window) {

    if (_x == player.get_x() && _y == player.get_y()) {
        player_interaction(window);
    }

    for (size_t index = 0; index < all_enemies.get_num_enemies(); index++) {
        if (_x == all_enemies.get_enemy_list()[index].get_x() &&
               _y == all_enemies.get_enemy_list()[index].get_y()) {
            enemy_interaction();
        }
    }
}
