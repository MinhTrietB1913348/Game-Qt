#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"
#include "Player.h"
#include <typeinfo>
#include <QDebug>

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random x position
    int random_number = rand() % 1100;
    setPos(random_number+150,0);

    // drew the rect
     setPixmap(QPixmap(":/img/enemy1.png"));

    // make/connect a timer to move() the enemy every so often
    timer = new QTimer(this);
    timer->start(200);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer

}

void Enemy::move(){
    // move enemy down
    //QTimer * timer = new QTimer(this);
   // timer->start(200);
    int randomx=rand() % 10;
    int randomy=rand() %10;
    int randomz=rand()% 2;

    if(randomz==0){
        setPos(x()+randomx,y()+randomy);
    }
    else {
        setPos(x()-randomx,y()+randomy);
    }

    QList<QGraphicsItem *> colliding_items = collidingItems();
    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            // increase the score
            game->health->decrease();


            // remove them from the scene (still on the heap)
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }
    }

    if(game->health->getHealth()<=0){
        timer->stop();
        scene()->removeItem(this);
        delete this;
        QGraphicsTextItem *a = new QGraphicsTextItem();
        a->setPos(200, 400);
        a->setPlainText(QString("GAME OVER"));
    }

    else if(game->score->getScore()>10){
        scene()->removeItem(this);
        delete this;
    }
     //destroy enemy when it goes out of the screen
    else if (pos().y() > 1290){
        //decrease the health
        //game->health->decrease();


        scene()->removeItem(this);
        delete this;
    }

}
