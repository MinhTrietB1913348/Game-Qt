#include "Boss.h"
#include <QGraphicsScene>
#include "Bullet.h"
#include "Bullet2.h"
#include "Bullet3.h"
#include "Bulletpro.h"
#include "Bulletend.h"
#include "Enemy.h"
#include "Enemy1.h"
#include "Score.h"
#include "Game.h"
#include <QDebug>
#include <QTimer>


extern Game * game;
Boss::Boss(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
//    setPixmap(QPixmap(":/img/enemy2.png"));
    picture=1;
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    connect(timer,SIGNAL(timeout()),this,SLOT(draw()));
    // start the timer
    timer->start(50);
}

void Boss::draw(){
    if(picture==1){
         setPixmap(QPixmap(":/img/Final_Boss1.png"));
         picture=2;
    }
    else if(picture==2){
        setPixmap(QPixmap(":/img/Final_Boss2.png"));
        picture=3;
    }
    else if(picture==3){
        setPixmap(QPixmap(":/img/Final_Boss3.png"));
        picture=4;
    }
    else if(picture==4){
        setPixmap(QPixmap(":/img/Final_Boss4.png"));
        picture=1;
    }
}


void Boss::move(){
    // move enemy down
    QTimer * timer = new QTimer(this);
    if(x() <= 1000 && y()<=0){
         setPos(x()+10,y());
    }
    else if( y()>=0 && (y()<=100) && x()>=500){
        setPos(x()-5, y()+5);
    }
    else if(x()<=1000 && x()>=200){
        setPos(x()-10, y());
    }
    else if(x()<=200){
        setPos(x()-5, y()-5);
    }

    if(game->healthboss->getHealthboss()<=0){
        timer->stop();
        scene()->removeItem(this);
        delete this;
    }
}



