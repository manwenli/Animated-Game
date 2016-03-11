/** @file "ghost.h"
 *  @author Manwen Li
 *  @brief Contains Ghost class
 *
 * This file is to create Ghost object to be displayed on game scene.
 */
#ifndef GHOST_H
#define GHOST_H
#include<QObject>
#include<QGraphicsItem>
#include <QTimer>
#include "energy.h"
#include<QMediaPlayer>

/** class Ghost
 *  @brief generates ghost
 *  ghost falling and provides godzilla energy when colliding
 */
class Ghost:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    //constructor
    Ghost(QGraphicsItem *parent=0);

    //destructor
    ~Ghost(){};
public slots:
    //ghost drop
    void drop();
private:
    QTimer* timer;
    QMediaPlayer* sound;

};

#endif // GHOST_H
