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

    Fighter* fighter = new Fighter(1, "Guy");

    QGraphicsRectItem* rect = new QGraphicsRectItem();
    rect->setRect(0,0,200,200);
    scene->addItem(rect);





    qDebug() << "Main window!";

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
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_leftarrow_clicked()
{
    characterSelect--;
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
