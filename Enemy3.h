#ifndef ENEMY3_H
#define ENEMY3_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
class Enemy3: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy3(QGraphicsItem * parent=0);
public slots:
    void move();
    void draw();
private:
    int picture;
};

#endif // ENEMY3_H
