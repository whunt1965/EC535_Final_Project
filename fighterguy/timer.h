#ifndef TIMER_H
#define TIMER_H


#include <QTimer>
#include <QString>
#include <QGraphicsTextItem>
#include <QFont>
#include "controller.h"

class MyTimer : public QObject
{
    Q_OBJECT
public:
    MyTimer(QGraphicsTextItem* timerLabel, Controller* controller);
    ~MyTimer();
    QTimer *timer;
    QGraphicsTextItem* timerLabel;

public slots:
    void MyTimerSlot();

private:
    int seconds;
    Controller* controller;

};
#endif // TIMER_H
