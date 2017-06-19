//
// Created by petro on 6/17/17.
//

#include "Player.hpp"

Player::Player(int x, int y, Map &map) : i(x), j(y), map(map), alive(1) {
    srand((unsigned)time(0));
    ch_dir();
    wasAlive = 1;
    std::cout << "Player constructor called" << std::endl;
    return ;
}

Player::~Player() {
    std::cout << "Player destructor called" << std::endl;
    //getDie();
}

Player::Player(Player const &rp) : map(rp.map){
    std::cout << "Player copy constructor called" << std::endl;
    *this = rp;
}

Player &Player::operator=(Player const &rp) {
    if (this != &rp)
    {
        i = rp.i;
        j = rp.j;
        direction = rp.direction;
        map = rp.map;
    }
    return *this;
}

void Player::ch_dir() {
    int dir;

    dir = rand() % 2 + 1;
    this->direction = dir;
}

int Player::gravity() {
    if (!map.isObstacle(i + 1, j))
    {
        i++;
        return 1;
    }
    return 0;
}

int Player::getI() const {
    return i;
}

void Player::setI(int i) {
    Player::i = i;
}

int Player::getJ() const {
    return j;
}

void Player::setJ(int j) {
    Player::j = j;
}


