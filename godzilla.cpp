/** @file "godzilla.cpp"
 *  @author Manwen Li
 *  @brief Contains implementation Godzilla class
 *
 * This file is to create Godzilla object to be displayed on game scene.
 */
#include "godzilla.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include<QTimer>
#include <QList>
#include "mainwindow.h"
#include "ufo.h"
#include "fire.h"
#include "ghost.h"
#include "game.h"
#include "level.h"
#include "energy.h"
#include <QFont>
#include "ufo2.h"
#include"laser.h"
#include "ufo_bonus.h"
#include "ufo_speed.h"
#include <typeinfo>
#include <QGraphicsItem>

extern Game * lets_game;
/**Constructor for Godzilla
 * @sets picture for godzilla.
 * @param parent is QGraphicsPixmapItem
 * set picture of godzilla
 */
Godzilla::Godzilla(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    //set sound
    sound=new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/sound/bullet.m4a"));

    //setpicture
    setPixmap(QPixmap(":/image/godzilla_cute.png"));



}

/**function that controls Godzilla's action( moving left, right, jumping and shooting fire)
 * @brief Godzilla::keyPressEvent
 * @param event responsible for godzilla moving left, right, jumping and shooting fire.
 * when pressing space, godzilla shoots fire.
 */
void Godzilla::keyPressEvent(QKeyEvent *event)
{
    //left key
    if(event->key()==Qt::Key_Left){
        setPixmap(QPixmap(":/image/godzilla_cute2.png"));
        if(pos().x()>0){
            setPos(x()-30,y());
        }
    }
    //right key
    else if (event->key()==Qt::Key_Right){
        setPixmap(QPixmap(":/image/godzilla_cute.png"));
        if (pos().x()+100<690){
            setPos(x()+30,y());
        }
    }
    //space, shoot
    else if(event->key()==Qt::Key_Space){
        if(lets_game->energy->energy>25){
            //play sound
            if(sound->state()==QMediaPlayer::PlayingState){
                sound->setPosition(0);
            }
            else if (sound->state()==QMediaPlayer::StoppedState){
                sound->play();
            }
        Fire *fire=new Fire();
        fire->setPos(x()+40,y());

        scene()->addItem(fire);
        lets_game->energy->decrease();
        }

    }
    //up key, jump
    else if(event->key()==Qt::Key_Up){
        //how to only allow it to hold for three seconds????
        if(pos().y()>450){
        setPos(x(),y()-50);
        QTimer::singleShot(100,this,SLOT(up()));
        QTimer::singleShot(200,this,SLOT(up()));
        QTimer::singleShot(300,this,SLOT(up()));

        if(pos().y()<650){



            QTimer::singleShot(600,this, SLOT(down()));
            QTimer::singleShot(400,this, SLOT(down()));
    }
    }
   }



}

/**Godzilla shakes when hit by laser.
 * @brief Godzilla::move
 */
void Godzilla::move()
{
    setPos(x()+5,y());
    QTimer::singleShot(100,this, SLOT(left()));
    QTimer::singleShot(50,this, SLOT(left()));

}

/*
void Godzilla::keyReleaseEvent(QKeyEvent *release)
{
    if(release->key()==Qt::Key_Up){
        if(pos().y()<650){



            QTimer::singleShot(400,this, SLOT(down()));
            QTimer::singleShot(300,this, SLOT(down()));
    }

    }
}

*/



/**adds ufo's to the scene in basic mode.
 */
void Godzilla::generate_ufo()
{
    //create ufo
    Ufo* ufo=new Ufo();
    scene()->addItem(ufo);
}

/**adds ufos to the scene in fancy mode
 */
void Godzilla::generate_ufo2()
{
    Ufo2* ufo2=new Ufo2();
    scene()->addItem(ufo2);
}

/**adds ghosts to the scene
 */
void Godzilla::generate_ghost()
{
    Ghost* ghost=new Ghost();
    scene()->addItem(ghost);
}

/**adds mysterious bonus ufo to the scene in fancy mode.
 */
 void Godzilla::generate_ufo_b()
{
    Ufo_b* ufo_b=new Ufo_b();
    scene()->addItem(ufo_b);

}

 /**adds mysterious ufo that makes everything drop faster to the scene in fancy mode.
  */
void Godzilla::generate_ufo_s()
{
    Ufo_s* ufo_s=new Ufo_s();
    scene()->addItem(ufo_s);
}


/**godzilla moving down
 * @brief Godzilla::down by 100
 */
void Godzilla::down(){
    setPos(x(),y()+100);
}

/**godzilla moving up
 * @brief Godzilla::up by 50
 */
void Godzilla::up()
{
    setPos(x(),y()-50);
}

/**godzilla moving right
 * @brief Godzilla::right by 5
 */
void Godzilla::right()
{
    setPos(x()+5,y());
}

/**godzilla moving left
 * @brief Godzilla::up by 5
 */
void Godzilla::left(){
    setPos(x()-5,y());
}
