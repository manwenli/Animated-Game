/** @file "ufo_speed.cpp"
 *  @author Manwen Li
 *  @brief Contains implementation of Ufo_s class
 *
 * This file is to create dangerous ufo object to be displayed on game scene in fancy mode.
 */
#include "ufo_speed.h"
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
#include"laser.h"

extern Game * lets_game;

/*constructor for a type of mysterious ufo. But this is the evil ufo. If it is hit by fire, the dropping speed of every ufo's will be very fast.
 *Godzilla has to eat a ghost in order to go back to the normal speed.
*/
Ufo_s::Ufo_s(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

    //set sound
    sound=new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/sound/speed.wav"));

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
    //if(surprise!=0){
    connect(timer, SIGNAL(timeout()),this, SLOT(drop()));
    timer->start(50);


    //}
    }


    //fast
    //else{
    //connect(timer2, SIGNAL(timeout()),this, SLOT(drop_speed2()));
    //timer2->start(30);
    //}


    else if(lets_game->speedy_mode==true){

        connect(timer2, SIGNAL(timeout()),this, SLOT(drop_speed2()));
        timer2->start(50);
        //speed_up();
    }

}

/**ufo drops with normal speed, and increase player's score if ufo is hit.
 * ufo's dropping speed increases as level increases.
 */
void Ufo_s::drop()
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
            if(sound->state()==QMediaPlayer::PlayingState){
                sound->setPosition(0);
            }
            else if (sound->state()==QMediaPlayer::StoppedState){
                sound->play();
            }
            //increse score
            lets_game->score->increase();

            lets_game->speedy_mode=true;


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
void Ufo_s::drop_speed2()
{
    //let ufo drop
    setPos(x(),y()+8);


    //if collides with fire
    QList<QGraphicsItem*> colliding_items=collidingItems();
    for(size_t i=0, n=colliding_items.size();i<n;i++){
        if(typeid(*(colliding_items[i]))==typeid(Fire)){
            //play sound
            if(sound->state()==QMediaPlayer::PlayingState){
                sound->setPosition(0);
            }
            else if (sound->state()==QMediaPlayer::StoppedState){
                sound->play();
            }
            //increse score
            lets_game->score->increase();
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

/**function generates alien when ufo hits ground or godzilla.
 * @brief Ufo::generate_alien creates alien objects.
 */
void Ufo_s::generate_alien()
{
    Alien* alien=new Alien();
    scene()->addItem(alien);


}



