/** @file "ufo_speed.h"
 *  @author Manwen Li
 *  @brief Contains Ufo_s class
 *
 * This file is to create dangerous ufo object to be displayed on game scene in fancy mode.
 */
#ifndef UFO_SPEED_H
#define UFO_SPEED_H
#include <QObject>
#include <QGraphicsItem>
#include "level.h"
#include <QMediaPlayer>

/**class Ufo_speed
 * @brief one of the mysterious ufo's in fancy mode. This is the evil ufo that can make other ufo's dropping faster.
  */
class Ufo_s: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    //constructor
    Ufo_s(QGraphicsItem *parent=0);

    //void speed_up();

    //destructor
    ~Ufo_s(){};
public slots:
    //ufo drops with normal speed.
    void drop();

    //ufo drops with faster speed.
    void drop_speed2();


    //generate aliens
    void generate_alien();


    //void recover();


 private:
    QTimer* timer;
    QMediaPlayer* sound;

};
#endif // UFO_SPEED_H
