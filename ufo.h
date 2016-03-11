/** @file "ufo.h"
 *  @author Manwen Li
 *  @brief Contains Ufo class
 *
 * This file is to create Ufo object to be displayed on game scene in basic mode.
 */
#ifndef UFO_H
#define UFO_H


#include <QObject>
#include <QGraphicsItem>
#include "level.h"
#include <QMediaPlayer>

/**class Ufo
 * @brief falling ufo's to be shot by godzilla's fire, in basic mode
 * creating ufo's falling
  */
class Ufo: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    //constructor
    Ufo(QGraphicsItem *parent=0);

    //destructor
    ~Ufo(){};
public slots:
    //ufo drops with normal speed.
    void drop();

    //ufo drops with faster speed.
    void drop_speed2();

    //generate aliens
    void generate_alien();



 private:
    QTimer* timer;
    QMediaPlayer* sound;

};

#endif // UFO_H
