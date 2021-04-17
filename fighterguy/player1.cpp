#include "player1.h"

//Player 1 constructor
Player1::Player1(int in_id, QString fname, QPixmap pic)
    :Fighter(in_id, fname, pic){

}

//key press event handler
void Player1::keyPressEvent(QKeyEvent *event){

    //move left - A key - ensure don't move beyond 0 coord
    if(event->key() == Qt::Key_A){
        if(pos().x() > 0){
            this->moveLeft();
        }

    //move right - D key -- cannot move past opponent --need to tweak
    }else if(event->key() == Qt::Key_D){
        if(pos().x() + 10 >= this->opponent->pos().x()){
            this->moveRight();
        }

    //jump - W key
    }else if(event->key() == Qt::Key_W){
        this->jump();

    //block - S key
    }else if(event->key() == Qt::Key_S){
        this->block();

    //kick - C key
    }else if(event->key() == Qt::Key_C){
        this->kick();

    //punch - X key
    }else if(event->key() == Qt::Key_X){
        this->punch();
    }
}

//key release event handler
void Player1::keyReleaseEvent(QKeyEvent *event){

    //release block on key release
    if(event->key() == Qt::Key_S){
        this->unblock();
    }
}
