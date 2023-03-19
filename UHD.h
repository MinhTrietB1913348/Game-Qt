#ifndef UHD_H
#define UHD_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
class UHD: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    UHD(QGraphicsItem * parent=0);
};
#endif // UHD_H
