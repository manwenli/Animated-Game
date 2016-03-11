/** @file "fire.cpp"
 *  @author Manwen Li
 *  @brief Contains implementation of Fire class
 *
 * This file is to create Fire object to be displayed on game scene when player press space key.
 */
#include "fire.h"
#include"ufo.h"
#include"godzilla.h"
#include"game.h"
#include<QGraphicsScene>
#include<QList>
#include <QTimer>
#include <Typeinfo>
#include <QGraphicsPixmapItem>
#include "energy.h"

extern Game * lets_game;
/**constructor for fire. Godzilla shoots fire when pressing space key.
 * sets picture of fire.
*/
Fire::Fire():QObject(), QGraphicsPixmapItem()
{

    //set position
    setPixmap(QPixmap(":/image/fire.png"));

    //connect with timer
    timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(shoot()));
    timer->start(50);

}

/**public slot. shoot fire towards ufo's
 */
void Fire::shoot()
{
    setPos(x(),y()-20);


    if (pos().y()<0){
        scene()->removeItem(this);
        delete this;
    }



}




