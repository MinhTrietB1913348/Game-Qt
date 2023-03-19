
#include "Enemy5.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Score.h"
#include <typeinfo>
#include "Player.h"
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

extern Game * game;

Enemy5::Enemy5(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random x position
    int random_number = rand() % 1100;
    setPos(random_number+100,0);

    //picture=1;

    // drew the rect
    setPixmap(QPixmap(":/img/bullet1.png"));

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    //connect(timer,SIGNAL(timeout()),this,SLOT(draw()));
    // start the timer
    timer->start(20);
}

//void Enemy3::draw(){

//                if(picture==1){
//                   setPixmap(QPixmap(":/img/ghost1.png"));
//                    picture=2;
//                }
//                else if(picture==2){
//                   setPixmap(QPixmap(":/img/ghost2.png"));
//                    picture=3;
//                }
//                else if(picture==3){
//                   setPixmap(QPixmap(":/img/ghost3.png"));
//                   picture=4;
//                }
//                else if(picture==4){
//                   setPixmap(QPixmap(":/img/ghost4.png"));
//                   picture=1;
//                }


//}

void Enemy5::move(){
    // move enemy down
    QTimer * timer = new QTimer(this);
    int randomx=rand() % 20;
    int randomy=rand() %20;
    int randomz=rand()% 2;

    if(randomz==0){
        setPos(x()+randomx,y()+randomy);
    }
    else {
        setPos(x()-randomx,y()+randomy);
    }
    if(game->healthboss->getHealthboss()<=0){
        timer->stop();
    }
    // destroy enemy when it goes out of the screen
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
}



