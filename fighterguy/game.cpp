#include "game.h"
#include <QBrush>
#include <QImage>




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

    this->controller = new Controller(scene, player1, player2);



    //set opponents
    player1->setOpponent(player2);
    player2->setOpponent(player1);

    //add to scene
    scene->addItem(player1);
    scene->addItem(player2);

    //add scores here




}

Game::~Game(){
    delete player1;
    delete player2;
    delete p1Score;
    delete p2Score;
    delete controller;
}
