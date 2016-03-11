/** @file "button.h"
 *  @author Manwen Li
 *  @brief Contains implementation Button class
 *
 * This file is to create Button object to quit game.
 */
#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

/**class Button
 * @brief The Button class creates quit button at the end of the game.
 */
class Button:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    // constructors
    Button(QString name, QGraphicsItem* parent=NULL);

    // public methods (events)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:
    //when player clicks the button, quit game.
    void clicked();

private:
    QGraphicsTextItem* text;
};

#endif // BUTTON_H
