
#include "Z.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Score.h"
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

extern Game * game;

Z::Z(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
        setPixmap(QPixmap(":/img/bullet3.png").scaled(30,40));
}






