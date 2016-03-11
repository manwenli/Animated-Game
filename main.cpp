/** @file "main.cpp"
 *  @author Manwen Li, ID:104290095
 *  @brief Final Project, PIC 10C WINTER 2016

 * This Project creates a game scene of Godzilla shooting UFO's.
 *
*/





#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //set window title
    w.setWindowTitle("Godzilla: The Earth Protector");
    w.show();

    return a.exec();
}
