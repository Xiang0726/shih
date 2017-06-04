#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include "Minion1.h"
#include <QKeyEvent>
#include "Minion2.h"
#include <Enemy1.h>
class Game: public QGraphicsView{
public:
    // member functions
    Game();
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *eventnumber);
    int id;
    // member attributes
    QGraphicsScene * scene;
};

#endif // GAME_H
