#include "game.h"

Game::Game(QGraphicsView* view, QPixmap player1pic, QPixmap player2pic){

    QGraphicsScene* scene = new QGraphicsScene();
    view->setScene(scene);
//    view->setBackgroundBrush(QBrush(QImage("::/assets/beach.png")));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //Create items in scene
    player1 = new Fighter(0, "Guy", player1pic);
    player1->setPos(100,500);
//    player1->setFlag(QGraphicsItem::ItemIsFocusable);
//    player1->setFocus();

    player2 = new Fighter(1, "Guy2", player2pic);
    player2->setPos(700, 500);
//    player2->setFlag(QGraphicsItem::ItemIsFocusable);
//    player2->setFocus();




    //set opponents
    player1->setOpponent(player2);
    player2->setOpponent(player1);

    //add to scene
    scene->addItem(player1);
    scene->addItem(player2);

    //add scores here
    this->p1Score = new Score("Player1", player1->getHealth());
    p1Score->setPos(100, 900);
    this->p2Score = new Score("Player2", player2->getHealth());
    p2Score->setPos(700, 900);
    scene->addItem(p1Score);
    scene->addItem(p2Score);


    this->controller = new Controller(scene, player1, player2, p1Score, p2Score);
}

Game::~Game(){
    delete player1;
    delete player2;
    delete p1Score;
    delete p2Score;
    delete controller;
}
