#ifndef PLAYER1_H
#define PLAYER1_H
#include "fighter.h"

class Player1: public Fighter
{
public:
    Player1();

    explicit Player1(int in_id, std::string fname, QPixmap pic);

    void keyPressEvent(QKeyEvent *event);

    void keyReleaseEvent(QKeyEvent *event);

};

#endif // PLAYER1_H
