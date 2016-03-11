/** @file "godzilla.h"
 *  @author Manwen Li
 *  @brief Contains Godzilla class
 *
 * This file is to create Godzilla object to be displayed on game scene.
 */
#ifndef GODZILLA_H
#define GODZILLA_H


#include<QObject>
#include<QKeyEvent>
#include<QGraphicsItem>
#include<QGraphicsPixmapItem>
#include<QMediaPlayer>


/**Godzilla class
  @brief displays player godzilla
  inherits from QGraphicPixmapItem.
  */
class Godzilla: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    //constructor
    Godzilla(QGraphicsItem* parent=0);

    //signal that moves godzilla's position and commands it shoots fire.
    void keyPressEvent(QKeyEvent *event);

    void move();

    //destructor
    ~Godzilla(){};
public slots:
    //create ufo for basic mode
    void generate_ufo();
    //create ufo for fancy mode
    void generate_ufo2();

    //create ghost
    void generate_ghost();

    //create bonus ufo
    void generate_ufo_b();

    //create evil ufo
    void generate_ufo_s();

    //gozilla moving down
    void down();
    //godzilla moving up
    void up();

    //godzilla move right
    void right();
    //godzilla move left.
    void left();


private:
    QMediaPlayer* sound;

};



#endif // GODZILLA_H
