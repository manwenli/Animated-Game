/** @file mainwindow.cpp
 *  @author Manwen Li
 *  @brief implementation for the main window of the program
 *
 *  Contains the declarations for the various member functions which generates welcome interface.
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPushButton>
#include <QGraphicsScene>
#include <QWidget>
#include"game.h"

Game* lets_game;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    /*
   QLabel* background=new QLabel;
   background->setPixmap(QPixmap(":/new/images/player.jpg"));
   background->show();
*/

    delete ui;
}


void MainWindow::move_gzl()
{
    ui->label_5->move(50,190);
}

void MainWindow::move_ghost()
{
    ui->label_4->move(20,10);
    ui->label_3->move(550,30);
}

void MainWindow::move_ufo()
{
    ui->label_3->move(250,30);

}

/**function starts in basic mode of game
 * @brief MainWindow::game_basic only one type of ufo and ghost.
 */
void MainWindow::game_basic()
{
    lets_game=new Game(this, true, false);
    this->setCentralWidget(lets_game);
    this->setFixedSize(700,650);
    lets_game->show();
}

/**function starts in fancy mode of game
 * @brief MainWindow::game_fancy only one type of ufo and ghost.
 */
void MainWindow::game_fancy()
{
    lets_game=new Game(this, false, true);
    this->setCentralWidget(lets_game);
    this->setFixedSize(700,650);
    lets_game->show();
}



void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
