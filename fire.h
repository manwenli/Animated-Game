/** @file "fire.h"
 *  @author Manwen Li
 *  @brief Contains Fire class
 *
 * This file is to create Fire object to be displayed on game scene when player press space key.
 */
#ifndef FIRE_H
#define FIRE_H
#include<QObject>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QTimer>

/**class Fire
 * @brief generates fire shooting to the ufo
 * destroys ufo when colliding.
  */
class Fire: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    //constructor
    Fire();
    //destructor
    ~Fire(){};

public slots:
    //shoots fire when pressing space key.
    void shoot();

private:
    QTimer *timer;


};

#endif // FIRE_H
