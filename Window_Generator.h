#include <ncurses.h>
#include <cstddef>

#include "Enemy_Manager.h"
#include "Obstacle_Manager.h"

#ifndef WINDOW_GENERATOR_H
#define WINDOW_GENERATOR_H

class Window_Generator {
public:
    Window_Generator();
    void generate_starting_window();
    void enemy_obstacle_counter(const Enemy_Manager & all_enemies,
                                        const Obstacle_Manager & all_obstacles);
    void text_box();
    void collectible_and_point_generator();
    void collectible_and_point_counter();
    void game_over(const Enemy_Manager & all_enemies);
    void total_points_counter(const Enemy_Manager & all_enemies) const;
    void screen_clearer();
private:
    void enemy_obstacle_printer(const Enemy_Manager & all_enemies,
                                const Obstacle_Manager & all_obstacles) const;
    int _total_points;
    WINDOW * _window_array[MAX_WINDOWS];
};


#endif //WINDOW_GENERATOR_H
