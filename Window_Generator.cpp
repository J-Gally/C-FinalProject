#include "Window_Generator.h"
#include "Window_Generator_constants.h"
#include <random>
#include <string>

/**
 * Generates the Window_Generator class
 */
Window_Generator::Window_Generator() {
    _total_points = 0;
}

/**
 * Generates the tutorial window
 */
void Window_Generator::generate_starting_window() {
    _window_array[STARTING_WINDOW] = newwin(STARTING_WINDOW_HEIGHT,
                   STANDARD_WINDOW_WIDTH, STARTING_WINDOW_Y, STANDARD_WINDOW_X);
    refresh();
    wborder(_window_array[STARTING_WINDOW], WINDOW_SIDE, WINDOW_SIDE,
    WINDOW_TOP_BOTTOM, WINDOW_TOP_BOTTOM,WINDOW_CORNER, WINDOW_CORNER,
    WINDOW_CORNER, WINDOW_CORNER);

    mvwprintw(_window_array[STARTING_WINDOW], LINE_Y_1, LINE_X_1,
                                                  "Hello! Welcome to my game!");
    mvwprintw(_window_array[STARTING_WINDOW], LINE_Y_2, LINE_X_1,
                                                      "Tips before you begin:");
    mvwprintw(_window_array[STARTING_WINDOW], LINE_Y_4, LINE_X_1,
                                                   "-Move with the arrow keys");
    mvwprintw(_window_array[STARTING_WINDOW], LINE_Y_5, LINE_X_1,
                                                         "-Attack with 'WASD'");
    mvwprintw(_window_array[STARTING_WINDOW], LINE_Y_6, LINE_X_1,
                                                              "-Avoid enemies");
    mvwprintw(_window_array[STARTING_WINDOW], LINE_Y_7, LINE_X_1,
                                                            "-Dodge obstacles");
    mvwprintw(_window_array[STARTING_WINDOW], LINE_Y_8, LINE_X_1,
                                                     "-Get pickups for points");
    mvwprintw(_window_array[STARTING_WINDOW], LINE_Y_10, LINE_X_1,
                                                   "Press any button to begin");
    mvwprintw(_window_array[STARTING_WINDOW], LINE_Y_11, LINE_X_1,
                                                                 "Good Luck!!");
    wrefresh(_window_array[STARTING_WINDOW]);
    getch();
}

/**
 * Counts the number of valid obstacles and alive enemies
 * @param all_enemies - all of the enemies on the floor
 * @param all_obstacles - all of the obstacles on the floor
 */
void Window_Generator::enemy_obstacle_counter(const Enemy_Manager & all_enemies,
                                 const Obstacle_Manager & all_obstacles) {
    _window_array[ENEMY_OBSTACLE_WINDOW] = newwin(ENEMY_OBSTACLE_HEIGHT,
                    STANDARD_WINDOW_WIDTH, ENEMY_OBSTACLE_Y, STANDARD_WINDOW_X);
    refresh();

    wborder(_window_array[ENEMY_OBSTACLE_WINDOW], WINDOW_SIDE, WINDOW_SIDE,
    WINDOW_TOP_BOTTOM, WINDOW_TOP_BOTTOM, WINDOW_CORNER, WINDOW_CORNER,
    WINDOW_CORNER, WINDOW_CORNER);

    enemy_obstacle_printer(all_enemies, all_obstacles);
}

/**
 * Prints the obstacle and enemy statitics
 */
void Window_Generator::enemy_obstacle_printer(const Enemy_Manager & all_enemies,
                                 const Obstacle_Manager & all_obstacles) const {
    std::string temporary_std_string =
                              std::to_string(all_enemies.count_alive_enemies());
    char const * char_enemies_obstacles_string = temporary_std_string.c_str();
    //this is from the string class, mvwprintw has a very specific parameter: const * char, so I needed to convert an integer or other numerical data
    //type into a string. I did this with the to_string class, which converts alive_enemies into an std::string type, and then the c_string operator
    //which converts that type into a c_style string that I then assigned a const to. I had to do std::... because at one point Professor Strash
    //said that we could not use "using namespace std;" in our header files.

    mvwprintw(_window_array[ENEMY_OBSTACLE_WINDOW], LINE_Y_1, LINE_X_1,
                                                             "Enemies alive: ");
    mvwprintw(_window_array[ENEMY_OBSTACLE_WINDOW], LINE_Y_1,
                          PRINT_ENEMIES_ALIVE_X, char_enemies_obstacles_string);

    temporary_std_string = std::to_string(all_obstacles.count_valid_obstacles());
    char_enemies_obstacles_string = temporary_std_string.c_str();

    mvwprintw(_window_array[ENEMY_OBSTACLE_WINDOW], LINE_Y_2, LINE_X_1,
                                                       "Obstacles Remaining: ");
    mvwprintw(_window_array[ENEMY_OBSTACLE_WINDOW], LINE_Y_2,
                    PRINT_OBSTACLES_REMAINING_X, char_enemies_obstacles_string);

    wrefresh(_window_array[ENEMY_OBSTACLE_WINDOW]);
}

/**
 * Generates a text box for the player to "shout" in
 */
void Window_Generator::text_box() {
    _window_array[TEXT_BOX_WINDOW]= newwin(TEXT_BOX_HEIGHT,
                          STANDARD_WINDOW_WIDTH, TEXT_BOX_Y, STANDARD_WINDOW_X);
    refresh();

    wborder(_window_array[TEXT_BOX_WINDOW], WINDOW_SIDE, WINDOW_SIDE,
                              WINDOW_TOP_BOTTOM, WINDOW_TOP_BOTTOM,
                              WINDOW_CORNER, WINDOW_CORNER,
                              WINDOW_CORNER, WINDOW_CORNER);

    mvwprintw(_window_array[TEXT_BOX_WINDOW], LINE_Y_1, LINE_X_1,
    sayings_array[rand() % (sizeof(sayings_array) /
                      (STANDARD_WINDOW_WIDTH - STANDARD_WINDOW_EDGE_CONTROL))]);

    wrefresh(_window_array[TEXT_BOX_WINDOW]);
}

/**
 * Generates an empty box for the points to be counted in in the future
 */
void Window_Generator::collectible_and_point_generator() {
    _window_array[COLLECTIBLE_POINT_STARTING_WINDOW] = newwin(
    COLLECTIBLE_POINT_HEIGHT, STANDARD_WINDOW_WIDTH, COLLECTIBLE_POINT_Y,
    STANDARD_WINDOW_X);

    refresh();
    wborder(_window_array[COLLECTIBLE_POINT_STARTING_WINDOW], WINDOW_SIDE,
               WINDOW_SIDE, WINDOW_TOP_BOTTOM, WINDOW_TOP_BOTTOM, WINDOW_CORNER,
               WINDOW_CORNER, WINDOW_CORNER, WINDOW_CORNER);

    mvwprintw(_window_array[COLLECTIBLE_POINT_STARTING_WINDOW], LINE_Y_2,
                                                   LINE_X_1, "Total Points: 0");

    wrefresh(_window_array[COLLECTIBLE_POINT_STARTING_WINDOW]);
}

/**
 * Adds points to _total_points and prints the name of the collectible the
 * player picked up
 */
void Window_Generator::collectible_and_point_counter() {
    _window_array[COLLECTIBLE_POINT_UPDATE_WINDOW] = newwin(
    COLLECTIBLE_POINT_HEIGHT, STANDARD_WINDOW_WIDTH, COLLECTIBLE_POINT_Y,
    STANDARD_WINDOW_X);

    refresh();

    wborder(_window_array[COLLECTIBLE_POINT_UPDATE_WINDOW], WINDOW_SIDE,
    WINDOW_SIDE, WINDOW_TOP_BOTTOM, WINDOW_TOP_BOTTOM, WINDOW_CORNER,
    WINDOW_CORNER, WINDOW_CORNER, WINDOW_CORNER);

    mvwprintw(_window_array[COLLECTIBLE_POINT_UPDATE_WINDOW],
                                              LINE_Y_1, LINE_X_1, "You found ");
    mvwprintw(_window_array[COLLECTIBLE_POINT_UPDATE_WINDOW], LINE_Y_1,
                              PRINT_COLLECTIBLE_X, list_of_collectibles[rand() %
                      (sizeof(list_of_collectibles) / MAX_COLLECTIBLE_LENGTH)]);

    _total_points += int(rand() % POINTS_SPREAD);

    std::string temporary_std_string = std::to_string(_total_points);
    char const * char_total_points = temporary_std_string.c_str();

    mvwprintw(_window_array[COLLECTIBLE_POINT_UPDATE_WINDOW], LINE_Y_2,
                                                    LINE_X_1, "Total Points: ");
    mvwprintw(_window_array[COLLECTIBLE_POINT_UPDATE_WINDOW], LINE_Y_2,
                                              PRINT_POINT_X, char_total_points);

    wrefresh(_window_array[COLLECTIBLE_POINT_UPDATE_WINDOW]);
}

/**
 * Prints a game over screen that tallies enemies killed and points collected
 * @param all_enemies - all of the enemies on the floor
 */
void Window_Generator::game_over(const Enemy_Manager & all_enemies) {
    screen_clearer();
    _window_array[GAME_OVER_WINDOW] = newwin(GAME_OVER_HEIGHT,
                                     GAME_OVER_WIDTH, GAME_OVER_Y, GAME_OVER_X);

    std::string temporary_std_string =
                                 std::to_string(all_enemies.get_dead_enemies());
    char const * stats_string = temporary_std_string.c_str();

    wborder(_window_array[GAME_OVER_WINDOW], WINDOW_SIDE, WINDOW_SIDE,
    WINDOW_TOP_BOTTOM, WINDOW_TOP_BOTTOM, WINDOW_CORNER, WINDOW_CORNER,
    WINDOW_CORNER, WINDOW_CORNER);

    mvwprintw(_window_array[GAME_OVER_WINDOW], LINE_Y_1,
                                               PRINT_GAME_OVER_X, "GAME OVER!");
    mvwprintw(_window_array[GAME_OVER_WINDOW], LINE_Y_3, LINE_X_1,
                                                            "Enemies killed: ");
    mvwprintw(_window_array[GAME_OVER_WINDOW], LINE_Y_3,
                                       PRINT_GAME_OVER_ENEMIES_X, stats_string);

    total_points_counter(all_enemies);

    refresh();
    wrefresh(_window_array[GAME_OVER_WINDOW]);
    getch();
}

/**
 * Calculates and prints the total number of points the player got when playing
 * @param all_enemies - all of the enemies on the floor
 */
void Window_Generator::total_points_counter(const Enemy_Manager & all_enemies)
                                                                         const {
    std::string temporary_std_string = std::to_string(_total_points);
    char const * stats_string = temporary_std_string.c_str();

    mvwprintw(_window_array[GAME_OVER_WINDOW], LINE_Y_4, LINE_X_2,
                                                              "Total Points: ");
    mvwprintw(_window_array[GAME_OVER_WINDOW], LINE_Y_4,
                                        PRINT_GAME_OVER_POINTS_X, stats_string);

    temporary_std_string = std::to_string((_total_points * POINTS_MULTIPLIER) +
                         (all_enemies.get_dead_enemies() * ENEMIES_MULTIPLIER));
    stats_string = temporary_std_string.c_str();

    mvwprintw(_window_array[GAME_OVER_WINDOW], LINE_Y_6, LINE_X_2,
                                                               "Final Score: ");
    mvwprintw(_window_array[GAME_OVER_WINDOW], LINE_Y_6,
                                             PRINT_FINAL_SCORE_X, stats_string);
}

/**
 * Clears the screen
 */
void Window_Generator::screen_clearer() {
    _window_array[SCREEN_CLEAR_WINDOW] = newwin(SCREEN_CLEAR_HEIGHT,
                            SCREEN_CLEAR_WIDTH, SCREEN_CLEAR_Y, SCREEN_CLEAR_X);
    refresh();
    wrefresh(_window_array[SCREEN_CLEAR_WINDOW]);
}
