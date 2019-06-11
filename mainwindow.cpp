#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;

    delete drawmaze;
    delete simulate_run;
}

void MainWindow::init()
{
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint);

    scene = new QGraphicsScene;

    ui->filePathEdit->setReadOnly(true);

    ui->actionHistoryEdit->setReadOnly(true);

    for(int i = 0; i < 16; i++) {
        for(int j =0; j < 16; j++ ){
            maze[i][j] = 0;
        }
    }

    drawmaze = new DrawMaze();

    simulate_run = new SimulateMazeRun();
    simulate_run->setGoal(7,7);

    drawmaze->init(scene);

    ui->graphicsView->setScene(scene);

}

void MainWindow::on_drawMazeButton_clicked()
{
    drawmaze->drawWall(scene, maze);

    ui->graphicsView->setScene(scene);

    QMessageBox *box = new QMessageBox;
    box->setText("You push draw Maze Button");
    box->exec();

}

void MainWindow::on_loadButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text File (*.txt);;"));

    if ( !fileName.isEmpty() ){
        QFile file(fileName);
        if ( !file.open(QIODevice::ReadOnly)){
            QMessageBox::critical(this, tr("Error"), tr("This System could not open File"));
            return;
        }

        ui->filePathEdit->setText(fileName);

        QTextStream stream(&file);

        loadMazeData(&stream, maze );

        maze_read = true;

    } else {
        ui->actionHistoryEdit->setText("Not Exsit File");
    }

}

void MainWindow::loadMazeData(QTextStream *maze_data, uint8_t (*wall_data)[16])
{
    for ( uint8_t x = 0; x < 16; x++ ){
        QString str = maze_data->readLine();
        QList<QString> list = str.split(" ");
        for ( uint8_t y = 0; y < 16; y++ ){
            wall_data[x][y] = list[y].toInt();
        }
    }

}

void MainWindow::on_SimulateStart_clicked()
{
    if(maze_read){
        simulate_run->copyNowMazeData(maze);
        simulate_run->leftHandSearch(scene);
        ui->graphicsView->setScene(scene);
    } else {
        ui->actionHistoryEdit->setText("Not Include Maze Data");
    }
}

void MainWindow::on_quitButton_clicked()
{
    qApp->quit();
}
