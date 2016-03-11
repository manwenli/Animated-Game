/** @file "laser.cpp"
 *  @author Manwen Li
 *  @brief Contains implementation of Laser class
 *
 * This file is to create Laser object shooting from UFO in fancy mode.
 */
#include<QGraphicsScene>
#include<QList>
#include <QTimer>
#include <Typeinfo>
#include <QGraphicsPixmapItem>
#include "laser.h"
#include "ufo2.h"
#include "game.h"
#include "godzilla.h"

extern Game * lets_game;
/**constructor for fire
 * sets picture for fire.
 * Laser inherated from QObject and QGraphicsPixmapItem classes.
*/
Laser::Laser():QObject(), QGraphicsPixmapItem()
{
    //set sound
    sound=new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/sound/laser.wav"));

    //set position
    setPixmap(QPixmap(":/image/laser.png"));

    //connect with timer
    timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(shoot()));
    timer->start(50);

}

/**Laser beams dropping from ufo in fancy mode. When collide with Godzilla, energy -35.
 */
void Laser::shoot()
{
    setPos(x(),y()+20);

    //if collide with godzilla
    QList<QGraphicsItem*> colliding_items=collidingItems();
    for(size_t i=0, n=colliding_items.size();i<n;i++){
        if(typeid(*(colliding_items[i]))==typeid(Godzilla)){
            //play sound
            if(sound->state()==QMediaPlayer::PlayingState){
                sound->setPosition(0);
            }
            else if (sound->state()==QMediaPlayer::StoppedState){
                sound->play();
            }

            lets_game->godzilla->move();

            //increse energy
            lets_game->energy->decrease35();
            //remove ghost
            scene()->removeItem(this);
            //delete
            delete this;

            return;
        }
    }

    if (pos().y()>440){
        scene()->removeItem(this);
        delete this;
    }



}
