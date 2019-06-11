#ifndef SIMULATEMAZERUN_H
#define SIMULATEMAZERUN_H

#include "mazerunbase.h"
#include <stdint.h>
#include "drawmaze.h"

class SimulateMazeRun : public MazeRunBase
{
public:
    SimulateMazeRun();

    virtual ~SimulateMazeRun();

    void leftHandSearch(QGraphicsScene *scene);

    void copyNowMazeData(uint8_t wall_data[16][16]);

private:

    void addSimulateWall();

    DrawMaze *draw_maze;

    void msleep(int _time);

    uint8_t simulate_wall[16][16];


};

#endif // SIMULATEMAZERUN_H
