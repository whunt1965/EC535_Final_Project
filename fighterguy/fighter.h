#ifndef FIGHTER_H
#define FIGHTER_H

#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include <QString>

/**
 * @brief The Fighter class
 */
class Fighter: public QGraphicsPixmapItem
{
public:

    /*Default Constructor*/
    Fighter();

    /**
     * @brief Constructor for a fighter
     * @param in_id - The fighter's id
     * @param fname - The fighter's name
     * @param pic -- An Array of pictures for fighter animations
     */
    explicit Fighter(int in_id, QString fname, QPixmap& pic);

    /*Destructor*/
    ~Fighter(){};

    /**
     * @brief setOpponent - sets the fighter's opponent
     * @param opponent - the opposing fighter
     */
    void setOpponent(Fighter* opponent);

    /**
     * @brief isAlive
     * @return True is the fighter's health is greater than 0 and false otherwise
     */
    bool isAlive();

    /**
     * @brief getHealth
     * @return The fighter's health
     */
    int getHealth();

    /**
     * @brief block - sets fighter's blocking state to True
     */
    void block();

    /**
     * @brief unblock - sets fighter's blocking state to False
     */
    void unblock();

    /**
     * @brief moveLeft - moves a fighter 1 unit in the positive or negative x
     */
    void moveLeft();

    /**
     * @brief moveRight - moves a fighter 1 unit in the positive or negative x
     */
    void moveRight();

    /**
     * @brief jump - causes a fighter to jump 1 unit in the positive y direction
     */
    void jump();

    /**
     * @brief inRange - Determines if an opponent is in range for an attack
     * @return True if the opponent is in range and false otherwise
     */
    bool opponentInRange();

    /**
     * @brief kick - executes a kick attack against an opponent is the opponent is in range
     * @param opponent - a pointer to the other fighter to be kicked
     */
    void kick();

    /**
     * @brief punch- executes a punch attack against an opponent is the opponent is in range
     * @param opponent - a pointer to the other fighter to be punched
     */
    void punch();

    /**
     * @brief isBlocking - indicates whether a fighter is blocking
     * @return True if a fighter is blocking and false otherwise
     */
    bool isBlocking();

    /**
     * @brief takePunch if this fighter is blocking, health decrements by 1. Else, health decrements by 2
     */
    void takeKick();

    /**
     * @brief takePunch if this fighter is blocking, health remains unchanged. Else, health decrements by 1
     */
    void takePunch();

    /**
     * @brief getOpponent - returns a pointer to the Fighter's opponent
     * @return a pointer to this fighter's opponent
     */
    Fighter* getOpponent();

    //getter for fighter name
    QString getName();


private:
    int id;//Fighter's ID
    QString name;//Fighter's name
    int health;//a fighter's health - default is 20
    bool blocking;//boolean indeictaing if the fighter is blocking
    Fighter* opponent = nullptr;//Fighter's opponent

    //also need some sort of position...

};

#endif // FIGHTER_H
