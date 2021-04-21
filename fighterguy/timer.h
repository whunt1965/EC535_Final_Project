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

    //citation for implementing pause/resume behavior: https://stackoverflow.com/questions/35794617/how-to-pause-and-restart-the-qtimer-on-qt/35794807
    void pause();//pause timer
    void resume();//resume timer

public slots:
    void MyTimerSlot();

private:
    int seconds;
    Controller* controller;

};
#endif // TIMER_H
