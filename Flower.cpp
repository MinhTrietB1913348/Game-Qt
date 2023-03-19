#include "Flower.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Score.h"
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

extern Game * game;

Flower::Flower(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    picture=1;

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(draw()));

    // start the timer
    timer->start(300);
}

void Flower::draw(){

                if(picture==1){
                   setPixmap(QPixmap(":/img/flower1.png"));
                    picture=2;
                }
                else if(picture==2){
                   setPixmap(QPixmap(":/img/flower2.png"));
                    picture=3;
                }
                else if(picture==3){
                   setPixmap(QPixmap(":/img/flower3.png"));
                   picture=4;
                }
                else if(picture==4){
                   setPixmap(QPixmap(":/img/flower4.png"));
                   picture=5;
                }
                else if(picture==5){
                    setPixmap(QPixmap(":/img/flower5.png"));
                    picture=1;
                }

}




