/** @file "life.h"
 *  @author Manwen Li
 *  @brief Contains Life class
 *
 * This file is to create Life object to display number of lives left.
 */
#ifndef LIFE_H
#define LIFE_H
#include<QGraphicsTextItem>
#include "godzilla.h"
#include "alien.h"

/**class Life
 * @brief displays and updates number of lives left for player.
 */
class Life: public QGraphicsTextItem{
public:
    //constructor
    explicit Life(QGraphicsItem *parent=0);
    //destructor
    ~Life(){};
    //decrease number of lives by 1.
    void decrease();
    //number of lives.
    int life;

    friend class alien;
    friend class godzilla;
};

#endif // LIFE_H
