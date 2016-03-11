/** @file "level.h"
 *  @author Manwen Li
 *  @brief Contains Level class
 *
 * This file is to create Level object to display current level on the scene.
 */
#ifndef LEVEL_H
#define LEVEL_H
#include<QGraphicsTextItem>
#include "godzilla.h"
#include "score.h"
#include "ufo.h"
#include "ufo_bonus.h"
/**class Level
 * @brief displays and updates level of player.
 */
class Level: public QGraphicsTextItem{
public:
    //constructor
    explicit Level(QGraphicsItem *parent=0);
    //destructor
    ~Level(){};
    //increase level by 1.
    void increase();



    int level;
    friend class Ufo;
    friend class Ufo2;
    friend class Ufo_b;


};

#endif // LEVEL_H
