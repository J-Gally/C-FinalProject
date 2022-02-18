#include <cstddef>

#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player();
    void player_placement();
    bool player_action();
    void attack_cleanup();
    size_t get_x() const;
    size_t get_y() const;
    size_t get_attack_x() const;
    size_t get_attack_y() const;
private:
    void player_movement(const int input);
    void player_attack(const int input);
    void player_color() const;

    size_t _attack_x;
    size_t _attack_y;
    size_t _player_x;
    size_t _player_y;
};

#endif //PLAYER_H
