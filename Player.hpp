//
// Created by petro on 6/17/17.
//

#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include "Map.hpp"
#include <random>

class Player {
protected:
    int i;
    int j;
    int direction;//1 ->, 2 <-;
    bool alive;
    bool wasAlive;
    Map &map;
    void ch_dir();
    int gravity();
public:
    Player(int, int, Map &);
    virtual ~Player();
    Player(Player const &);
    Player &operator=(Player const &);
    virtual void move(int = 0) = 0;
    int getI() const;
    void setI(int i);
    int getJ() const;
    void setJ(int j);
};


#endif //PLAYERS_HPP
