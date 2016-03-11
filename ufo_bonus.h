#ifndef UFO_BONUS_H
#define UFO_BONUS_H
/** @file "ufo_bonus.h"
 *  @author Manwen Li
 *  @brief Contains Ufo_b class
 *
 * This file is to create bonus ufo object to be displayed on game scene in fancy mode.
 */
#include <QObject>
#include <QGraphicsItem>
#include "level.h"
#include <QMediaPlayer>

/**class Ufo_bonus
 * @brief one of the mysterious ufo's in fancy mode. This is the good ufo.
 * score increases by 10 if this type of ufo is shot.
  */
class Ufo_b: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    //constructor
    Ufo_b(QGraphicsItem *parent=0);

    //void recover();

    //destructor
    ~Ufo_b(){};
public slots:
    //ufo drops with normal speed.
    void drop();

    //ufo drops with faster speed.
    void drop_speed2();

    //generate aliens
    void generate_alien();





 private:
    QTimer* timer;
    QMediaPlayer* bonussound;

};

#endif // UFO_BONUS_H
