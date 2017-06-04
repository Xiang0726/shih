#ifndef MINION2_H
#define MINION2_H

#include<QGraphicsPixmapItem>
#include<QGraphicsPolygonItem>
#include<QGraphicsItem>
class Minion2 : public QObject,public QGraphicsPixmapItem{
    Q_OBJECT


public:
    Minion2(QGraphicsItem * parent=0);
    QGraphicsPolygonItem *attack_area;
    int team;
public slots:
    void move();
};
#endif // MINION2_H

