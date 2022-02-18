//Window_Generator_constants
#ifndef WINDOW_GENERATOR_CONSTANTS_H
#define WINDOW_GENERATOR_CONSTANTS_H

#define WINDOW_SIDE 124
#define WINDOW_TOP_BOTTOM 45
#define WINDOW_CORNER 43

#define STANDARD_WINDOW_WIDTH 28
#define STANDARD_WINDOW_X 51
#define STANDARD_WINDOW_EDGE_CONTROL 2

#define LINE_Y_1 1
#define LINE_Y_2 2
#define LINE_Y_3 3
#define LINE_Y_4 4
#define LINE_Y_5 5
#define LINE_Y_6 6
#define LINE_Y_7 7
#define LINE_Y_8 8
#define LINE_Y_9 9
#define LINE_Y_10 10
#define LINE_Y_11 11

#define LINE_X_1 1
#define LINE_X_2 2

#define STARTING_WINDOW 0
#define STARTING_WINDOW_HEIGHT 13
#define STARTING_WINDOW_Y 0

#define ENEMY_OBSTACLE_WINDOW 1
#define ENEMY_OBSTACLE_HEIGHT 4
#define ENEMY_OBSTACLE_Y 16
#define PRINT_ENEMIES_ALIVE_X 16
#define PRINT_OBSTACLES_REMAINING_X 22

#define TEXT_BOX_WINDOW 2
#define TEXT_BOX_HEIGHT 3
#define TEXT_BOX_Y 13

#define COLLECTIBLE_POINT_STARTING_WINDOW 3
#define COLLECTIBLE_POINT_UPDATE_WINDOW 4
#define COLLECTIBLE_POINT_HEIGHT 4
#define COLLECTIBLE_POINT_Y 20
#define PRINT_COLLECTIBLE_X 11
#define PRINT_POINT_X 15

#define SCREEN_CLEAR_WINDOW 5
#define SCREEN_CLEAR_X 0
#define SCREEN_CLEAR_Y 0
#define SCREEN_CLEAR_HEIGHT 24
#define SCREEN_CLEAR_WIDTH 80

#define GAME_OVER_WINDOW 6
#define GAME_OVER_X 30
#define GAME_OVER_Y 7
#define GAME_OVER_WIDTH 20
#define GAME_OVER_HEIGHT 8
#define PRINT_GAME_OVER_ENEMIES_X 17
#define PRINT_GAME_OVER_X 5
#define PRINT_GAME_OVER_POINTS_X 16
#define PRINT_FINAL_SCORE_X 15

#define POINTS_MULTIPLIER 9
#define ENEMIES_MULTIPLIER 4

#define MAX_COLLECTIBLE_LENGTH 16
#define POINTS_SPREAD 5

const char list_of_collectibles[][MAX_COLLECTIBLE_LENGTH] = {"a TV Remote",
    "a Cool Coin", "a Fish Head", "a Bent Fork", "a Candy Bar","3 Push Pins",
    "Loaded Dies", "a New Photo","a Dull Lock","Shiny Rocks", "a AAA Battery",
    "a Greenback","a Cigarette","Old Needles", "an Ice Cube","a Telescope",
    "a Book", "a CS Degree", "a Cannonball", "Two Cookies", "a Harmonica",
    "a 1UP Shroom", "*ERROR*", "an Iron Bar","a Tape Worm"};

const char sayings_array[][STANDARD_WINDOW_WIDTH - STANDARD_WINDOW_EDGE_CONTROL] =
    {"Huzzah!", "DIE DIE DIE", "Remember the Alamo!",
    "Chaaaaarge!!!", "Hoorah!", "Deus Hoc Volt!", "In Valhalla We Dine!",
    "Victory or Death!", "BANZAI!!", "Victory is MINE!",
    "BACK you Fiend!", "Any Last Words?", "Dead Man Walking...",
    "Life is Pain, so is Death", "Violence is the Answer"};

#endif //WINDOW_GENERATOR_CONSTANTS_H
