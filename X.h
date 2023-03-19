#ifndef X_H
#define X_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
class X: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    X(QGraphicsItem * parent=0);
public slots:

private:

};
#endif // X_H
