#ifndef HEALTHBOSS_H
#define HEALTHBOSS_H


#include <QGraphicsTextItem>

class Healthboss: public QGraphicsTextItem{
public:
    Healthboss(QGraphicsItem * parent=0);
    void decreaseboss();
    int getHealthboss();
public slots:
    void draw();
private:
    int healthboss;
};

#endif // HEALTHBOSS_H
