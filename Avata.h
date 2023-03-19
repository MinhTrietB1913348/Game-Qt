#ifndef AVATA_H
#define AVATA_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
class Avata: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Avata(QGraphicsItem * parent=0);
public slots:

private:

};
#endif // AVATA_H
