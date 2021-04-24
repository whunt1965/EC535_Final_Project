#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void reset(QString name);//Ends game and displays winner

    void updateProgress(int p1Score, int p2Score);//Updates progress bars

    void setPauseLabel(bool isVisible);//Toggle visibility of pause label for game
    Game* game = nullptr;

private slots:

    //Quit button for main menu
    void on_quitButton_clicked();

    //New Game button for main menu
    void on_newGameButton_clicked();

    //Starts a new game
    void on_FightButton_clicked();

    //Left arrow for Player1 character select
    void on_leftarrow_clicked();

    //Right arrow for Player1 character select
    void on_rightArrow_clicked();

    //Updates image for Player1's character
    void changeCharacterImage();

    //Start new game from game over screen
    void on_newGameBtn_clicked();

    //exit button from game over screen
    void on_exitBtn_clicked();

    //Navigate to main menu from fighter select screen
    void on_mainMenuBtn_clicked();

    //left arrow for Player2 character select
    void on_leftarrow_2_clicked();

    //right arrow for Player2 character select
    void on_rightArrow_2_clicked();

    //Updates image for Player2's character
    void changeCharacterImageTwo();

    //Button to navigate from main menu to instructions page
    void on_newGameButton_2_clicked();

    //in-game quit button -- returns to main menu
    void on_quitButton_2_clicked();

    //back button from instructions page to main menu
    void on_instrucToMenubtn_clicked();


private:
    Ui::MainWindow *ui;
    QVector<QPixmap> p1Pics;
    QVector<QPixmap> p2Pics;

};
#endif // MAINWINDOW_H
