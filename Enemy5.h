#ifndef ENEMY5_H
#define ENEMY5_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
class Enemy5: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy5(QGraphicsItem * parent=0);
public slots:
    void move();
    //void draw();
private:
    //int picture;
};
#endif // ENEMY5_H
