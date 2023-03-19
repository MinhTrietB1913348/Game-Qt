#include "Player2.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Bullet2.h"
#include "Bullet3.h"
#include "Bulletpro.h"
#include "Bulletend.h"
#include "Enemy.h"
#include "Enemy1.h"
#include "Boss.h"
#include "Score.h"
#include "Game.h"
#include <QDebug>

extern Game * game;


Player2::Player2(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletsound =new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/bullet.wav"));

    setPixmap(QPixmap(":/img/nhanvat.png"));
}

void Player2::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);

        //play music
        if(bulletsound->state()== QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if(bulletsound->state()==QMediaPlayer::StoppedState){
            bulletsound->play();
        }

        Bullet2 * bullet2 = new Bullet2();
        bullet2->setPos(x(),y());
        scene()->addItem(bullet2);

        //play music
        if(bulletsound->state()== QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if(bulletsound->state()==QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        Bullet3 * bullet3 = new Bullet3();
        bullet3->setPos(x(),y());
        scene()->addItem(bullet3);

        //play music
        if(bulletsound->state()== QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if(bulletsound->state()==QMediaPlayer::StoppedState){
            bulletsound->play();
        }

    }
//    else if (event->key() == Qt::Key_T){
//        // create a bullet
//        Bullet2 * bullet2 = new Bullet2();
//        bullet2->setPos(x(),y());
//        scene()->addItem(bullet2);

//        //play music
//        if(bulletsound->state()== QMediaPlayer::PlayingState){
//            bulletsound->setPosition(0);
//        }
//        else if(bulletsound->state()==QMediaPlayer::StoppedState){
//            bulletsound->play();
//        }

//    }
    else if (event->key() == Qt::Key_Q){
        // create a bullet
        Bulletpro * bulletpro = new Bulletpro();
        bulletpro->setPos(x(),y());
        scene()->addItem(bulletpro);
    }
    else if (event->key() == Qt::Key_R){
        // create a bullet
        Bulletend * bulletend = new Bulletend();
        bulletend->setPos(x(),y());
        scene()->addItem(bulletend);
    }
}

void Player2::spawn(){
    // create an enemy
    if(game->score->getScore()<=15){
        Enemy * enemy = new Enemy();
        scene()->addItem(enemy);
    }
    if(game->score->getScore()>=10 && game->score->getScore()<20){
        Enemy1 * enemy1 = new Enemy1();
        scene()->addItem(enemy1);
    }
    if(game->score->getScore()==20){
        Boss * boss= new Boss();
        boss->setPos(400,0);
        scene()->addItem(boss);
    }

}
//void Player::spawn(){
//    // create an enemy1
//    Enemy1 * enemy1 = new Enemy1();
//    scene()->addItem(enemy1);
//}

