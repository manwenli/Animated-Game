/** @file "score.h"
 *  @author Manwen Li
 *  @brief Contains Score class
 *
 * This file is to create Level object to display current score on the scene.
 */
#ifndef SCORE_H
#define SCORE_H
#include<QGraphicsTextItem>
#include "godzilla.h"

/**class Score
 * @brief displays and updates score of player.
 * score increase by 1 if godzilla shoots a ufo.
 */
class Score: public QGraphicsTextItem{
public:
    //constructor
    explicit Score(QGraphicsItem *parent=0);
    //destructor
    ~Score(){};
    //increase score by 1
    void increase();
    //increase score by 10
    void increase10();
    int score;

    friend class Ufo;
};

#endif // SCORE_H
