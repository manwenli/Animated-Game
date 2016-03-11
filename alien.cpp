/** @file "alien.cpp"
 *  @author Manwen Li
 *  @brief Contains implementation of Alien class
 *
 * This file is to create vicious green aliens when ufo's fall on ground.
 */

#include "alien.h"
#include<QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include<QTimer>
#include<QList>
#include <stdlib.h>
#include <QTime>
#include<typeinfo>
#include "godzilla.h"
#include "game.h"
#include <qglobal.h>

extern Game * lets_game;

/**constructor for alien
 *Alien::Alien creates an alien every time a ufo drops on the ground. Aliens move towards left or right
 * @param parent is QGraphicsPixmapItem
 */
Alien::Alien(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    //set sound
    sound=new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/sound/bit.m4a"));

    //set picture
    setPixmap(QPixmap(":/image/alien.png"));

    //generate direction
    int rand_direction=qrand()%2;

    //from left to right
    if(rand_direction==0){
        //set position
        setPos(0,570);
        //move horizontally.
        timer=new QTimer(this);
        connect(timer, SIGNAL(timeout()),this, SLOT(move_to_right()));
        timer->start(50);
    }

    //from right to left
    if(rand_direction==1){
        //set position
        setPos(750,570);
        //move horizontally.
        timer2=new QTimer(this);
        connect(timer2, SIGNAL(timeout()),this, SLOT(move_to_left()));
        timer2->start(50);
    }

}

/*public slot move_to_right moves alien to right
 * Everytime an alien collides with Godzilla, player loses 1 life.
 */
void Alien::move_to_right()
{
    //move right
    setPos(x()+20,y());
    if(pos().x()>800){
        scene()->removeItem(this);
        delete this;
    }

    //if collide with godzilla
    QList<QGraphicsItem*> colliding_items=collidingItems();
    for(size_t i=0, n=colliding_items.size();i<n;++i){
        if(typeid(*(colliding_items[i]))==typeid(Godzilla)){
            //play sound
            if(sound->state()==QMediaPlayer::PlayingState){
                sound->setPosition(0);
            }
            else if (sound->state()==QMediaPlayer::StoppedState){
                sound->play();
            }

            //decrease score
            lets_game->life->decrease();
            //remove alien

            scene()->removeItem(this);
            //delete
            delete this;

            return;
        }
    }


}

/*public slot move_to_left moves alien to left
 * Everytime an alien collides with Godzilla, player loses 1 life.

 */
void Alien::move_to_left()
{
    setPos(x()-20,y());
    if(pos().x()<0){
        scene()->removeItem(this);
        delete this;
    }

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

            //decrease score
            lets_game->life->decrease();
            //remove alien

            scene()->removeItem(this);
            //delete
            delete this;

            return;
        }
    }


}
