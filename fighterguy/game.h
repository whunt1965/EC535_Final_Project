#ifndef GAME_H
#define GAME_H


#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "fighter.h"
#include "player1.h"
#include "player2.h"
#include "score.h"

class Game: public QGraphicsView{

public:

    /**
     * @brief Game - Constructor for Game Object
     * @param player1 - Player1 base image
     * @param player2 - Player2 base image
     */
    Game(QGraphicsPixmapItem player1, QGraphicsPixmapItem player2);

    //Destructor for Game
    ~Game();

    QGraphicsScene* scene;
    Player1* player1;
    Player2* player2;
    Score* p1Score;
    Score* p2Score;

};

#endif // GAME_H
