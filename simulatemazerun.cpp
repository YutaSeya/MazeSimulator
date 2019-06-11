#include "simulatemazerun.h"

#include <QtCore/QEventLoop>
#include <QtCore/QTimer>

SimulateMazeRun::SimulateMazeRun()
{
    draw_maze = new DrawMaze();
}

SimulateMazeRun::~SimulateMazeRun()
{
    delete draw_maze;
}

void SimulateMazeRun::copyNowMazeData(uint8_t wall_data[16][16])
{
    for(int x = 0; x < 16; x++){
        for(int y = 0; y < 16; y++){
            simulate_wall[x][y] = wall_data[x][y];
        }
    }
}

void SimulateMazeRun::leftHandSearch(QGraphicsScene *scene)
{
    uint8_t act = Front;

    wall_init();
    pos.init();

    // 左手法の場合ゴールにたどり着けない可能性があるため、
    // ある一定以上の回数で終わりにする
    int count = 200;

    while(1){

        addSimulateWall();

        draw_maze->drawSimulate(scene, pos.x, pos.y, wall);

        act = leftHand();

        count--;

        msleep( 100 );

        if(gx == pos.x && gy == pos.y) break;

        if(count < 0) break;

    }

    draw_maze->drawSimulate(scene, pos.x, pos.y, wall);
}

void SimulateMazeRun::msleep(int _time)
{
    QEventLoop loop;
    QTimer::singleShot( _time, &loop, SLOT( quit() ) );
    loop.exec();
}

void SimulateMazeRun::addSimulateWall()
{
    wall[pos.x][pos.y] = simulate_wall[pos.x][pos.y];
}


