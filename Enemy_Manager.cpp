#include "Enemy_Manager.h"

/**
 * Constructs the Enemy_Manager class
 */
Enemy_Manager::Enemy_Manager() {
    _num_enemies = 0;
    _dead_enemies = 0;
}

/**
 * Checks whether a player's attack has hit the enemy
 * @param player - the player
 */
void Enemy_Manager::attack_hit(const Player & player) {
    for (size_t index = 0; index < get_num_enemies(); index++) {

        if ((player.get_attack_x() == _enemy_list[index].get_x())
         && (player.get_attack_y() == _enemy_list[index].get_y())
         && _enemy_list[index].get_alive()) {

             _enemy_list[index].remove_health();
             _dead_enemies += 1;
        }
    }
}

/**
 * Checks whether an enemy has touched the player
 * @param player - the player
 * @return true if all the enemies are not currently touching the player
 */
bool Enemy_Manager::enemy_not_touched_player(const Player & player) const {
    for (size_t index = 0; index < _num_enemies; index++) {
        if ((player.get_x() == _enemy_list[index].get_x()) &&
            (player.get_y() == _enemy_list[index].get_y()))
            return false;
    }
    return true;
}

/**
 * Counts the number of alive enemies
 * @return counter - the number of alive enemies
 */
size_t Enemy_Manager::count_alive_enemies() const {
    size_t counter = 0;

    for (size_t index = 0; index < _num_enemies; index++) {
        if (_enemy_list[index].get_alive())
            counter++;
    }
    return counter;
}

/**
 * Adds an enemy to the array of Enemies
 * @param enemy - an Enemy object
 */
void Enemy_Manager::add_enemy(const Enemy & enemy) {
    _enemy_list[_num_enemies++] = enemy;
}

/**
 * Returns an array of enemies
 * @param _enemy_list - the list of Enemies
 */
Enemy * Enemy_Manager::get_enemy_list() {
    return _enemy_list;
}

/**
 * Returns the number of enemies
 * @return _num_enemies - the number of enemies
 */
size_t Enemy_Manager::get_num_enemies() const {
    return _num_enemies;
}

/**
 * Returns the number of dead enemies
 * @return _dead_enemies - the number of dead enemies
 */
size_t Enemy_Manager::get_dead_enemies() const {
    return _dead_enemies;
}
