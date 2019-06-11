#include "drawmaze.h"

DrawMaze::DrawMaze()
{

}

void DrawMaze::init(QGraphicsScene *scene)
{

    pen.setColor(Qt::gray);
    pen.setWidth(3);

    for( int i = 1; i < 17; i++ ){
        QGraphicsTextItem *text_row_on = scene->addText(QString::number(i-1));
        text_row_on->setPos( i * step + 11, 0 );

        QGraphicsTextItem *text_row_under = scene->addText(QString::number(i-1));
        text_row_under->setPos( i * step + 11, step * 17 + 21);

        QGraphicsTextItem *text_column_left = scene->addText(QString::number(16-i));
        text_column_left->setPos( 0, i * step + 11 );

        QGraphicsTextItem *text_column_right = scene->addText(QString::number(16-i));
        text_column_right->setPos( step * 17 + 21, i * step + 11 );

    }

    for ( int i = 1; i <= 17; i++ ){
        scene->addLine(i*step, step, i*step, 17*step, pen);
        scene->addLine(step, i*step, 17*step, i*step, pen);
    }

}

void DrawMaze::drawWall(QGraphicsScene *scene, uint8_t (*wall)[16])
{
    scene->clear();
    init(scene);

    pen.setColor(Qt::red);

    for( int x = 0; x < 16; x++ ){
        for( int y = 0; y < 16; y++ ){
            int n = (wall[x][y] & 0x01);
            int e = (wall[x][y] & 0x02) >> 1;
            int w = (wall[x][y] & 0x04) >> 2;
            int s = (wall[x][y] & 0x08) >> 3;

            if( n == 1 ) scene->addLine( (x+1)*step, (16-y)*step, (x+2)*step, (16-y)*step, pen );


            if( e == 1 ) scene->addLine( (x+2)*step, (17-y)*step, (x+2)*step, (16-y)*step, pen );


            if( w == 1 ) scene->addLine( (x+1)*step, (17-y)*step, (x+1)*step, (16-y)*step, pen );


            if( s == 1 ) scene->addLine( (x+1)*step, (17-y)*step, (x+2)*step, (17-y)*step, pen );

        }
    }
}

void DrawMaze::drawMachine(QGraphicsScene *scene, uint8_t x, uint8_t y)
{
    int dx = 7+step;
    int dy = 17 * step - 35;
    int box_size = 30;

    QBrush brush(Qt::SolidPattern);
    QPen pen;

    pen.setColor(Qt::cyan);
    brush.setColor(Qt::cyan);

    dx += x * step;
    dy -= y * step;

    scene->addRect(dx, dy, box_size, box_size, pen, brush);
}

void DrawMaze::drawSimulate(QGraphicsScene *scene, uint8_t x, uint8_t y, uint8_t (*wall)[16])
{
    drawWall(scene, wall);
    drawMachine(scene, x, y);
}


