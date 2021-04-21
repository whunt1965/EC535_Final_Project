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

    timerLabel->setPlainText("1:30");
    timerLabel->setDefaultTextColor(Qt::black);//we can play with this color
    timerLabel->setFont(QFont("times",16));//and this font type and size


    seconds= 90;
}

MyTimer::~MyTimer(){
    delete timer;

}

void MyTimer::pause(){
    int remaining = timer->remainingTime();
    timer->stop();
    timer->setInterval(remaining);
 }

void MyTimer::resume(){
    timer->start();
}

void MyTimer::MyTimerSlot()
{
    seconds--;
    int outMinutes = seconds / 60;
    int outSeconds = seconds % 60;

    //Normalize display so seconds have leading 0 if less than 10 (ie, mm:09 vs mm:9)
    if(outSeconds < 10){
        QString secondsremaining = QString::number(outMinutes) + ":0" +  QString::number(outSeconds);
        timerLabel->setPlainText(secondsremaining);
    }else{
        QString secondsremaining = QString::number(outMinutes) + ":" +  QString::number(outSeconds);
        timerLabel->setPlainText(secondsremaining);
    }

    if(seconds == 0){
        controller->timeUp();
    }
}
