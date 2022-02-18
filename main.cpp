/**
 * Final Project: Plays a pseudo dungeon crawler game using ncurses
 * @file main.cpp
 * @author - James Gallagher
 * @collaborators N/A
 * @12/10/21
 */

#include "Game_Player.h"
#include <ctime>
#include <iostream>

/**
 * Initalizes ncurses
 */
void ncurses_intializer() {
    initscr();
    noecho();
    cbreak();

    curs_set(0);
    keypad(stdscr, TRUE);
    srand(time(0));
}

//Controls the operations of the program
int main() {

    ncurses_intializer();

    if (!has_colors()) {
        endwin();
        printf("Your terminal does not support color\n");
        return 1;
    }
    start_color();

    Room_Generator room;
    Window_Generator window;
    Player player;
    Obstacle_Manager all_obstacles;
    Enemy_Manager all_enemies;
    Collectible_Manager all_collectibles;

    Game_Generator game_generator;
    game_generator.generate_game(room, window, player, all_obstacles, all_enemies,
                                                                all_collectibles);

    Game_Player game;
    game.play_game(window, player, all_obstacles, all_enemies, all_collectibles);

    endwin();
    return 0;
}
