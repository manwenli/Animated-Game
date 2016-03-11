/** @file "ghost.cpp"
 *  @author Manwen Li
 *  @brief Contains implementation of Ghost class
 *
 * This file is to create Ghost object to be displayed on game scene.
 */
#include "ghost.h"
#include<QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include<QTimer>
#include<QList>
#include <stdlib.h>
#include <QTime>
#include<typeinfo>
#include "fire.h"
#include "godzilla.h"
#include "game.h"
#include <qglobal.h>


extern Game * lets_game;
/**constructor for ghost
 * @brief Ghost::Ghost creates ghosts dropping. Godzilla gets 50 energy if collides with ghosts.
 * @param parent is QGraphicsItem
 */
Ghost::Ghost(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    //set collision sound
    sound=new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/sound/ghost.m4a"));

    //set picture for ghost
    setPixmap(QPixmap(":/image/ghost.png"));

    //randomly generates position
    int rand_pos=qrand()%650;
    setPos(rand_pos,0);

    //connecting with timer
    timer=new QTimer();
    connect(timer, SIGNAL(timeout()),this, SLOT(drop()));
    timer->start(100);


}

/**function drop
 * @brief Ghost::drop makes ghosts moving downward
 */
void Ghost::drop()
{
    //let ghost drop
    setPos(x(),y()+13);

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

            if(lets_game->speedy_mode==true){
                lets_game->speedy_mode=false;
            }
            //increse energy
            lets_game->energy->increase();
            //remove ghost
            scene()->removeItem(this);
            //delete
            delete this;

            return;
        }
    }




    //destroy ufo when goes out of screen
    if(pos().y()>550){
        scene()->removeItem(this);
        delete this;
    }
}
