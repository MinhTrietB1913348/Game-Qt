#ifndef C_H
#define C_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
class C: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    C(QGraphicsItem * parent=0);
public slots:

private:

};
#endif // C_H
