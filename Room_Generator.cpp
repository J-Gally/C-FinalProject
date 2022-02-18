#include "Room_Generator.h"
#include "constants.h"
#include <ncurses.h>

/**
 * Generates a white background for the game
 */
void Room_Generator::background_generator() const {
    init_pair(BACKGROUND_COLOR_PAIR, COLOR_WHITE, COLOR_WHITE);

    attron(COLOR_PAIR(BACKGROUND_COLOR_PAIR));

    for (size_t y = STARTING_BACKGROUND_Y; y < ROW_BORDER_CONTROL; y++) {
        for (size_t x = STARTING_BACKGROUND_X; x < COL_BORDER_CONTROL; x++) {
            mvprintw(y, x, "%s", " ");
        }
    }

    attroff(COLOR_PAIR(BACKGROUND_COLOR_PAIR));
    refresh();
}

/**
 * Generates a green border for the game
 */
void Room_Generator::border_generator() const {
    init_pair(BORDER_COLOR_PAIR, COLOR_GREEN, COLOR_GREEN);
    attron(COLOR_PAIR(BORDER_COLOR_PAIR));

    for (size_t y = 0; y < ROW_MAX; y++) {
        for (size_t x = 0; x < COL_MAX; x++) {
            if (y == 0 || x < STARTING_BACKGROUND_X ||
                y == ROW_BORDER_CONTROL || x > COL_BORDER_CONTROL - 1)
                mvprintw(y, x, "%s", " ");
        }
    }
    attroff(COLOR_PAIR(BORDER_COLOR_PAIR));
    refresh();
}
