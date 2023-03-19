
#include "Bulletend.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy1.h"
#include "Enemy.h"
#include "Enemy3.h"
#include "Enemy4.h"
#include "Enemy1.h"
#include "Enemy5.h"
#include "Boss.h"
#include "Game.h"
#include<typeinfo>

extern Game * game; // there is an external global object called game

Bulletend::Bulletend(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // drew the bullet (a rectangle)
    setPixmap(QPixmap(":/img/bullet3.png"));
    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Bulletend::move(){
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Boss)){
            // increase the score
            game->healthboss->decreaseboss();

            // remove them from the scene (still on the heap)
            if(game->healthboss->getHealthboss()<=0){
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
            }

           // scene()->removeItem(colliding_items[i+1]);
            scene()->removeItem(this);

            // delete them from the heap to save memory

            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(Enemy3)){
            // increase the score
            //game->score->increase();

            // remove them from the scene (still on the heap)
            //scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete them from the heap to save memory
            //delete colliding_items[i];
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(Enemy5)){
            // increase the score
            //game->score->increase();

            // remove them from the scene (still on the heap)
            //scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete them from the heap to save memory
            //delete colliding_items[i];
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }
    }

    // if there was no collision with an Enemy, move the bullet forward
    setPos(x(),y()-10);
    // if the bullet is off the screen, destroy it
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}