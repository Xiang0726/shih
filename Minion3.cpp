#include"Minion3.h"
#include<QPixmap>
#include<QObject>
#include<QTimer>
#include<QGraphicsScene>
#include<QVector>
#include<QPointF>
#include<QPolygonF>
#include<QLineF>
#include "Game.h"
#include <Bullet1.h>
#include <QList>
#include <Tower.h>
#include "Bullet10.h"
#include"Bullet3.h"
extern Game * game;

Minion3::Minion3(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //define HP
     hp = 50;

    //define team
     team = 1;

   //draw pic
    setPixmap(QPixmap(":images/minion3.jpg"));

   //set  timer

    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(200);







   //create a polygon

   QVector<QPointF> points;
   points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3)
         << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);
   //scale polygon
   int i,n;
   int scale = 80;
   for(i=0,n=points.size();i<n;i++){
       points[i]=points[i]*scale;
   }

   //create polygonitem
   attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);

   //match polygon and minion
   QPointF poly_center(1.5,1.5);
   poly_center = poly_center * scale;
   poly_center = mapToScene(poly_center);
   QPointF Minion_center(x()+28,y()+40);
   QLineF ln(poly_center,Minion_center);
   attack_area->setPos(x()+ln.dx(),y()+ln.dy());
}

Minion3::~Minion3()
{
   move_timer->stop();
   delete move_timer;
}

void Minion3::attack()
{
    QLineF lnn(this -> pos(),target);
    int angle = -1 * lnn.angle();
    Bullet3 *bullet3 = new Bullet3;
    bullet3 ->from = 1;
    bullet3 -> setPos(x(),y());
    bullet3 ->setRotation(angle);
    game -> scene -> addItem(bullet3);
   // has = false;
}








void Minion3::move(){
     int closedistance=200;
     setPos(x()+10,y());
     has = false;
     QList<QGraphicsItem *> colliding_items = attack_area -> collidingItems();
     for (int i = 0, n = colliding_items.size(); i < n; ++i){
         if(dynamic_cast<Tower*>(colliding_items[i])){
             QLineF ln(this->pos(),colliding_items[i]->pos());
             int distance = ln.length();

                 if(distance<=closedistance){
                     closedistance = distance;
                     target = colliding_items[i]->pos();
                     has = true;
                     setPos(x()-10,y());
         }}
         else if( dynamic_cast<Enemy1*>(colliding_items[i])){
         //setPos(x()-5,y());
         QLineF ln(this->pos(),colliding_items[i]->pos());
         int distance = ln.length();

             if(distance<=closedistance){
                 closedistance = distance;
                 target = colliding_items[i]->pos();
                 has = true;
               }
            }
         else if(dynamic_cast<Minion3*>(colliding_items[i])==this){ continue;}

         else if(dynamic_cast<Bullet10*>(colliding_items[i])){
                 //  if(bullet->from == 10){
                      this->hp--;
                    //  }
                 }
           }

     if(has == true){
        attack();
     }
     if(this->hp <= 0){
         scene() ->removeItem(this);
         delete this;
     }

     if (pos().x()>1300){
             scene()->removeItem(this);
             delete this;

         }
     }


