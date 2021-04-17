#ifndef CONTROLLLER_H
#define CONTROLLLER_H
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QObject>
#include "fighter.h"

class Controlller: public QObject{
      Q_OBJECT
public:

    Controlller(QGraphicsScene* scene, Fighter* P1, Fighter* P2);

    void handleKeyPressEvent(QKeyEvent *event);

    void handleKeyReleaseEvent(QKeyEvent *event);

    bool eventFilter(QObject *object, QEvent *event);

private:
    QGraphicsScene* scene;
    Fighter* Player1;
    Fighter* Player2;


};

#endif // CONTROLLLER_H
