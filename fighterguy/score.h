#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QString>


class Score: public QGraphicsTextItem{

public:
    /**
     * @brief Score - Constructor for score
     * @param pname - Player name tied to score
     */
    Score(QString pname);

    /**
     * @brief setScore - Setter for score
     * @param score - The new Score
     */
    void setScore(int score);

    /**
     * @brief getScore - Getter for Score
     * @return score
     */
    int getScore();

private:
    int score;//player health
    QString name;//player name

};

#endif // SCORE_H
