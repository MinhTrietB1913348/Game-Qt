#ifndef Z_H
#define Z_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
class Z: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Z(QGraphicsItem * parent=0);
public slots:

private:

};
#endif // Z_H
