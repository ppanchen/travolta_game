#include <iostream>
#include "Enemy.hpp"
#include "RealPlayer.hpp"
//Enemy * initialize_enemies(Map & map)
//{
//    int i;
//    int j;
//    int k = -1;
//    Enemy *en;
//    en = new Enemy[10](0, 0, map);
//    while (++k < 10)
//    {
//        i = rand() % (map.getCountOfStr() - 1) + 1;
//        j = rand() % ((int)map.getMap()[0].length() - 1 ) + 1;
//        en[k].setI(i);
//        en[k].setJ(j);
//    }
//    return en;
//}

int main(int argc, char *argv[]) {
    if (argc == 1)
    {
        std::cout << "Please enter a map" << std::endl;
        return 0;
    }
    Map map(argv[1]);
    RealPlayer rp (map);
    Enemy en1 (1, 1, map);
    Enemy en2 (5, 10, map);
    Enemy en3 (1, 5, map);
    char c[2];
    while (1)
    {
        getstr(c);
        if (c[0] == 'q')
            break;
        rp.move(c[0]);
        en1.move();
        en2.move();
        en3.move();
        map.printMap();
        c[0] = en1.checkAlive();
        c[0] += en2.checkAlive();
        c[0] +=en3.checkAlive();
        c[1] = rp.checkAlive();
        if (c[0] == 0 || c[1] == 0)
        {
            map.printMap();
            mvprintw(map.getCountOfStr(),0, "%s", c[0] == 0 ?
                                                  "You are winner" : "You lose");
            mvprintw(map.getCountOfStr() + 1,0, "Please press eny key");
            c[0] = -1;
            while (c[0] == -1)
                c[0] = getch();
            break ;
        }
        system("sleep 0.1s");
    }
}