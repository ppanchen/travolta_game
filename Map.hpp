//
// Created by petro on 6/18/17.
//

#ifndef MAP_HPP
#define MAP_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <sstream>

class Map {
private:
    enum{
        Main_color = 1,
        Active_color = 2,
        Obstacle_color = 3
    };
    std::string     *map;
    int             countOfStr;
public:
    Map(std::string const &);
    ~Map();
    Map(Map const &);
    Map &operator=(Map const &);
    void printMap();
    int isObstacle(int , int );
    std::string *getMap() const;
    void pasteOnMap(int, int, char);
    int getCountOfStr() const;
};


#endif //MAP_HPP
