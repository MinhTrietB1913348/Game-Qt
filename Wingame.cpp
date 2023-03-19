#include "Wingame.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Score.h"
#include <stdlib.h> // rand() -> really large int
#include "Game.h"
#include "Healthboss.h"
#include "Health.h"

extern Game * game;

Wingame::Wingame(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random x position


    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(draw()));

    // start the timer
    timer->start(300);
}

void Wingame::draw(){

    if(game->healthboss->getHealthboss()<=0){
       setPixmap(QPixmap(":/img/Clear_Scene.png"));
     }
    else if(game->health->getHealth()<=0){
        setPixmap(QPixmap(":/img/Failed_Scene.png"));
    }

}



