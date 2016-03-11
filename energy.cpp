/** @file "energy.cpp"
 *  @author Manwen Li
 *  @brief Contains implementation of Energy class
 *
 * This file is to create Energy object to be displayed on game scene..
 */
#include "energy.h"
#include <QFont>
#include "game.h"

extern Game* lets_game;
/**constructor for energy
 * @param parent is QGraphicsItem
 * sets initial value and text for energy.
 */
Energy::Energy(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    energy=100;


    setPlainText((QString("Energy ")+QString::number(energy)));
    setFont(QFont("Fixedsys", 16));

    setDefaultTextColor(Qt::green);


}

/**Function increases energy by 50 when godzilla collides with ghost
 * @then update text.
 */
void Energy::increase(){
    energy+=50;
    setPlainText(QString("Energy ")+QString::number(energy));
    if(energy>50){
    setDefaultTextColor(Qt::green);
    }
    else if(energy<=50){
        setDefaultTextColor(Qt::red);
    }
}


/**Function decreases energy by 25 when godzilla shoots a fire
 * @then update text.
 */void Energy::decrease(){
    if(energy>25||energy==25){
    energy-=25;
    }
    else energy=0;
    setPlainText(QString("Energy ")+QString::number(energy));
    if(energy>50){
    setDefaultTextColor(Qt::green);
    }
    else if(energy<=50){
        setDefaultTextColor(Qt::red);
    }


}

/**Function increases energy by 50 when godzilla hit by laser
 * @then update text.
 */
void Energy::decrease35()
{
    if(energy>35||energy==35){
    energy-=35;}
    else energy=0;
    setPlainText(QString("Energy ")+QString::number(energy));


    if(energy>50){
    setDefaultTextColor(Qt::green);
    }
    else if(energy<=50){
        setDefaultTextColor(Qt::red);
    }


}


#include <QGraphicsTextItem>
