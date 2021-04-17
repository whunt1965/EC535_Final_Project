#include "game.h"




Game::Game(QGraphicsScene *scene, QPixmap player1pic, QPixmap player2pic)
    :scene(scene){

    //Create items in scene
    this->player1 = new Player1(0, "Guy", player1pic);
    player1->setPos(100,500);
    player1->setFlag(QGraphicsItem::ItemIsFocusable);
    player1->setFocus();

    this->player2 = new Player2(1, "Guy2", player2pic);
    player2->setPos(700, 500);
    player2->setFlag(QGraphicsItem::ItemIsFocusable);
    player2->setFocus();

    //set opponents
    player1->setOpponent(player2);
    player2->setOpponent(player1);

    //add to scene
    scene->addItem(player1);
    scene->addItem(player2);

    //add scores here

     show();




}

Game::~Game(){
    delete this->player1;
    delete this->player2;
    delete this->p1Score;
    delete this->p2Score;
}
