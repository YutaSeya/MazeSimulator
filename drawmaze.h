#ifndef DRAWMAZE_H
#define DRAWMAZE_H

#include <QtWidgets>

#include <stdint.h>

class DrawMaze
{
public:
    DrawMaze();

    void init(QGraphicsScene *scene);

    void drawWall(QGraphicsScene *scene, uint8_t wall[16][16]);

    void drawSimulate(QGraphicsScene *scene, uint8_t x, uint8_t y, uint8_t wall[16][16]);

private:
    const int step = 43;

    QPen pen;

    void drawMachine(QGraphicsScene *scene, uint8_t x, uint8_t y);
};

#endif // DRAWMAZE_H
