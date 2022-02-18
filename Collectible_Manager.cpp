#include "Collectible_Manager.h"

/**
 * Constructs the Collectible_Manager class
 */
Collectible_Manager::Collectible_Manager() {
    _num_collectibles = 0;
}

/**
 * Manages the interactions of all the collectibles
 * @player - the player
 * @param all_enemies - all of the enemies on the floor
 * @param window - the window the game is seen on
 */
void Collectible_Manager::collectible_interaction(const Player & player,
                        Enemy_Manager all_enemies, Window_Generator & window) {

    for (size_t index = 0; index < _num_collectibles; index++) {
        _collectible_list[index].entity_interaction(player, all_enemies, window);
    }
}

/**
 * Adds a collectible to the collectible array
 * @param collectible - a Collectible object
 */
void Collectible_Manager::add_collectible(const Collectible & collectible) {
    _collectible_list[_num_collectibles++] = collectible;
}

/**
 * Returns the array of collectibles
 * @return _collectible_list - the list of all collectibles
 */
Collectible * Collectible_Manager::get_collectible_list() {
    return _collectible_list;
}

/**
 * Gets the total number of collectibles
 * @param _num_collectibles - the number of collectibles
 */
size_t Collectible_Manager::get_num_obstacles() const {
    return _num_collectibles;
}
