#include "Bulletpro.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Boss.h"
#include "Enemy.h"
#include "Game.h"
#include<typeinfo>

extern Game * game; // there is an external global object called game

Bulletpro::Bulletpro(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // drew the bullet (a rectangle)
    setPixmap(QPixmap(":/img/bullet2.png"));
    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Bulletpro::move(){
    QTimer * timer = new QTimer(this);
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
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // increase the score
            game->score->increase();


            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete colliding_items[i];
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
    if(game->healthboss->getHealthboss()<=0){
        timer->stop();
    }
}
