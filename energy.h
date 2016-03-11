/** @file "energy.h"
 *  @author Manwen Li
 *  @brief Contains Energy class
 *
 * This file is to create Energy object to be displayed on game scene..
 */
#ifndef ENERGY_H
#define ENERGY_H

#include<QGraphicsTextItem>
#include "godzilla.h"
#include "score.h"
#include "ufo.h"
#include "ghost.h"
#include "fire.h"
/**class Energy
 * @brief displays and updates energy of godzilla
 */
class Energy: public QGraphicsTextItem{
public:
    //constructor
    explicit Energy(QGraphicsItem *parent=0);
    ~Energy(){};
    //increase energy
    void increase();
    //decrease energt
    void decrease();
    //decrease energy by 35
    void decrease35();

    //public member variable energy
    int energy;

    friend class Ghost;
    friend class Godzilla;
    friend class Laser;

};
#endif // ENERGY_H
