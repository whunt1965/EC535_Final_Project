#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QString>


class Score: public QGraphicsTextItem{

public:

    Score(QString pname);
    void setScore(int score);
    int getScore();

private:
    int score;//player health
    QString name;//player name

};

#endif // SCORE_H
