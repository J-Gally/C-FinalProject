#include <ncurses.h>
#include "Player.h"
#include "constants.h"
#include <random>

/**
 * Constructs the Player class
 */
Player::Player() {
    _player_x = 0;
    _player_y = 0;
    _attack_x = 0;
    _attack_y = 0;
}

/**
 * Colors the current player's x,y in the player color
 */
void Player::player_color() const {
    init_pair(PLAYER_COLOR_PAIR, COLOR_RED, COLOR_RED);
    attron(COLOR_PAIR(PLAYER_COLOR_PAIR));

    mvprintw(_player_y, _player_x, "%s", " ");

    attroff(COLOR_PAIR(PLAYER_COLOR_PAIR));
}

/**
 * Places the player on the game floor
 */
void Player::player_placement() {
    _player_y = (rand() % (PLACEMENT_Y)) + PLACEMENT_Y_CONTROL;
    _player_x = (rand() % (PLACEMENT_X)) + PLACEMENT_X_CONTROL;

    player_color();
}

/**
 * Controls a player's actions
 * @return true if the player attacked, false otherwise
 */
bool Player::player_action() {
    int input = 0;
    input = getch();

    attack_cleanup();

    if (input == KEY_LEFT || input == KEY_RIGHT
     || input == KEY_UP || input == KEY_DOWN)
        player_movement(input);

    if (input == 'w' || input == 'a' || input == 's' || input == 'd' ||
        input == 'W' || input == 'A' || input == 'S' || input == 'D') {
        player_attack(input);
        refresh();
        return true;
    }

    return false;
}

/**
 * Moves a player one unit in a cardinal direction
 * @param input - the key the user inputted to move
 */
void Player::player_movement(const int input) {
    const size_t old_x = _player_x;
    const size_t old_y = _player_y;

    if (input == KEY_LEFT && _player_x > MIN_PLAYER_X)
        _player_x -= 1;

    else if (input == KEY_RIGHT && _player_x != MAX_PLAYER_X)
        _player_x += 1;

    else if (input == KEY_UP && _player_y > MIN_PLAYER_Y)
        _player_y -= 1;

    else if (input == KEY_DOWN && _player_y < MAX_PLAYER_Y)
        _player_y += 1;

    player_color();

    init_pair(BACKGROUND_COLOR_PAIR, COLOR_WHITE, COLOR_WHITE);
    attron(COLOR_PAIR(BACKGROUND_COLOR_PAIR));

    if (old_x != _player_x || old_y != _player_y)
        mvprintw(old_y, old_x, "%s", " ");

    attroff(COLOR_PAIR(BACKGROUND_COLOR_PAIR));
}

/**
 * Attacks in one of the cardinal directions
 * @param input - the key the user inputted to attack
 */
void Player::player_attack(const int input) {

    if ((input == 'w' || input == 'W') && _player_y > MIN_PLAYER_Y) {
        mvprintw(_player_y - 1, _player_x, "%s", "^");
        _attack_y = _player_y - 1;
        _attack_x = _player_x;

    } else if ((input == 'a' || input == 'A') && _player_x > MIN_PLAYER_X) {
        mvprintw(_player_y, _player_x - 1, "%s", "<");
        _attack_y = _player_y;
        _attack_x = _player_x - 1;

    } else if ((input == 's' || input == 'S') && _player_y < MAX_PLAYER_Y) {
        mvprintw(_player_y + 1, _player_x, "%s", ".");
        _attack_y = _player_y + 1;
        _attack_x = _player_x;

    } else if ((input == 'd' || input == 'D') && _player_x < MAX_PLAYER_X) {
        mvprintw(_player_y, _player_x + 1, "%s", ">");
        _attack_y = _player_y;
        _attack_x = _player_x + 1;
    }
}

/**
 * Removes the attack icon from the screen
 */
void Player::attack_cleanup() {
    init_pair(BACKGROUND_COLOR_PAIR, COLOR_WHITE, COLOR_WHITE);

    attron(COLOR_PAIR(BACKGROUND_COLOR_PAIR));

    if (_attack_x != 0 || _attack_y != 0)
        mvprintw(_attack_y, _attack_x, "%s", " ");

    attroff(COLOR_PAIR(BACKGROUND_COLOR_PAIR));

    _attack_x = 0;
    _attack_y = 0;
}

/**
 * Returns the player's x position
 * @return the x position of the player
 */
size_t Player::get_x() const {
    return _player_x;
}

/**
 * Returns the player's y position
 * @return the y position of the player
 */
size_t Player::get_y() const {
    return _player_y;
}

/**
 * Returns the player's attack x position
 * @return the attack x position of the player
 */
size_t Player::get_attack_x() const {
    return _attack_x;
}

/**
 * Returns the player's attack y position
 * @return the attack y position of the player
 */
size_t Player::get_attack_y() const {
    return _attack_y;
}
