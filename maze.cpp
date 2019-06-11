#include "maze.h"

Maze::Maze()
{

}

Maze::~Maze()
{

}


uint8_t Maze::leftHands(Position *pos, uint8_t wall[16][16])
{
    uint8_t act = Rear;
    uint8_t north = wall[pos->x][pos->y] & 0x01;
    uint8_t east = (wall[pos->x][pos->y] & 0x02) >> 1;
    uint8_t west = (wall[pos->x][pos->y] & 0x04) >> 2;
    uint8_t south = (wall[pos->x][pos->y] & 0x08) >> 3;

    if (pos->direction == North){
        if(west == 0){
            act = Left;
        } else if(north == 0){
            act = Front;
        } else if(east == 0){
            act = Right;
        } 
    } else if(pos->direction == South) {
        if(east == 0){
            act = Left;
        } else if(south == 0){
            act = Front;
        } else if(west == 0){
            act = Right;
        } 
    } else if(pos->direction ==West){
        if(south == 0){
            act = Left;
        } else if(west == 0){
            act = Front;
        } else if(north == 0){
            act = Right;
        }
    } else {
        if(north == 0){
            act = Left;
        } else if(east == 0){
            act = Front;
        } else if(south == 0){
            act = Right;
        }
    }

    return act;

}
