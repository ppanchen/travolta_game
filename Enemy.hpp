//
// Created by petro on 6/17/17.
//

#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "Player.hpp"

class Enemy : public Player{
public:
    Enemy(int, int, Map &);
    ~Enemy();
    Enemy(const Enemy &);
    Enemy &operator=(const Enemy &);
    void move(int = 0);
    bool checkAlive();
};

#endif //ENEMY_HPP
