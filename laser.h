/** @file "laser.h"
 *  @author Manwen Li
 *  @brief Contains Laser class
 *
 * This file is to create Laser object shooting from UFO in fancy mode.
 */

#ifndef LASER_H
#define LASER_H
#include<QObject>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMediaPlayer>

/**class Laser
 * @brief generates laser mean dropping from ufo, decrease godzilla's energy by 35.
 * delete when laser reaches ground.
  */
class Laser: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    //constructor
    Laser();
    //destructor
    ~Laser(){};

public slots:
    //shoots fire when pressing space key.
    void shoot();

private:
    QTimer *timer;
    QMediaPlayer* sound;

};

#endif // LASER_H
