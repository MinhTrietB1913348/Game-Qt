#ifndef BOSS_H
#define BOSS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include<QMediaPlayer>
class Boss:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Boss(QGraphicsItem * parent=0);

public slots:
    void move();
    void draw();
private:
    QMediaPlayer * bulletsound;
    QMediaPlayer * bulletsound1;
    int picture;
};

#endif // BOSS_H
