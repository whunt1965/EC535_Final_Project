#include "fighter.h"
#include<QtMath>

//default constructor
//need to add a location...
Fighter::Fighter()
    : name("default"),
      health(20),
      blocking(false){}

//parameterized constructor
//need to add a location...
Fighter::Fighter(const QString &fname, const QVector<QPixmap>& pics)
    : name(fname),
      pics(pics),
      health(20),
      blocking(false){

    setPixmap(pics[0].scaled(120,240,Qt::KeepAspectRatio));
}

//destructor - clean up dynamically allocated memory
Fighter::~Fighter(){
    delete timer;
    delete animationUp;
}

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
    setPixmap(pics[3].scaled(120,240,Qt::KeepAspectRatio));
    this->blocking = true;
}

//set blocking state to false
void Fighter::unblock(){
    setPixmap(pics[0].scaled(120,240,Qt::KeepAspectRatio));
    this->blocking = false;
}

//move a fighter in -x direction
void Fighter::moveLeft(){
    setPos(x()-16, y());
}

//move a fighter in +x direction
void Fighter::moveRight(){
    setPos(x()+16, y());
}


//make fighter jump 1 unit (up) in y direction
void Fighter::jump(){
    if(timer == nullptr || timer->state() == QTimeLine::NotRunning){
        delete timer;
        delete animationUp;
        timer = new QTimeLine(500);
        timer->setFrameRange(0, 100);
        animationUp = new QGraphicsItemAnimation;
        animationUp->setItem(this);
        animationUp->setTimeLine(timer);
        animationUp->setPosAt(.2, QPointF(x(), y()-50));
        animationUp->setPosAt(1, QPointF(x(), y()));
        timer->start();
    }
}

//Determines if an opponent is in range for an attack
bool Fighter::opponentInRange(){
    qreal xdist = qFabs(this->pos().x() - this->opponent->pos().x());
    qreal ydist = qFabs(this->pos().y() - this->opponent->pos().y());
    if(xdist <= 220 && ydist == 0){
        return true;
    }
    return false;
}

//Kick an opponent
void Fighter::kick(){
    setPixmap(pics[1].scaled(120,240,Qt::KeepAspectRatio));
    if (this->opponentInRange()){
        this->opponent->takeKick();
    }
}

//Punch an opponent
void Fighter::punch(){
    setPixmap(pics[2].scaled(120,240,Qt::KeepAspectRatio));   //.scaled(140,280,Qt::KeepAspectRatio));
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
     setPixmap(pics[4].scaled(120,240,Qt::KeepAspectRatio));
}

//take a punch
void Fighter::takePunch(){
    if(!this->isBlocking()){
        setPixmap(pics[4].scaled(120,240,Qt::KeepAspectRatio));
        this->health-=1;
    }
}

//reset to default image
void Fighter::reset(){
    setPixmap(pics[0].scaled(120,240,Qt::KeepAspectRatio));
}

//getter for opponent pointer
Fighter *Fighter::getOpponent(){
    return this->opponent;
}

QString Fighter::getName(){
    return name;
}
