#ifndef GAME_H
#define GAME_H


#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "fighter.h"
#include "player1.h"
#include "player2.h"

class Game: public QGraphicsView{

public:
    Game(QGraphicsPixmapItem player1, QGraphicsPixmapItem player2);

    QGraphicsScene* scene;
    Player1* player1;
    Player2* player2;

};

#endif // GAME_H
