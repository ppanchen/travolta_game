//
// Created by petro on 6/19/17.
//

#include <netinet/in.h>
#include "RealPlayer.hpp"

void RealPlayer::jump() {
    static int i = 3;
    inJump = 1;
    if (i == 0) {
        inJump = 0;
        i = 3;
        return ;
    }
    i--;
    if (map.isObstacle(this->i - 1, this->j))
    {
        return ;
    }
    this->i--;
}

RealPlayer::RealPlayer(Map &map) : Player(0, 0, map){
    std::string *mapcpy = map.getMap();
    for(int i = 0; i < map.getCountOfStr(); i++)
    {
        if (mapcpy[i].find('0') != -1)
        {
            this->j = (int)mapcpy[i].find('0');
            this->i = i;
            break ;
        }
    }
    inJump = 0;
    isShooting = 0;
}

RealPlayer::RealPlayer(const RealPlayer &rr) : Player(rr.i, rr.j, rr.map){
    *this = rr;
}

RealPlayer &RealPlayer::operator=(const RealPlayer &rr) {
    if (this != &rr)
    {
        i = rr.i;
        j = rr.j;
        direction = rr.direction;
        map = rr.map;
        inJump = rr.inJump;
    }
    return *this;
}

RealPlayer::~RealPlayer() {
    return ;
}

void RealPlayer::move(int keyPress) {
    if (!this->alive && wasAlive)
    {
        map.pasteOnMap(i, j, 'X');
        wasAlive = 0;
        return;
    }
    else if (!alive && !wasAlive)
        return;
    map.pasteOnMap(i, j, ' ');
    if (inJump)
        jump();
    if (isShooting)
        shoot();
    switch (keyPress) {
        case 'w': {
            if (map.isObstacle(i + 1, j))
                jump();
            break;
        }
        case 'a': {
            if (!map.isObstacle(i, j - 1))
                j--;
            direction = 2;
            break;
        }
        case 'd': {
            if (!map.isObstacle(i, j + 1))
                j++;
            direction = 1;
            break;
        }
        case ' ': {
            shoot();
            break;
        }
        default:
            break;
    }
    if (!inJump)
        gravity();
    map.pasteOnMap(i, j, '0');

}
void RealPlayer::shoot() {
    static int i = 0;
    static int j = 0;
    static int dir = 0;

    if (dir == 0)
    {
        i = this->i;
        j = this->j;
        dir = this->direction;
        if (dir == 1) {
            if (map.isObstacle(i, ++j)) {
                dir = 0;
                return;
            }
        } else if (dir == 2) {
            if (map.isObstacle(i, --j)) {
                dir = 0;
                return;
            }
        }
        map.pasteOnMap(i, j, '-');
        isShooting = 1;
        return;
    }
    map.pasteOnMap(i, j, ' ');
    if (dir == 1) {
        if (map.isObstacle(i, ++j)) {
            dir = 0;
            isShooting = 0;
            return;
        }
    } else if (dir == 2) {
        if (map.isObstacle(i, --j)) {
            dir = 0;
            isShooting = 0;
            return;
        }
    }
    map.pasteOnMap(i, j, '-');
    isShooting = 1;
    return;
}

bool RealPlayer::checkAlive() {
    if (map.isObstacle(i, j - 1) == 'E' ||
        map.isObstacle(i, j + 1) == 'E')
    {
        alive = 0;
    }
    return alive;
}
