#ifndef FLOWER_H
#define FLOWER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
class Flower: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Flower(QGraphicsItem * parent=0);
public slots:
    void draw();
private:
    int picture;
};




#endif // FLOWER_H
