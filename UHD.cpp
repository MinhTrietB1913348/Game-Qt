
#include "UHD.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Score.h"
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

extern Game * game;


UHD::UHD(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){


    QTimer * timer = new QTimer(this);
    setPixmap(QPixmap(":/img/HUDgame.png").scaled(300,175));

    timer->start(300);
}
