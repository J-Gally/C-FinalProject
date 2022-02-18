#include "Obstacle_Manager.h"

/**
 * Constructs the Obstacle_Manager class
 */
Obstacle_Manager::Obstacle_Manager() {
    _num_obstacles = 0;
}

/**
 * Checks whether an obstacle has touched the player
 * @param player - the player
 * @return true if all the obstacles are not currently touching the player
 */
bool Obstacle_Manager::obstacle_not_touched_player(const Player & player) const {
    for (size_t index = 0; index < _num_obstacles; index++) {
        if (_obstacle_list[index].get_obstacle_x() == player.get_x() &&
            _obstacle_list[index].get_obstacle_y() == player.get_y() &&
            _obstacle_list[index].get_valid_obstacle())
            return false;
    }
    return true;
}

/**
 * Checks whether an enemy or a player's attack has touched an obstacle,
 * if so, invalidates the obstacle
 * @param player - the player on the floor
 * @param all_enemies - all of the enemies on the floor
 * @return true if all the enemies are not currently touching the player
 */
void Obstacle_Manager::obstacle_enemy_attack_interaction(const Player & player,
                                                  Enemy_Manager & all_enemies) {
    for (size_t enemy = 0; enemy < all_enemies.get_num_enemies(); enemy++) {
        for (size_t index = 0; index < _num_obstacles; index++) {

            if (_obstacle_list[index].get_obstacle_x() ==
                                  all_enemies.get_enemy_list()[enemy].get_x() &&
                _obstacle_list[index].get_obstacle_y() ==
                                  all_enemies.get_enemy_list()[enemy].get_y())
                remove_obstacle(index);
        }
    }

    for (size_t index = 0; index < _num_obstacles; index++) {
        if (_obstacle_list[index].get_obstacle_x() == player.get_attack_x() &&
            _obstacle_list[index].get_obstacle_y() == player.get_attack_y())
            remove_obstacle(index);
    }
}

/**
 * Counts the number of valid obstacles
 * @return counter - the number of valid obstacles
 */
size_t Obstacle_Manager::count_valid_obstacles() const {
    size_t counter = 0;

    for (size_t index = 0; index < _num_obstacles; index++) {
        if (_obstacle_list[index].get_valid_obstacle())
            counter++;
    }

    return counter;
}

/**
 * Invalidates an obstacle in the obstacle array
 * @param index - the index of the obstacle array to invalidate
 */
void Obstacle_Manager::remove_obstacle(const size_t index) {
    _obstacle_list[index].invalidate();
}

/**
 * Adds an obstacle to the array of obstacles
 * @param Obstacle - an obstacle
 */
void Obstacle_Manager::add_obstacle(const Obstacle & obstacle) {
    _obstacle_list[_num_obstacles++] = obstacle;
}

/**
 * Returns the array of all obstacles
 * @return _obstacle_list - the list of all obstacles
 */
Obstacle * Obstacle_Manager::get_obstacle_list() {
    return _obstacle_list;
}

/**
 * Returns the number of obstacles
 * @return _num_obstacles - the number of obstacles
 */
size_t Obstacle_Manager::get_num_obstacles() const {
    return _num_obstacles;
}
