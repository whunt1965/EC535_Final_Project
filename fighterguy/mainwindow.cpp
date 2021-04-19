#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QDebug>
#include <QLabel>
#include "fighter.h"

int characterSelect = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    QGraphicsScene* scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);

//    QPixmap mypix (":/assets/lifegaurd.png");
//    Fighter* fighter = new Player1(1, "Guy", mypix);
//    fighter->setOpponent(fighter);



}

MainWindow::~MainWindow()
{
    delete ui;
    delete game;
}

void MainWindow::reset(QString name){
    delete game;
    ui->winnerName->setText(name);
    ui->stackedWidget->setCurrentIndex(3);
}




void MainWindow::on_quitButton_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::on_newGameButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_FightButton_clicked()
{
    QPixmap mypix (":/assets/lifegaurd.png");

    if(characterSelect ==0){
        p1Pic= QPixmap(":/assets/lifegaurd.png");
        p2Pic= QPixmap(":/assets/foodtruckJim.png");

//    QGraphicsPixmapItem* item = ui->graphicsView->scene()->addPixmap(mypix);
//    item->setPixmap(mypix.scaled(200,400,Qt::KeepAspectRatio));
       }
    else{
       p1Pic= QPixmap(":/assets/foodtruckJim.png");
       p2Pic= QPixmap(":/assets/lifegaurd.png");
//       QGraphicsPixmapItem* item = ui->graphicsView->scene()->addPixmap(mypix);

//       item->setPixmap(mypix.scaled(200,400,Qt::KeepAspectRatio));
    }

    this->game = new Game(ui->graphicsView, p1Pic, p2Pic);


    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_leftarrow_clicked()
{
    characterSelect--;
    characterSelect =abs(characterSelect);
    characterSelect = characterSelect % 2;

    ui->playerOneSelect->setText(QString::number(characterSelect));
    changeCharacterImage();

}

void MainWindow::on_rightArrow_clicked()
{
    characterSelect++;
    characterSelect = characterSelect %2;
    ui->playerOneSelect->setText(QString::number(characterSelect));
    changeCharacterImage();
}

void MainWindow::changeCharacterImage(){

    if(characterSelect ==0){
        ui->characterImg->setStyleSheet("image:url(:/assets/lifegaurd.png);");
    }

    else if(characterSelect ==1){
        ui->characterImg->setStyleSheet("image:url(:/assets/foodtruckJim.png);");

    }
}

void MainWindow::on_newGameBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_exitBtn_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_mainMenuBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
