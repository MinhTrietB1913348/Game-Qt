
#include "X.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Score.h"
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

extern Game * game;

X::X(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
        setPixmap(QPixmap(":/img/bullet.png").scaled(80,60));
}






