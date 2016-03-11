/** @file "score.cpp"
 *  @author Manwen Li
 *  @brief Contains implementation Score class
 *
 * This file is to create Level object to display current score on the scene.
 */
#include "score.h"
#include <QFont>
#include "game.h"
#include <QGraphicsTextItem>
#include "level.h"

extern Game * lets_game;
/**Constructor for class Score.
 * @brief Level::Level displays current score.
 * @param parent is QGraphicsItem pointer
 */
Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    score=0;

    setPlainText((QString("Score:")+QString::number(score)));
    setFont(QFont("Fixedsys", 16));
    setDefaultTextColor(Qt::green);
}

/**Function increases score by 1, and increase leveles accordingly.
 */
void Score::increase(){
    score++;
    setPlainText(QString("Score:")+QString::number(score));

      //increase level
    if(lets_game->is_fancy==true){
        if (lets_game->score->score%20==0){
            lets_game->level->increase();
        }
    }
    else{

    if (lets_game->score->score%5==0){
        lets_game->level->increase();
    }
    }
}
/**Function increases score by 10.
 */
void Score::increase10()
{
    lets_game->score->increase();
    lets_game->score->increase();
    lets_game->score->increase();
    lets_game->score->increase();
    lets_game->score->increase();
    lets_game->score->increase();
    lets_game->score->increase();
    lets_game->score->increase();
    lets_game->score->increase();
    lets_game->score->increase();

    setPlainText(QString("Score:")+QString::number(score));

    /*
    //increase level
    lets_game->level->increase();
    lets_game->level->increase();
    */
}

