//#include "MyRect.h"
//#include <QGraphicsScene>
//#include <QKeyEvent>
//#include "Bullet.h"
//#include "Bulletpro.h"
//#include "Enemy.h"
//#include <QDebug>
//void MyRect::keyPressEvent(QKeyEvent *event){
//    if (event->key() == Qt::Key_Left){
//        if(pos().x()>0)
//        setPos(x()-10,y());
//    }
//    else if (event->key() == Qt::Key_Right){
//        if(pos().x()+100<800)
//        setPos(x()+10,y());
//    }
////    else if (event->key() == Qt::Key_Up){
////        setPos(x(),y()-10);
////    }
////    else if (event->key() == Qt::Key_Down){
////        setPos(x(),y()+10);
////    }
//    else if (event->key() == Qt::Key_Space){
//        // create a bullet
//        Bullet * bullet = new Bullet();
//        bullet->setPos(x(),y());
//        scene()->addItem(bullet);
//    }
//    else if (event->key() == Qt::Key_W){
//        // create a bullet
//        Bulletpro * bulletpro = new Bulletpro();
//        bulletpro->setPos(x(),y());
//        scene()->addItem(bulletpro);
//    }
//}

//void MyRect::spawn()
//{
//    Enemy * enemy=new Enemy();
//    scene()->addItem(enemy);
//}
