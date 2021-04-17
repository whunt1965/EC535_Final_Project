#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QDebug>
#include <QLabel>
#include "fighter.h"
#include "player1.h"

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

    if(characterSelect ==0){
    QPixmap mypix (":/assets/lifegaurd.png");
    QGraphicsPixmapItem* item = ui->graphicsView->scene()->addPixmap(mypix);
    item->setPixmap(mypix.scaled(200,400,Qt::KeepAspectRatio));
       }
    else{
       QPixmap mypix (":/assets/foodtruckJim.png");
       QGraphicsPixmapItem* item = ui->graphicsView->scene()->addPixmap(mypix);

       item->setPixmap(mypix.scaled(200,400,Qt::KeepAspectRatio));
    }


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
