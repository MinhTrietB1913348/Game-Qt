#ifndef BULLETPRO_H
#define BULLETPRO_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Bulletpro: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bulletpro(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // BULLETPROEND_H
