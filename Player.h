#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include<QMediaPlayer>
#include "score.h"
class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    Score * score;
public slots:
    void spawn();
    void draw();
private:
    QMediaPlayer * bulletsound;
    QMediaPlayer * bulletsound1;
    int picture;
    int nhanvat;
    int flagBoss;
};

#endif // PLAYER_H
