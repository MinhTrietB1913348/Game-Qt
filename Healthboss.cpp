#include "Healthboss.h"
#include <QFont>
#include "Score.h"
#include "Game.h"
#include "Wingame.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Score.h"
#include <stdlib.h> // rand() -> really large int
#include "Health.h"

extern Game * game;

Healthboss::Healthboss(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    healthboss = 20;

    setPlainText(QString("Healthboss: ") + QString::number(healthboss)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));

}

void Healthboss::draw(){
    if( game->score->getScore()>=20){
        setPlainText(QString("Healthboss: ") + QString::number(healthboss)); // Health: 3
        setDefaultTextColor(Qt::red);
        setFont(QFont("times",16));
    }
}

void Healthboss::decreaseboss(){
    healthboss--;
    setPlainText(QString("Healthboss: ") + QString::number(healthboss)); // Health: 2
}

int Healthboss::getHealthboss(){
    return healthboss;
}

