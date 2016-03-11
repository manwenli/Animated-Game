/** @file "game.h"
 *  @author Manwen Li
 *  @brief Contains Game class
 *
 * This file is to create Game scene.
 */
#ifndef GAME_H
#define GAME_H

#include<iostream>
#include<QGraphicsView>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QGraphicsTextItem>
#include<QPixmap>
#include<QWidget>
#include <QTimer>

#include "godzilla.h"
#include "ufo.h"
#include "fire.h"
#include "score.h"
#include "level.h"
#include "energy.h"
#include "life.h"
#include "ufo2.h"
#include "ufo_bonus.h"
#include "ufo_speed.h"

/** class game
 *  @brief creates game scene of the shooting game.
*/
class Game:public QGraphicsView{
public:

    //constructor
    Game(QWidget* parent=0, bool basic=false, bool fancy=false);

    //game over
    void game_over();

    //destructor
    ~Game(){};

    //create pointers
    QGraphicsScene *scene;
    Godzilla * godzilla;

    //QTimer variables
    QTimer*timer_ufo;
    QTimer* timer_ghost;
    QTimer* timer_ufo_b;
    QTimer* timer_ufo_s;

    //other member variables
    Score* score;
    Level* level;
    Energy *energy;
    Life* life;

    //bool type member variables
    bool is_fancy;
    bool speedy_mode;

};



#endif // GAME_H
