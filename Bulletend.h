#ifndef BULLETEND_H
#define BULLETEND_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Bulletend: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bulletend(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // BULLETEND_H
