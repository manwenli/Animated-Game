/** @file "button.cpp"
 *  @author Manwen Li
 *  @brief Contains implementation Button class
 *
 * This file is to create Button object to quit game.
 */
#include "Button.h"
#include <QGraphicsTextItem>
#include <QBrush>

/**class Button
 * @brief Button::Button inheritates from QGraohicsItem
 * @param name is QString, which sets the text on the button
 * @param parent is QGraphicsItem pointer
 */
Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw the rect
    setRect(0,0,100,25);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::yellow);
    setBrush(brush);

    // draw the text
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    // allow responding to hover events
    setAcceptHoverEvents(true);
}

/**function responds to mouse click
 * @ mousePressEvent quits the program by clicking the button.
 */
void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}



