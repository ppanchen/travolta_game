//
// Created by petro on 6/18/17.
//

#include "Map.hpp"

int getStrCount(std::string const &filename)
{
    std::ifstream filecontent (filename);
    std::string str;
    int i;

    i = 0;
    while (std::getline(filecontent, str))
        i++;
    filecontent.close();
    return (i);
}

Map::Map(std::string const &file) {
    std::ifstream filecontent (file);
    std::string str;
    std::string *map;
    int i;

    i = -1;
    countOfStr = getStrCount(file);
    map = new std::string[countOfStr]();
    while (std::getline(filecontent, str) && ++i < countOfStr)
        map[i] = str;
    this->map = map;
    filecontent.close();
    std::cout << "Map constructor was called" << std::endl;

    initscr();
    cbreak();
    noecho();
    start_color();
    curs_set(0);
    keypad(stdscr, true);
    timeout(1);
    init_pair(Main_color, COLOR_YELLOW, COLOR_BLACK);
    init_pair(Active_color, COLOR_BLACK, COLOR_YELLOW);
    init_pair(Obstacle_color, COLOR_WHITE, COLOR_WHITE);

}

Map::~Map() {
    delete [] map;
    endwin();
    std::cout << "Map destructor was called" << std::endl;
    return ;
}

Map::Map(Map const & map) {
    *this = map;
}

Map &Map::operator=(Map const & map) {
    if (this != &map)
    {
        delete [] this->map;;
        this->map = new std::string[map.countOfStr]();
        for (int i = 0; i < map.countOfStr; i++)
            this->map[i] = map.map[i];
    }
    return *this;
}

void Map::printMap() {
    for (int i = 0; i < this->countOfStr; i++)
        for (int j = 0; j < map[i].length(); j++)
        {
            if (map[i][j] == '*')
                attron(COLOR_PAIR(Obstacle_color));
            else
                attron(COLOR_PAIR(Main_color));
            mvprintw(i, j, "%c", map[i][j]);
            attroff(COLOR_PAIR(Obstacle_color));
            attroff(COLOR_PAIR(Main_color));
        }
    refresh();
    getch();
}

int Map::isObstacle(int i, int j) {
    if (i >= countOfStr || j >= map[i].length()
            || i < 0 || j < 0)
        return 1;
    if (map[i][j] == '*')
        return '*';
    else if (map[i][j] == 'E')
        return 'E';
    else if (map[i][j] == '0')
        return '0';
    else if (map[i][j] == '-')
        return '-';
    return 0;
}

std::string *Map::getMap() const {
    return map;
}

void Map::pasteOnMap(int i, int j, char c) {
    map[i][j] = c;
}

int Map::getCountOfStr() const {
    return countOfStr;
}