/** @file "ufo2.h"
 *  @author Manwen Li
 *  @brief Contains Ufo2 class
 *
 * This file is to create Ufo object to be displayed on game scene in fancy mode.
 */
#ifndef UFO2_H
#define UFO2_H
#include <QObject>
#include <QGraphicsItem>
#include "level.h"
#include <QMediaPlayer>

/**class Ufo2
 * @brief creates falling ufo's that can generate laser beam in fancy mode
 * creating ufo's falling
  */
class Ufo2: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    //constructor
    Ufo2(QGraphicsItem *parent=0);

    //void speed_up();

    //destructor
    ~Ufo2(){};
public slots:
    //ufo drops with normal speed.
    void drop();

    //ufo drops with faster speed.
    void drop_speed2();


    //generate aliens
    void generate_alien();

    //generate laser beam
    void generate_laser();

    //void recover();


 private:
    QTimer* timer;
    QMediaPlayer* sound;
};

#endif // UFO2_H
