#include "fighter.h"

//default constructor
//need to add a location...
Fighter::Fighter()
    : id(0),
      name("default"),
      health(20),
      blocking(false){}

//parameterized constructor
//need to add a location...
Fighter::Fighter(int in_id, std::string fname)
    : id(in_id),
      name(fname),
      health(20),
      blocking(false){}

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

//move a fighter in x direction
void Fighter::move(){

    //TO-DO

}

//make fighter jump 1 unit (up) in y direction
void Fighter::jump(){

    //TO-DO

}

//Determines if an opponent is in range for an attack
bool Fighter::inRange(Fighter* opponent){

    //TO-DO

    return true;
}

//Kick an opponent
void Fighter::kick(Fighter* opponent){

    //TO-DO
}

//Punch an opponent
void Fighter::punch(Fighter* opponent){

    //TO-DO

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
