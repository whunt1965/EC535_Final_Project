#include "fighter.h"
#include<QtMath>

//default constructor
//need to add a location...
Fighter::Fighter()
    : id(0),
      name("default"),
      health(20),
      blocking(false){}

//parameterized constructor
//need to add a location...
Fighter::Fighter(int in_id, QString fname)
    : id(in_id),
      name(fname),
      health(20),
      blocking(false){}

//sets a fighter's opponent
void Fighter::setOpponent(Fighter* opponent){
    this->opponent = opponent;
}

//indicates if a fighter is alive
bool Fighter::isAlive(){
    return this->health > 0;
}

//returns a fighter's health
int Fighter::getHealth(){
    return this->health;
}

//set blocking state to true
void Fighter::block(){
    this->blocking = true;
}

//set blocking state to false
void Fighter::unblock(){
    this->blocking = false;
}

//move a fighter in -x direction
void Fighter::moveLeft(){
    setPos(x()-10, y());
}

//move a fighter in +x direction
void Fighter::moveRight(){
    setPos(x()+10, y());
}


//make fighter jump 1 unit (up) in y direction
void Fighter::jump(){

    //TO-DO

}

//Determines if an opponent is in range for an attack
bool Fighter::opponentInRange(){
    //TO-DO
    qreal xdist = qFabs(this->pos().x() - this->opponent->pos().x());
    qreal ydist = qFabs(this->pos().y() - this->opponent->pos().y());
    if(xdist <= 10 && ydist == 0){
        return true;
    }
    return false;
}

//Kick an opponent
void Fighter::kick(){
    if (this->opponentInRange()){
        this->opponent->takeKick();
    }
}

//Punch an opponent
void Fighter::punch(){
    if (this->opponentInRange()){
        this->opponent->takePunch();
    }
}

//indicates if a fighter is blocking
bool Fighter::isBlocking(){
    return this->blocking;
}

//take a kick
void Fighter::takeKick(){
    this->isBlocking()? this->health-=1 : this->health -=2;
}

//take a punch
void Fighter::takePunch(){
    if(!this->isBlocking()){
        this->health-=1;
    }
}
