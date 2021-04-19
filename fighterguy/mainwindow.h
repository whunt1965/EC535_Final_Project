#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void reset(QString name);

private slots:

    void on_quitButton_clicked();

    void on_newGameButton_clicked();

    void on_FightButton_clicked();

    void on_leftarrow_clicked();

    void on_rightArrow_clicked();

    void changeCharacterImage();

    void on_newGameBtn_clicked();

    void on_exitBtn_clicked();

    void on_mainMenuBtn_clicked();

private:
    Ui::MainWindow *ui;
    Game* game = nullptr;
    QPixmap p1Pic;
    QPixmap p2Pic;

};
#endif // MAINWINDOW_H
