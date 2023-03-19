#include "Avata.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Score.h"
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

extern Game * game;

Avata::Avata(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/img/avata.jpg").scaled(55,130));

}





