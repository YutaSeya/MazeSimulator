#include "mazerunbase.h"

MazeRunBase::MazeRunBase()
{ 
    maze = new Maze();
    pos.init();
    wall_init();
}

MazeRunBase::~MazeRunBase()
{
    delete maze;
}

MazeRunBase::MazeRunBase(uint8_t x, uint8_t y)
{
    gx = x;
    gy = y;
}

void MazeRunBase::setGoal(uint8_t x, uint8_t y)
{
    gx = x;
    gy = y;
}

uint8_t MazeRunBase::leftHand()
{
  uint8_t act = Rear;

  act = maze->leftHands(&pos, wall);
  pos.update(act);

  return act;
}

void MazeRunBase::wall_init()
{
    for(int x = 0; x< 16; x++){
        for(int y = 0; y< 16; y++){
            wall[x][y] = 0;
        }
    }
}
