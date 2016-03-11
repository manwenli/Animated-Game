/** @file "level.cpp"
 *  @author Manwen Li
 *  @brief Contains implementation of Level class
 *
 * This file is to create Level object to display current level on the scene.
 */
#include "level.h"
#include <QFont>
#include "game.h"
#include <QGraphicsTextItem>

extern Game* lets_game;
/**Constructor for class Level.
 * @brief Level::Level displays current level of player
 * @param parent is QGraphicsItem pointer
 */
Level::Level(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    level=1;

    setPlainText((QString("Level:")+QString::number(level)));
    setFont(QFont("Fixedsys", 16));
    setDefaultTextColor(Qt::green);

}

/**Function increases level by 1.
 */
void Level::increase(){
    level++;
    setPlainText(QString("Level:")+QString::number(level));

}



