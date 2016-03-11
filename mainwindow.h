/** @file mainwindow.h
 *  @author Manwen Li
 *  @brief declaration for the main window of the program
 *
 *  Contains the declarations for the various member functions which generates welcome interface.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"game.h"
#include"godzilla.h"

namespace Ui {
class MainWindow;
}


/** @class MainWindow
 *  @brief The main window of the program
 *
 * This class contains all of the slots for use with the GUI widgets.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    //for greeting window
    void move_gzl();
    void move_ghost();
    void move_ufo();

    //choose mode
    void game_basic();
    void game_fancy();


private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::MainWindow *ui;
    Godzilla* godzilla;
};

#endif // MAINWINDOW_H
