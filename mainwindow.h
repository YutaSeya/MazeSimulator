#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

#include "drawmaze.h"
#include "simulatemazerun.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_drawMazeButton_clicked();

    void on_loadButton_clicked();

    void on_SimulateStart_clicked();

    void on_quitButton_clicked();

private:
    Ui::MainWindow *ui;

    void init();

    void loadMazeData(QTextStream *maze_data, uint8_t wall_data[16][16]);

    uint8_t maze[16][16];

    QGraphicsScene *scene = new QGraphicsScene;

    DrawMaze *drawmaze;

    bool maze_read = false;

    SimulateMazeRun *simulate_run;
};

#endif // MAINWINDOW_H
