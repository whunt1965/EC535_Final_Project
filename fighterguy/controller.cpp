#include "controller.h"


Controller::Controller(QGraphicsScene* scene, Fighter *P1, Fighter *P2)
    : scene(scene),
      Player1(P1),
      Player2(P2){
        scene->installEventFilter(this);

}

//key press event handler
void Controller::handleKeyPressEvent(QKeyEvent *event){


    switch(event->key()){

        /********* Player 1 Keys ********/
        case Qt::Key_A:{ //Player 1 move left - A key - ensure don't move beyond 0 coord
            if(Player1->pos().x() -100 > 0){
                Player1->moveLeft();
            }
            break;
        }

        case Qt::Key_D:{//Player1 move right - D key -- cannot move past opponent --need to tweak
            if(Player1->pos().x() + 210 <= Player1->getOpponent()->pos().x()){
                Player1->moveRight();
            }
            break;
        }

        case Qt::Key_W:{//Player 1 jump - W key
            Player1->jump();
            break;
        }

        case Qt::Key_S:{//Player1 block - S key
            Player1->block();
            break;
        }

        case Qt::Key_C:{//Player1 kick - C key
            Player1->kick();
            break;
        }

        case Qt::Key_X:{//Player1 punch - X key
            Player1->punch();
            break;
        }

        /********* Player 2 Keys ********/
        case Qt::Key_J:{ //Player 2 move left - J key - ensure don't move beyond opponent
            if(Player2->pos().x() >= Player2->getOpponent()->pos().x() + 210){
                Player2->moveLeft();
            }
            break;
        }

        case Qt::Key_L:{//Player2 move right - L key -- cannot move out of scene --need to tweak
            if(Player2->pos().x() + 100 < 800){
                Player2->moveRight();
            }
            break;
        }

        case Qt::Key_I:{//Player 2 jump - I key
            Player2->jump();
            break;
        }

        case Qt::Key_K:{//Player2 block - K key
            Player2->block();
            break;
        }

        case Qt::Key_N:{//Player2 kick - N key
            Player2->kick();
            break;
        }

        case Qt::Key_M:{//Player2 punch - M key
            Player2->punch();
            break;
        }

        default: break;

  }

}

//key release event handler
void Controller::handleKeyReleaseEvent(QKeyEvent *event){

    switch(event->key()){

        /********* Player 1 Keys ********/

        case Qt::Key_S:{    //Player1 unblock - release S key
            Player1->unblock();
            break;
        }
        /********* Player 2 Keys ********/

        case Qt::Key_K:{    //Player2 unblock - release K key
            Player2->unblock();
            break;
        }
        default: break;
  }
}

//event filter
bool Controller::eventFilter(QObject *object, QEvent *event){

    if (event->type() == QEvent::KeyPress) {
        handleKeyPressEvent((QKeyEvent *)event);
        return true;
    } else if (event->type() == QEvent::KeyRelease) {
        handleKeyReleaseEvent((QKeyEvent *)event);
        return true;
    }else {
        return QObject::eventFilter(object, event);
    }

}
