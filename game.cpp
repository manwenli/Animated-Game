/** @file "game.cpp"
 *  @author Manwen Li
 *  @brief Contains implementation of Game class
 *
 * This file is to create Game scene.
 */
#include"game.h"
#include"godzilla.h"
#include"fire.h"
#include "ghost.h"
#include<QGraphicsScene>
#include<QTimer>
#include<QPixmap>
#include<QKeyEvent>
#include "alien.h"
#include "level.h"
#include "energy.h"
#include "life.h"
#include <QGraphicsTextItem>
#include "ufo2.h"
#include "laser.h"
#include "ufo_bonus.h"
#include "ufo_speed.h"
#include <QMediaPlayer>
#include <QSoundEffect>
#include "button.h"

/**constructor for game
 * @brief Game::Game creates the game, either in basic mode or in fancy mode.
 * @param parent is QWidget
 * @param basic mode if player clicks basic mode
 * @param fancy mode if player clicks fancy mode
 */
Game::Game(QWidget *parent, bool basic, bool fancy)
{
    //create a scene
    scene=new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,650);
    setBackgroundBrush(QBrush(QImage(":/image/halloween.jpg")));
    setScene(scene);

    //fix window
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,650);


    //create godzilla
    godzilla=new Godzilla();
    godzilla->setPos(350,500);
    //set godzilla focusable
    godzilla->setFlag(QGraphicsItem::ItemIsFocusable);
    godzilla->setFocus();
    //add godzilla to the scene
    scene->addItem(godzilla);

    //set Life
    life=new Life();
    life->setPos(310,15);
    scene->addItem(life);

    //set Score
    score=new Score();
    score->setPos(600,15);
    scene->addItem(score);

    //set level
    level=new Level();
    level->setPos(510,15);
    scene->addItem(level);

    //set energy
    energy=new Energy();
    energy->setPos(410, 15);
    scene->addItem(energy);

    speedy_mode=false;

    /*
    QMediaPlayer* BGM=new QMediaPlayer();
    BGM->setMedia(QUrl("qrc:/sound/background.wav"));
    BGM->play();
*/

    QSoundEffect* BGM=new QSoundEffect();
    BGM->setSource(QUrl("qrc:/sound/background.wav"));
    BGM->setLoopCount(QSoundEffect::Infinite);
    BGM->setVolume(0.25f);
    BGM->play();

    if(basic){
    is_fancy=false;

    //generates ufo's
    timer_ufo=new QTimer();
    timer_ghost=new QTimer();


    //generate ufo
    QObject::connect(timer_ufo, SIGNAL(timeout()), godzilla,SLOT(generate_ufo()));
    timer_ufo->start(3000);


    //generate ghost

    QObject::connect(timer_ghost, SIGNAL(timeout()), godzilla, SLOT(generate_ghost()));
    timer_ghost->start(7000);
}
    else if(fancy){
        is_fancy=true;

        timer_ufo=new QTimer();
        timer_ghost=new QTimer();
        timer_ufo_b=new QTimer();
        timer_ufo_s=new QTimer();

        //generate ufo
        QObject::connect(timer_ufo, SIGNAL(timeout()), godzilla,SLOT(generate_ufo2()));
        timer_ufo->start(4000);

        //generate ghost

        QObject::connect(timer_ghost, SIGNAL(timeout()), godzilla, SLOT(generate_ghost()));
        timer_ghost->start(6000);


        //generate bonus ufo
        QObject::connect(timer_ufo_b, SIGNAL(timeout()), godzilla, SLOT(generate_ufo_b()));
        timer_ufo_b->start(14000);


        //generate speed up ufo
        QObject::connect(timer_ufo_s, SIGNAL(timeout()), godzilla, SLOT(generate_ufo_s()));
        timer_ufo_s->start(13000);





    }

    show();

}

/**function creates game over mode
 * When life=0, game over, display final score.
 */
void Game::game_over()
{
    scene=new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,650);
    setBackgroundBrush(QBrush(QImage(":/image/spooky.jpg")));
    setScene(scene);

    QGraphicsTextItem* over=new QGraphicsTextItem;
    over->setPlainText((QString("GAME OVER!")));
    over->setFont(QFont("Fixedsys", 36));
    over->setDefaultTextColor(Qt::black);
    over->setPos(180,150);

    int final_score=score->score;
    QString sayscore="You got "+QString::number(final_score)+" points!\nNot bad!";
    QGraphicsTextItem* display=new QGraphicsTextItem();
    display->setPlainText(sayscore);
    display->setFont(QFont("Fixedsys", 36));
    display->setDefaultTextColor(Qt::black);
    display->setPos(130,250);

    Button* quit=new Button(QString("Bye!"));
    quit->setPos(330, 450);

    scene->addItem(quit);
    connect(quit, SIGNAL(clicked()),this->parent(),SLOT(close()));
    scene->addItem(over);
    scene->addItem(display);
}
