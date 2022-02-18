#include "Enemy.h"
#include <random>
#include <ncurses.h>
#include "constants.h"

/**
 * Constructs the Enemy class to focus on a specific player
 * @param player - the player on the floor
 */
Enemy::Enemy(const Player & player) {
    _x = 0;
    _y = 0;
    _player = player;
    _alive = true;
    _enemy_type = rand() % 2;
}

/**
 * Default constructor for the Enemy class
 */
Enemy::Enemy() {
    _x = 0;
    _y = 0;
    _alive = true;
    _enemy_type = rand() % 2;
}


/**
 * Places an enemy
 * @param player - the player object that is on the board
 */
void Enemy::enemy_placement(const Player & player) {
    _y = (rand() % (PLACEMENT_Y)) + PLACEMENT_Y_CONTROL;
    _x = (rand() % (PLACEMENT_X)) + PLACEMENT_X_CONTROL;

    while(_y == player.get_y() && _x == player.get_x()) {
        _y = (rand() % (PLACEMENT_Y)) + PLACEMENT_Y_CONTROL;
        _x = (rand() % (PLACEMENT_X)) + PLACEMENT_X_CONTROL;
    }

    init_pair(ENEMY_COLOR_PAIR, COLOR_BLUE, COLOR_BLUE);
    attron(COLOR_PAIR(ENEMY_COLOR_PAIR));

    mvprintw(_y, _x, "%s", " ");

    attroff(COLOR_PAIR(ENEMY_COLOR_PAIR));
}

/**
 * Moves an enemy
 * @param player - the player object that is on the board
 */
void Enemy::enemy_movement(const Player & player) {
    _player = player;
    size_t old_x = _x;
    size_t old_y = _y;

    enemy_dead(old_x, old_y);

    if (_alive) {
        enemy_type_movement();
        refresh();

        init_pair(ENEMY_COLOR_PAIR, COLOR_BLUE, COLOR_BLUE);
        attron(COLOR_PAIR(ENEMY_COLOR_PAIR));

        mvprintw(_y, _x, "%s", " ");

        attroff(COLOR_PAIR(ENEMY_COLOR_PAIR));

        init_pair(BACKGROUND_COLOR_PAIR, COLOR_WHITE, COLOR_WHITE);
        attron(COLOR_PAIR(BACKGROUND_COLOR_PAIR));

        if (old_x != _x || old_y != _y)
            mvprintw(old_y, old_x, "%s", " ");

        attroff(COLOR_PAIR(BACKGROUND_COLOR_PAIR));
    }
}

/**
 * If the enemy is dead, moves it off screen
 * @param old_x - the player's previous x coordinate
 * @param old_y - the player's previous y coordinate
 */
void Enemy::enemy_dead(const size_t old_x, const size_t old_y) {
    if (!_alive) {
        _y = 0;
        _x = 0;

        init_pair(BACKGROUND_COLOR_PAIR, COLOR_WHITE, COLOR_WHITE);
        attron(COLOR_PAIR(BACKGROUND_COLOR_PAIR));

        if (old_y != 0 && old_x != 0)
            mvprintw(old_y, old_x, "%s", " ");

        attroff(COLOR_PAIR(BACKGROUND_COLOR_PAIR));
    }
}

/**
 * Changes the enemy's x and y in a particular order: if the enemy is
 * type 0, prioritizes y movement; type 1 prioritizes x
 */
void Enemy::enemy_type_movement() {
    if (_enemy_type == 0) {

        if (_y < _player.get_y())
            _y += 1;
        else if (_y > _player.get_y())
            _y -= 1;

        else if (_x < _player.get_x())
            _x += 1;
        else if (_x > _player.get_x())
            _x -= 1;
    }
     else if (_enemy_type == 1) {

        if (_x < _player.get_x())
            _x += 1;
        else if (_x > _player.get_x())
            _x -= 1;

        else if (_y < _player.get_y())
            _y += 1;
        else if (_y > _player.get_y())
            _y -= 1;
    }
}

/**
 * Returns the enemy's x position
 * @return the x position of the enemy
 */
size_t Enemy::get_x() const {
    return _x;
}

/**
 * Returns the enemy's y position
 * @return the y position of the enemy
 */
size_t Enemy::get_y() const {
    return _y;
}

/**
 * Kills the enemy
 */
void Enemy::remove_health() {
    _alive = false;
}

/**
 * Revives the enemy
 */
void Enemy::add_health() {
    _alive = true;
}

/**
 * Returns whether the enemy is alive or not
 * @return _alive - true if the enemy is alive
 */
bool Enemy::get_alive() const {
    return _alive;
}
