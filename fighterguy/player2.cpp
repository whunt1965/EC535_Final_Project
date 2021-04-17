#include "player2.h"
#include <QGraphicsScene>


//constructor
Player2::Player2(int in_id, QString fname, QPixmap pic)
    :Fighter(in_id, fname){
    setPixmap(pic);

}

//key press event handler
void Player2::keyPressEvent(QKeyEvent *event){

    //move left - J key - ensure can't move past opponent -- need to play with
    if(event->key() == Qt::Key_J){
        if(pos().x() >= this->opponent->pos().x() + 10){
            this->moveLeft();
        }

    //move right - L key -- cannot move out of scene --need to tweak
    }else if(event->key() == Qt::Key_L){
        if(pos().x() + 10 < scene()->width()){
            this->moveRight();
        }

    //jump - I key
    }else if(event->key() == Qt::Key_I){
        this->jump();

    //block - K key
    }else if(event->key() == Qt::Key_K){
        this->block();

    //kick - N key
    }else if(event->key() == Qt::Key_N){
        this->kick();

    //punch - M key
    }else if(event->key() == Qt::Key_M){
        this->punch();
    }

}

//key release event handler
void Player2::keyReleaseEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_K){
            this->unblock();
    }

}
