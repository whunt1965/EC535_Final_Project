#ifndef PLAYER2_H
#define PLAYER2_H
#include "fighter.h"


class Player2: public Fighter
{
public:
    Player2();

    explicit Player2(int in_id, QString fname, QPixmap pic);

    void keyPressEvent(QKeyEvent *event);

    void keyReleaseEvent(QKeyEvent *event);
};

#endif // PLAYER2_H
