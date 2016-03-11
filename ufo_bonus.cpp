/** @file "ufo_bonus.cpp"
 *  @author Manwen Li
 *  @brief Contains implementation of Ufo_b class
 *
 * This file is to create bonus ufo object to be displayed on game scene in fancy mode.
 */
#include "ufo_bonus.h"
#include<QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include<QTimer>
#include<QList>
#include <stdlib.h>
#include <QTime>
#include<typeinfo>
#include "fire.h"
#include "alien.h"
#include <qglobal.h>
#include "game.h"
#include "level.h"
#include <stdlib.h>
#include <iostream>

extern Game * lets_game;

/*constructor for bonus ufo. This kind of ufo looks mysterious but gives player 10 points if the ufo is hit.
 * set sound and picture for bonus ufo.
*/
Ufo_b::Ufo_b(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

    //sound
    bonussound=new QMediaPlayer();
    bonussound->setMedia(QUrl("qrc:/sound/bonusufo.m4a"));
    bonussound->setVolume(0.25f);


    //generates random position
    int rand_pos=qrand()%600;
    setPos(rand_pos,0);

    int surprise=qrand()%4;


    //set picture of ufo
    setPixmap(QPixmap(":/image/UFO_mysterious.png"));


    //makes ufo drops by connecting to timer.
    timer=new QTimer(this);
    QTimer* timer2=new QTimer;

    //normal

    if(lets_game->speedy_mode==false){

    connect(timer, SIGNAL(timeout()),this, SLOT(drop()));
    timer->start(50);
    }
//}

    //fast
    else if(lets_game->speedy_mode==true){
    connect(timer2, SIGNAL(timeout()),this, SLOT(drop_speed2()));
    timer2->start(30);
    }



}

/**ufo drops with normal speed, and increase player's score if ufo is hit.
 * ufo's dropping speed increases as level increases.
 */
void Ufo_b::drop()
{
    //level=1
    if(lets_game->level->level==1){
        //let ufo drop
        setPos(x(),y()+3);

    }

    else if(lets_game->level->level==2){
        int surprise=qrand()%3;
        if(surprise==0){
                setPos(x(),y()+10);
    }
        else{
        setPos(x(),y()+4.5);
    }
    }

    else if (lets_game->level->level==3){
        int surprise=qrand()%2;
        if(surprise==0){
                setPos(x(),y()+15);
    }
        else{
        setPos(x(),y()+5);
    }
    }

    else if (lets_game->level->level==4){
        int surprise=qrand()%2;
        if(surprise==0){
                setPos(x(),y()+18);
    }
        else{
        setPos(x(),y()+5.5);
    }
    }

    else if (lets_game->level->level==5){
        int surprise=qrand()%3;
        if(surprise==0){
                setPos(x(),y()+20);
    }
        else{
        setPos(x(),y()+7);
    }
    }

    else{
        int surprise =qrand()%3;
        if(surprise==0){
            setPos(x(),y()+25);
        }
        else {
            setPos(x(),y()+7);
        }
    }


    //if collides with fire
    QList<QGraphicsItem*> colliding_items=collidingItems();
    for(size_t i=0, n=colliding_items.size();i<n;i++){
        if(typeid(*(colliding_items[i]))==typeid(Fire)){
            //play sound
            if(bonussound->state()==QMediaPlayer::PlayingState){
                bonussound->setPosition(0);
            }
            else if (bonussound->state()==QMediaPlayer::StoppedState){
                bonussound->play();
            }

            //increse score
            lets_game->score->increase10();

            //lets_game->speedy_mode=true;



/*
            //increase level
            if (lets_game->score->score%5==0){
                lets_game->level->increase();
            }
*/
            //remove ufo and fire
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete
            delete this;
            delete colliding_items[i];
            return;
        }
    }

    for(size_t i=0, n=colliding_items.size();i<n;i++){
        if(typeid(*(colliding_items[i]))==typeid(Godzilla)){

             generate_alien();
            scene()->removeItem(this);
            //delete
            delete this;

            return;
        }
    }



    //destroy ufo when goes out of screen
    if(pos().y()>550){

        //create aliens

        generate_alien();


        scene()->removeItem(this);
        delete this;
    }


}

/**ufo drops with very fast speed, and increase player's score if ufo is hit.
 * ufo's dropping speed increases as level increases.
 */
void Ufo_b::drop_speed2()
{
    //let ufo drop
    setPos(x(),y()+8);


    //if collides with fire
    QList<QGraphicsItem*> colliding_items=collidingItems();
    for(size_t i=0, n=colliding_items.size();i<n;i++){
        if(typeid(*(colliding_items[i]))==typeid(Fire)){
            //play sound
            if(bonussound->state()==QMediaPlayer::PlayingState){
                bonussound->setPosition(0);
            }
            else if (bonussound->state()==QMediaPlayer::StoppedState){
                bonussound->play();
            }
            //increse score
            lets_game->score->increase10();
            //remove ufo and fire
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete
            delete this;
            delete colliding_items[i];
            return;
        }
    }

    for(size_t i=0, n=colliding_items.size();i<n;i++){
        if(typeid(*(colliding_items[i]))==typeid(Godzilla)){

             generate_alien();
            scene()->removeItem(this);
            //delete
            delete this;

            return;
        }
    }

    //destroy ufo when goes out of screen
    if(pos().y()>550){

        //create aliens

        generate_alien();
        //show();

        scene()->removeItem(this);
        delete this;
    }
}

/**function generates alien every time ufo touches ground or godzilla.
 * @brief Ufo::generate_alien creates alien objects.
 */
void Ufo_b::generate_alien()
{
    Alien* alien=new Alien();
    scene()->addItem(alien);


}

