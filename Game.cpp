#include"Game.h"
#include"Minion1.h"
#include"Minion2.h"
#include <QGraphicsScene>
#include <QLabel>
#include <Enemy1.h>
#include <Bullet1.h>
#include"Tower.h"
#include"enemyTower1.h"
#include"Minion3.h"
Game::Game(){


  //create scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);

    //CREATE tower
    Tower * t = new Tower();
    t->setPos(0,50);
    enemyTower1 * t1 = new enemyTower1();
    t1->setPos(700,100);
    // add tower to scene
    scene->addItem(t);
    scene->addItem(t1);
   }
  //chose minion type

void Game::keyPressEvent(QKeyEvent *eventnumber){
    if(eventnumber->key() == Qt::Key_1){
        id = 1;
    }
    else if(eventnumber ->key() == Qt::Key_2){
        id = 2;
    }
    else if(eventnumber ->key() == Qt::Key_3){
        id = 3;
    }
    else if(eventnumber ->key() == Qt::Key_4){
        id = 4;
    }
    else if(eventnumber ->key() == Qt::Key_5){
        id = 5;
    }
}



void Game::mousePressEvent(QMouseEvent *event){
    if(id == 1){
    //create minion1
    Minion1 * minion = new Minion1();
    minion->setPos(event->x()-250,event->y());
    scene->addItem(minion);
    }
    else if(id == 2){
     //create minion2
    Minion2 * minion = new Minion2();
    minion->setPos(event->x()-250,event->y());
    scene->addItem(minion);
    }
    if(id == 3){
    //create a minion3
    Minion3 * minion = new Minion3();
    minion->setPos(event->x()-250,event->y());
    scene->addItem(minion);
    }
    if(id == 5){
    //create a ENEMY1
    Enemy1 * minion = new Enemy1();
    minion->setPos(event->x()-250,event->y());
    scene->addItem(minion);
    }
}




