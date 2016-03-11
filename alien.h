/** @file "alien.h"
 *  @author Manwen Li
 *  @brief Contains Alien class
 *
 * This file is to create vicious green aliens when ufo's fall on ground.
 */

#ifndef ALIEN_H
#define ALIEN_H
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QMediaPlayer>
/** class Alien
 * @brief creates an alien each time a ufo drops on the ground or collides with godzilla.
 * aliens moves horizontally to attack godzilla
 */
class Alien:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    //constructor
    Alien(QGraphicsItem* parent=0);

    //destructor
    ~Alien(){};


public slots:
    //aliens move from right to left
    void move_to_left();
    //aliens move from left to right
    void move_to_right();
private:
    //timer for move
   QTimer* timer;
   QTimer* timer2;
   QMediaPlayer* sound;
};

#endif // ALIEN_H
