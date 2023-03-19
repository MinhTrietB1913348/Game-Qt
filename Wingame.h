#ifndef WINGAME_H
#define WINGAME_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
class Wingame: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Wingame(QGraphicsItem * parent=0);
public slots:
    void draw();
private:
    int picture;
};

#endif // WINGAME_H
