#ifndef CONTROLLLER_H
#define CONTROLLLER_H
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QObject>
#include "fighter.h"
#include "score.h"

class Controller: public QObject{
      Q_OBJECT
public:

    Controller(QGraphicsScene* scene, Fighter* P1, Fighter* P2, Score *P1S, Score *P2S);

    void handleKeyPressEvent(QKeyEvent *event);

    void handleKeyReleaseEvent(QKeyEvent *event);

    void update();

    void endGame();

    bool eventFilter(QObject *object, QEvent *event);

private:
    QGraphicsScene* scene;
    Fighter* Player1;
    Fighter* Player2;
    Score* P1Score;
    Score* P2Score;


};

#endif // CONTROLLLER_H
