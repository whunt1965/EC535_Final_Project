#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QDebug>
#include <QLabel>
#include "fighter.h"

int characterSelect = 0;
int characterSelectTwo = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

   // this->progressBar = progressBar;
     ui->progressBar->setRange(0,20);
     ui->progressBar_2->setRange(0,20);

//    QGraphicsScene* scene = new QGraphicsScene();
//    ui->graphicsView->setScene(scene);

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
        p1Pics= {QPixmap(":/assets/lgLenny.png"), QPixmap(":/assets/lgkick.png"), QPixmap(":/assets/lgpunch.png"), QPixmap(":/assets/lgblock.png"), QPixmap(":/assets/lgflinch.png")};
       }
    if(characterSelect ==1){
        p1Pics= {QPixmap(":/assets/jimnormal.png"), QPixmap(":/assets/jimkick.png"),QPixmap(":/assets/jimpunch.png"),QPixmap(":/assets/jimblock.png"), QPixmap(":/assets/jimflinch.png")};
     }
    if(characterSelect ==2){
        p1Pics= {QPixmap(":/assets/surfer.png"), QPixmap(":/assets/surferkick.png"),QPixmap(":/assets/surferpunch.png"),QPixmap(":/assets/surferblock.png"), QPixmap(":/assets/surferflinch.png")};
     }
    if(characterSelect ==3){
        p1Pics= {QPixmap(":/assets/karen.png"), QPixmap(":/assets/karenkick.png"),QPixmap(":/assets/karenpunch.png"),QPixmap(":/assets/karenblock.png"),QPixmap(":/assets/karenflinch.png")};
     }


    if(characterSelectTwo ==0){
        p2Pics= {QPixmap(":/assets/lgLenny.png"), QPixmap(":/assets/lgkick.png"), QPixmap(":/assets/lgpunch.png"), QPixmap(":/assets/lgblock.png"), QPixmap(":/assets/lgflinch.png")};
       }
    if(characterSelectTwo ==1){
        p2Pics= {QPixmap(":/assets/jimnormal.png"), QPixmap(":/assets/jimkick.png"),QPixmap(":/assets/jimpunch.png"),QPixmap(":/assets/jimblock.png"), QPixmap(":/assets/jimflinch.png")};
     }
    if(characterSelectTwo ==2){
        p2Pics= {QPixmap(":/assets/surfer.png"), QPixmap(":/assets/surferkick.png"),QPixmap(":/assets/surferpunch.png"),QPixmap(":/assets/surferblock.png"), QPixmap(":/assets/surferflinch.png")};
     }
    if(characterSelectTwo ==3){
        p2Pics= {QPixmap(":/assets/karen.png"), QPixmap(":/assets/karenkick.png"),QPixmap(":/assets/karenpunch.png"),QPixmap(":/assets/karenblock.png"), QPixmap(":/assets/karenflinch.png")};
     }

    this->game = new Game(ui->graphicsView, p1Pics, p2Pics);
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_leftarrow_clicked()
{
    if(characterSelect !=0){
    characterSelect--;
    characterSelect =abs(characterSelect);
    characterSelect = characterSelect % 4;
    }

    changeCharacterImage();

}

void MainWindow::on_rightArrow_clicked()
{
    if(characterSelect != 3){
    characterSelect++;
    characterSelect = characterSelect %4;
    }
    changeCharacterImage();
}

void MainWindow::changeCharacterImage(){

    if(characterSelect ==0){
        ui->characterImg->setStyleSheet("image:url(:/assets/lifegaurd.png);");
         ui->playerOneSelect->setText(QString("LifeGuard Lenny"));
    }

    else if(characterSelect ==1){
        ui->characterImg->setStyleSheet("image:url(:/assets/foodtruckJim.png);");
        ui->playerOneSelect->setText(QString("Food Truck Jim"));
    }
    else if(characterSelect ==2){
        ui->characterImg->setStyleSheet("image:url(:/assets/surfer.png);");
        ui->playerOneSelect->setText(QString("Surfer Syd"));
    }
    else{
        ui->characterImg->setStyleSheet("image:url(:/assets/karen.png);");
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
    if(characterSelectTwo != 0){
    characterSelectTwo--;
    characterSelectTwo =abs(characterSelectTwo);
    characterSelectTwo = characterSelectTwo % 4;
    }

    changeCharacterImageTwo();

}

void MainWindow::on_rightArrow_2_clicked()
{
    if(characterSelectTwo != 3){
    characterSelectTwo++;
    characterSelectTwo = characterSelectTwo %4;
    ui->progressBar->setValue(20);
    }
    changeCharacterImageTwo();

}

void MainWindow::changeCharacterImageTwo(){

    if(characterSelectTwo ==0){
        ui->characterImg_2->setStyleSheet("image:url(:/assets/lifegaurd.png);");
        ui->playerTwoSelect->setText(QString("LifeGuard Lenny"));
    }

    else if(characterSelectTwo ==1){
        ui->characterImg_2->setStyleSheet("image:url(:/assets/foodtruckJim.png);");
        ui->playerTwoSelect->setText(QString("FoodTruck Jim"));
    }
    else if(characterSelectTwo ==2){
        ui->characterImg_2->setStyleSheet("image:url(:/assets/surfer.png);");
        ui->playerTwoSelect->setText(QString("Surfer Syd"));
    }
    else{
        ui->characterImg_2->setStyleSheet("image:url(:/assets/karen.png);");
        ui->playerTwoSelect->setText(QString("Karen"));
    }
}

void MainWindow::on_exitBtn_2_clicked(){
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_newGameButton_2_clicked(){
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_quitButton_2_clicked(){
    this->reset("No Winner");
}
