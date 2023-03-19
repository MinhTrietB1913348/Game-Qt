#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include<QGraphicsItem>
#include <QFont>
#include "Enemy.h"
#include "Enemy1.h"
#include "Enemy3.h"
#include "Flower.h"
#include "Avata.h"
#include "C.h"
#include "X.h"
#include "Z.h"
#include<QMediaPlayer>
#include<QMediaPlayer>
#include<QImage>
#include <QtDebug>
#include <QTimer>
#include "Boss.h"
#include "Wingame.h"
#include "UHD.h"

Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1280,720); // make the scene 800x600 instead of infinity by infinity (default)


    setBackgroundBrush(QBrush(QImage(":/img/New map (1).jpg")));
    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,720);

    Flower * flower = new Flower();
    flower->setPos(150,300);
    scene->addItem(flower);

    Flower * flower2 = new Flower();
    flower2->setPos(190,450);
    scene->addItem(flower2);

    Flower * flower3 = new Flower();
    flower3->setPos(200,150);
    scene->addItem(flower3);


    Flower * flower1 = new Flower();
    flower1->setPos(1000,50);
    scene->addItem(flower1);

    Flower * flower4 = new Flower();
    flower4->setPos(950,150);
    scene->addItem(flower4);

    Flower * flower5 = new Flower();
    flower5->setPos(850,350);
    scene->addItem(flower5);


    // create the player
    player = new Player(); // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);


    // create the score/health
    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    healthboss = new Healthboss();
    healthboss->setPos(healthboss->x(),healthboss->y()+50);
    scene->addItem(healthboss);



    Wingame * wingame = new Wingame();
    wingame->setPos(300, 200);
    scene->addItem(wingame);



    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
//    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(draw()));
    timer->start(2000);


    UHD * uhd = new UHD();
    uhd->setPos(0, 550);
    scene->addItem(uhd);

    Avata * avata = new Avata();
    avata->setPos(0,580);
    scene->addItem(avata);

    C * c = new C();
    c->setPos(205,650);
    scene->addItem(c);
    //if(score->getScore()>=10){
        X * x = new X();
        x->setPos(143,650);
        scene->addItem(x);
    //}


    Z * z = new Z();
    z->setPos(111,655);
    scene->addItem(z);

    QMediaPlayer * music= new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/background.mp3"));
    music->play();
    show();
}
void Game::draw(){
    if(score->getScore()<=10){
        setBackgroundBrush(QBrush(QImage(":/img/New map (1).jpg")));
    }
    else if(score->getScore()>10){
        setBackgroundBrush(QBrush(QImage(":/img/nhanvat.jpg")));
    }

}
