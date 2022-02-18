#include "Obstacle.h"
#include <random>
#include <ncurses.h>
#include "constants.h"

/**
 * Constructs the Obstacle class
 */
Obstacle::Obstacle() {
    _x = 0;
    _y = 0;
    _valid_obstacle = true;
}

/**
 * Places the obstacle
 * @param player - the player object that is on the board
 */
void Obstacle::obstacle_placement(const Player & player) {
    _y = (rand() % (PLACEMENT_Y)) + PLACEMENT_Y_CONTROL;
    _x = (rand() % (PLACEMENT_X)) + PLACEMENT_X_CONTROL;

    while (_y == player.get_y() && _x == player.get_x()) {
        _y = (rand() % (PLACEMENT_Y)) + PLACEMENT_Y_CONTROL;
        _x = (rand() % (PLACEMENT_X)) + PLACEMENT_X_CONTROL;
    }

    init_pair(OBSTACLE_COLOR_PAIR, COLOR_BLACK, COLOR_BLACK);
    attron(COLOR_PAIR(OBSTACLE_COLOR_PAIR));

    mvprintw(_y, _x, "%s", " ");

    attroff(COLOR_PAIR(OBSTACLE_COLOR_PAIR));
}

/**
 * Invalidates the obstacle
 */
void Obstacle::invalidate() {
    _valid_obstacle = false;
}

/**
 * Validates the obstacle
 */
void Obstacle::validate() {
    _valid_obstacle = true;
}

/**
 * Returns the obstacle's x position
 * @return the x position of the obstacle
 */
size_t Obstacle::get_obstacle_x() const {
    return _x;
}

/**
 * Returns the obstacle's y position
 * @return the y position of the obstacle
 */
size_t Obstacle::get_obstacle_y() const {
    return _y;
}

/**
 * Returns whether or not the obstacle is valid
 * @return true if the obstacle is valid
 */
bool Obstacle::get_valid_obstacle() const {
    return _valid_obstacle;
}
