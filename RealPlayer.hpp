//
// Created by petro on 6/19/17.
//

#ifndef REALPLAYER_HPP
#define REALPLAYER_HPP

# include "Player.hpp"

class RealPlayer : public Player{
    int inJump;
    int isShooting;
    void jump();
public:
    RealPlayer(Map &);
    RealPlayer(const RealPlayer &);
    RealPlayer &operator=(const RealPlayer &);
    ~RealPlayer();
    void move(int);
    void shoot();
    bool checkAlive();
};


#endif //REALPLAYER_HPP
