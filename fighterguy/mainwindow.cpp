#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);


    ui->stackedWidget->setCurrentIndex(0);


  //  QPixmap pix(":/assets/beach.png");
   // ui->stackedWidget->Qwidget->menu->background_2->setPixmap(pix);
    //   ui->widget->menu->background->setPixmap(pix);




}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_quitButton_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::on_newGameButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
