#ifndef GAME_H
#define GAME_H


#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "fighter.h"
#include "controller.h"
#include <QVector>
#include "timer.h"

class Game: public QGraphicsView{

public:

    /**
     * @brief Game - Constructor for Game Object
     * @param player1 - Player1 base image
     * @param player2 - Player2 base image
     */
    Game(QGraphicsView* view, const QVector<QPixmap> &player1, const QVector<QPixmap> &player2);

    //Destructor for Game
    ~Game();

    bool isPaused();//check pause state
    void togglePause();//toggle pause value


private:
    Fighter* player1;
    Fighter* player2;
    Controller* controller;
    QGraphicsScene* scene;
    MyTimer* timer;
    bool Paused;//boolean to indicate if game is paused

};

#endif // GAME_H
