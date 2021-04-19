#include "game.h"

Game::Game(QGraphicsView* view, QPixmap player1pic, QPixmap player2pic){

    scene = new QGraphicsScene();
    view->setScene(scene);

    QPixmap backgroundPic (":/assets/beach.png");


//    QPixmap mypix (":/assets/lifegaurd.png");
    QGraphicsPixmapItem* item =view->scene()->addPixmap(backgroundPic);
    item->setPos(0, 0);

//    item->setPixmap(backgroundPic.scaled(200,200,Qt::KeepAspectRatio));

  //  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
 //   setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
 //   setFixedSize(800,600);


    //Create fighters
    player1 = new Fighter("Player 1", player1pic);
    player1->setPos(50,220);

    player2 = new Fighter("Player 2", player2pic);
    player2->setPos(600, 220);

    //set fighter opponents
    player1->setOpponent(player2);
    player2->setOpponent(player1);

    //add to fighters to scene
    scene->addItem(player1);
    scene->addItem(player2);

    this->controller = new Controller(scene, player1, player2);

    //Initialize timer
    QGraphicsTextItem* gameTimer = new QGraphicsTextItem();
    timer = new MyTimer(gameTimer, this->controller);
    gameTimer->setPos(350, 60);
    scene->addItem(gameTimer);

}


Game::~Game(){
    delete player1;
    delete player2;
    delete scene;
    delete timer;
    delete controller;
}
