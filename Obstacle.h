#include <cstddef>
#include "Player.h"

#ifndef OBSTACLE_H
#define OBSTACLE_H

class Obstacle {
public:
    Obstacle();
    void obstacle_placement(const Player & player);
    void invalidate();
    void validate();
    size_t get_obstacle_x() const;
    size_t get_obstacle_y() const;
    bool get_valid_obstacle() const;
private:
    bool _valid_obstacle;
    size_t _x;
    size_t _y;
};

#endif //OBSTACLE_H
