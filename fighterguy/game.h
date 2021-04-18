#ifndef GAME_H
#define GAME_H


#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "fighter.h"
#include "score.h"
#include "controller.h"

class Game: public QGraphicsView{

public:

    /**
     * @brief Game - Constructor for Game Object
     * @param player1 - Player1 base image
     * @param player2 - Player2 base image
     */
    Game(QGraphicsView* view, QPixmap player1, QPixmap player2);

    //Destructor for Game
    ~Game();


private:
    Fighter* player1;
    Fighter* player2;
    Score* p1Score;
    Score* p2Score;
    Controller* controller;

};

#endif // GAME_H
