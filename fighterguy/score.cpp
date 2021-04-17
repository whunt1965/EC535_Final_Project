#include "score.h"
#include <QFont>


//Score constructor
Score::Score(QString pname, int score)
    :score(score),
     name(pname){

    //Create Text Item
    setPlainText(this->name + QString(" health:") + QString::number(this->score));
    setDefaultTextColor(Qt::black);//we can play with this color
    setFont(QFont("times",16));//and this font type and size

}

//Setter for score
void Score::setScore(int score){
    this->score = score;
    setPlainText(this->name + QString(" health:") + QString::number(this->score));


}

//Getter for score
int Score::getScore(){
    return this->score;
}
