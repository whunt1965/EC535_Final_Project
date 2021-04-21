#include "game.h"

Game::Game(QGraphicsView* view, const QVector<QPixmap> &player1pics, const QVector<QPixmap> &player2pics){

    scene = new QGraphicsScene();
    view->setScene(scene);

    QPixmap backgroundPic (":/assets/beachsmall.png");


//    QPixmap mypix (":/assets/lifegaurd.png");
    QGraphicsPixmapItem* item =view->scene()->addPixmap(backgroundPic);
    item->setPos(0, 0);


    //Create fighters
    player1 = new Fighter("Player 1", player1pics);
    player1->setPos(30,100);

    player2 = new Fighter("Player 2", player2pics);

    //Flips Fighter2 image
    QTransform transform;
    transform.scale(-1,1);
    player2->setTransform(transform);
    player2->setPos(440, 100);


    //set fighter opponents
    player1->setOpponent(player2);
    player2->setOpponent(player1);

    //add to fighters to scene
    scene->addItem(player1);
    scene->addItem(player2);

    //setup controller
    this->controller = new Controller(scene, player1, player2);

    //Initialize timer
    QGraphicsTextItem* gameTimer = new QGraphicsTextItem();
    timer = new MyTimer(gameTimer, this->controller);
    gameTimer->setPos(240, 20);
    scene->addItem(gameTimer);

}


Game::~Game(){
    delete player1;
    delete player2;
    delete scene;
    delete timer;
    delete controller;
}
