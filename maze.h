#ifndef MAZE_H
#define MAZE_H

#include "mazeconfig.h"

#include <stdint.h>

struct Position
{
public:
    uint8_t x;
    uint8_t y;
    uint8_t direction;

    void init(){
        x = 0;
        y = 0;
        direction = North;
    }

    void update(uint8_t act)
    {
        uint8_t next = (direction + act) % 4;

        direction = next;

        if ( direction == North ){
            y++;
        } else if ( direction == West ){
            x--;
        } else if ( direction == South ){
            y--;
        } else {
            x++;
        }
    }

};

class Maze
{
public:
    Maze();

    ~Maze();

    uint8_t leftHands(Position *pos, uint8_t wall[16][16]);



};

#endif // MAZE_H
