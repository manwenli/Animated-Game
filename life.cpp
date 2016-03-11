/** @file "life.cpp"
 *  @author Manwen Li
 *  @brief Contains implementation of Life class
 *
 * This file is to create Life object to display number of lives left.
 */
#include "life.h"
#include <QFont>
#include "game.h"
#include <QGraphicsTextItem>

extern Game * lets_game;

/**Constructor for class Life.
 * @brief Level::Level displays number of lives left.
 * @param parent is QGraphicsItem pointer
 */
Life::Life(QGraphicsItem *parent):QGraphicsTextItem(parent)
{

    //if(lets_game->is_fancy)
    life=8;
    //else life=4;

    setPlainText((QString("Lives:")+QString::number(life)));
    setFont(QFont("Fixedsys", 16));
    setDefaultTextColor(Qt::green);
}

/**Function decreases number of lives by 1.
 * If number of lives=0, game over.
 */
void Life::decrease(){

    life--;
    setPlainText(QString("lives:")+QString::number(life));

    if(life<1){
        lets_game->game_over();
    }

}
