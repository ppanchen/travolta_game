//
// Created by petro on 6/17/17.
//

#include <netinet/in.h>
#include <queue>
#include "Enemy.hpp"

void Enemy::move(int) {
    if (!this->alive && wasAlive)
    {
        map.pasteOnMap(i, j, ' ');
        wasAlive = 0;
        return;
    }
    else if (!alive && !wasAlive)
        return;
    map.pasteOnMap(i, j, ' ');
    switch (direction){
        case 1:
        {
            if (map.isObstacle(i, j + 1))
                ch_dir();
            else if (!gravity())
                j++;
            map.pasteOnMap(i, j, 'E');
            break;
        }
        case 2:
        {
            if (map.isObstacle(i, j - 1))
                ch_dir();
            else if (!gravity())
                j--;
            map.pasteOnMap(i, j, 'E');
            break;
        }
        default:
            break ;
    }
}

Enemy::Enemy(int i, int j, Map &map) : Player(i, j, map){
    while (gravity())
        continue ;
    map.pasteOnMap(this->i, this->j, 'E');
    std::cout << "Enemy constructor called" << std::endl;
    return ;
}

Enemy::~Enemy() {
    std::cout << "Enemy destructor called" << std::endl;
}

Enemy::Enemy(const Enemy &re) : Player(re.i, re.j, re.map){
    *this = re;
    std::cout << "Enemy copy constructor called" << std::endl;
}

Enemy &Enemy::operator=(const Enemy &re) {
    if (this != &re)
    {
        this->i = re.i;
        this->j = re.j;
        this->map = re.map;
        this->direction = re.direction;
    }
    return *this;
}
bool Enemy::checkAlive() {
    if (map.isObstacle(i, j - 1) == '-' ||
        map.isObstacle(i, j + 1) == '-')
    {
        alive = 0;
    }
    return alive;
}