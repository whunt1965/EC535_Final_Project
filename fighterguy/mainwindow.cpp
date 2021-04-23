#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QDebug>
#include <QLabel>
#include "fighter.h"

int characterSelect = 1;
int characterSelectTwo = 1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    changeCharacterImage();
    changeCharacterImageTwo();

    ui->progressBar->setRange(0,20);
    ui->progressBar_2->setRange(0,20);
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

void MainWindow::updateProgress(int p1Score, int p2Score){
    ui->progressBar->setValue(p1Score);
    ui->progressBar_2->setValue(p2Score);
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
        p1Pics= {QPixmap(":/assets/lgLenny/lgLenny.png"), QPixmap(":/assets/lgLenny/lgkick.png"), QPixmap(":/assets/lgLenny/lgpunch.png"), QPixmap(":/assets/lgLenny/lgblock.png"), QPixmap(":/assets/lgLenny/lgflinch.png")};
       }
    if(characterSelect ==1){
        p1Pics= {QPixmap(":/assets/foodTruckJim/jimnormal.png"), QPixmap(":/assets/foodTruckJim/jimkick.png"),QPixmap(":/assets/foodTruckJim/jimpunch.png"),QPixmap(":/assets/foodTruckJim/jimblock.png"), QPixmap(":/assets/foodTruckJim/jimflinch.png")};
     }
    if(characterSelect ==2){
        p1Pics= {QPixmap(":/assets/surfer/surfer.png"), QPixmap(":/assets/surfer/surferkick.png"),QPixmap(":/assets/surfer/surferpunch.png"),QPixmap(":/assets/surfer/surferblock.png"), QPixmap(":/assets/surfer/surferflinch.png")};
     }
    if(characterSelect ==3){
        p1Pics= {QPixmap(":/assets/karen/karen.png"), QPixmap(":/assets/karen/karenkick.png"),QPixmap(":/assets/karen/karenpunch.png"),QPixmap(":/assets/karen/karenblock.png"),QPixmap(":/assets/karen/karenflinch.png")};
     }


    if(characterSelectTwo ==0){
        p2Pics= {QPixmap(":/assets/lgLenny/lgLenny.png"), QPixmap(":/assets/lgLenny/lgkick.png"), QPixmap(":/assets/lgLenny/lgpunch.png"), QPixmap(":/assets/lgLenny/lgblock.png"), QPixmap(":/assets/lgLenny/lgflinch.png")};
       }
    if(characterSelectTwo ==1){
        p2Pics= {QPixmap(":/assets/foodTruckJim/jimnormal.png"), QPixmap(":/assets/foodTruckJim/jimkick.png"),QPixmap(":/assets/foodTruckJim/jimpunch.png"),QPixmap(":/assets/foodTruckJim/jimblock.png"), QPixmap(":/assets/foodTruckJim/jimflinch.png")};
     }
    if(characterSelectTwo ==2){
        p2Pics= {QPixmap(":/assets/surfer/surfer.png"), QPixmap(":/assets/surfer/surferkick.png"),QPixmap(":/assets/surfer/surferpunch.png"),QPixmap(":/assets/surfer/surferblock.png"), QPixmap(":/assets/surfer/surferflinch.png")};
     }
    if(characterSelectTwo ==3){
        p2Pics= {QPixmap(":/assets/karen/karen.png"), QPixmap(":/assets/karen/karenkick.png"),QPixmap(":/assets/karen/karenpunch.png"),QPixmap(":/assets/karen/karenblock.png"), QPixmap(":/assets/karen/karenflinch.png")};
     }

    this->game = new Game(ui->graphicsView, p1Pics, p2Pics);
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_leftarrow_clicked()
{
    if(characterSelect == 0){
        characterSelect = 3;
    }else{
       characterSelect--;
    }

    changeCharacterImage();

}

void MainWindow::on_rightArrow_clicked()
{
    if(characterSelect == 3){
        characterSelect = 0;
    }else{
       characterSelect++;
    }
    changeCharacterImage();
}

void MainWindow::changeCharacterImage(){

    if(characterSelect ==1){
        qDebug() << "Character 1" << characterSelect;
        ui->characterImg->setStyleSheet("image:url(:/assets/lgLenny/lifegaurd.png);");
         ui->playerOneSelect->setText(QString("LifeGuard Lenny"));
    }

    else if(characterSelect ==2){
         qDebug() << "Character 2" << characterSelect;
         ui->characterImg->setStyleSheet("image:url(:/assets/foodTruckJim/foodtruckJim.png);");
         ui->playerTwoSelect->setText(QString("FoodTruck Jim"));
    }
     else if(characterSelect ==3){
         qDebug() << "Character 3" << characterSelect;
        ui->characterImg->setStyleSheet("image:url(:/assets/surfer/surfer.png);");
        ui->playerOneSelect->setText(QString("Surfer Syd"));
    }
    else{
         qDebug() << "Character 0" << characterSelect;
        ui->characterImg->setStyleSheet("image:url(:/assets/karen/karen.png);");
        ui->playerOneSelect->setText(QString("Karen"));
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

void MainWindow::on_leftarrow_2_clicked()
{
    if(characterSelectTwo == 0){
        characterSelectTwo = 3;
    }else{
       characterSelectTwo--;
    }

    changeCharacterImageTwo();

}

void MainWindow::on_rightArrow_2_clicked()
{
    if(characterSelectTwo == 3){
        characterSelectTwo = 0;
    }else{
       characterSelectTwo++;
    }
    changeCharacterImageTwo();

}

void MainWindow::changeCharacterImageTwo(){

    if(characterSelectTwo ==1){
        qDebug() << "CharacterTwo 1" << characterSelectTwo;
        ui->characterImg_2->setStyleSheet("image:url(:/assets/lgLenny/lifegaurd.png);");
        ui->playerTwoSelect->setText(QString("LifeGuard Lenny"));
    }

     else if(characterSelectTwo ==2){
         qDebug() << "CharacterTwo 2" << characterSelectTwo;
        ui->characterImg_2->setStyleSheet("image:url(:/assets/foodTruckJim/foodtruckJim.png);");
        ui->playerTwoSelect->setText(QString("FoodTruck Jim"));
    }
     else if(characterSelectTwo ==3){
         qDebug() << "CharacterTwo 3" << characterSelectTwo;
        ui->characterImg_2->setStyleSheet("image:url(:/assets/surfer/surfer.png);");
        ui->playerTwoSelect->setText(QString("Surfer Syd"));
    }
    else{
         qDebug() << "CharacterTwo 0" << characterSelectTwo;
        ui->characterImg_2->setStyleSheet("image:url(:/assets/karen/karen.png);");
        ui->playerTwoSelect->setText(QString("Karen"));
    }
}


void MainWindow::on_newGameButton_2_clicked(){
    ui->stackedWidget->setCurrentIndex(4);

}

//In-game Quit button
void MainWindow::on_quitButton_2_clicked(){
    this->reset("No Winner");
}

//Back to menu button on instructions page
void MainWindow::on_instrucToMenubtn_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
}
