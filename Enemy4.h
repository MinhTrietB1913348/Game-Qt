#ifndef ENEMY4_H
#define ENEMY4_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
class Enemy4: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy4(QGraphicsItem * parent=0);
public slots:
    void move();
    void draw();
private:
    int picture;
};
#endif // ENEMY4_H
