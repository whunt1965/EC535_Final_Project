#include "timer.h"
#include <QDebug>

MyTimer::MyTimer(QGraphicsTextItem* timerLabel, Controller* controller)
{
    // create a timer
    timer = new QTimer(this);
    this->controller = controller;
    this->timerLabel = timerLabel;

    // setup signal and slot
    connect(timer, SIGNAL(timeout()),
          this, SLOT(MyTimerSlot()));

    // msec
    timer->start(1000);

    QString* timerguy = new QString();
    *timerguy ="2:00";


    timerLabel->setPlainText(*timerguy);
    timerLabel->setDefaultTextColor(Qt::black);//we can play with this color
    timerLabel->setFont(QFont("times",16));//and this font type and size


    seconds= 12;
}

void MyTimer::MyTimerSlot()
{
    seconds--;
    int outMinutes = seconds / 60;
    int outSeconds = seconds % 60;


    QString secondsremaining = QString::number(outMinutes) + ":" +  QString::number(outSeconds);
    timerLabel->setPlainText(secondsremaining);

    if(seconds == 0){
        controller->endGame();
    }
}
