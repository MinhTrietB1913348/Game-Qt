#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Bullet2.h"
#include "Bullet3.h"
#include "Bulletpro.h"
#include "Bulletend.h"
#include "Enemy.h"
#include "Enemy1.h"
#include "Enemy3.h"
#include "Enemy4.h"
#include "Enemy5.h"
#include "Boss.h"
#include "Score.h"
#include "Game.h"
#include <QDebug>
#include <QTimer>

extern Game * game;


Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletsound =new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/bullet.wav"));
    bulletsound1 =new QMediaPlayer();
    bulletsound1->setMedia(QUrl("qrc:/sounds/bullet2.wav"));
    picture=1;
    nhanvat=1;
    flagBoss=0;
    QTimer * timer =new QTimer(this);
    //setPixmap(QPixmap(":/img/nhanvat2.png"));
    connect(timer,SIGNAL(timeout()),this,SLOT(draw()));
    timer->start(500);
}

void Player::draw(){
    if(nhanvat==1){
        if(picture==1){
           setPixmap(QPixmap(":/img/dragon_player1.png"));
            picture=2;
        }
        else if(picture==2){
           setPixmap(QPixmap(":/img/dragon_player2.png"));
            picture=3;
        }
        else if(picture==3){
           setPixmap(QPixmap(":/img/dragon_player3.png"));
           picture=4;
        }
        else if(picture==4){
           setPixmap(QPixmap(":/img/dragon_player4.png"));
           picture=1;
        }
    }
    else if(nhanvat==2){
        if(picture==1){
           setPixmap(QPixmap(":/img/dragonEvolve_player1.png"));
            picture=2;
        }
        else if(picture==2){
           setPixmap(QPixmap(":/img/dragonEvolve_player2.png"));
            picture=3;
        }
        else if(picture==3){
           setPixmap(QPixmap(":/img/dragonEvolve_player3.png"));
           picture=4;
        }
        else if(picture==4){
           setPixmap(QPixmap(":/img/dragonEvolve_player4.png"));
           picture=1;
        }
    }

}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 1200)
        setPos(x()+10,y());
    }
//    else if (event->key() == Qt::Key_Z){
//        if(nhanvat==1){
//            nhanvat=2;
//        }
//        else if(nhanvat==2){
//            nhanvat=1;
//        }

//    }
    else if(game->score->getScore()>=10 &&game->score->getScore()<20){
            if (event->key() == Qt::Key_X){
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
            }
            else if (event->key() == Qt::Key_C){
                // create a bullet
                Bulletpro * bulletpro = new Bulletpro();
                bulletpro->setPos(x(),y());
                scene()->addItem(bulletpro);
                //play music
                if(bulletsound1->state()== QMediaPlayer::PlayingState){
                    bulletsound1->setPosition(0);
                }
                else if(bulletsound1->state()==QMediaPlayer::StoppedState){
                    bulletsound1->play();
                }
            }
    }
    else if(game->score->getScore()>=20){
            if (event->key() == Qt::Key_X){
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
//            else if (event->key() == Qt::Key_X){
//            Bullet2 * bullet2 = new Bullet2();
//            bullet2->setPos(x(),y());
//            scene()->addItem(bullet2);
//                //play music
//                if(bulletsound->state()== QMediaPlayer::PlayingState){
//                    bulletsound->setPosition(0);
//                }
//                else if(bulletsound->state()==QMediaPlayer::StoppedState){
//                    bulletsound->play();
//                }
//            }
            else if (event->key() == Qt::Key_Z){
                // create a bullet
                Bulletend * bulletend = new Bulletend();
                bulletend->setPos(x(),y());
                scene()->addItem(bulletend);
                //play music
                if(bulletsound->state()== QMediaPlayer::PlayingState){
                    bulletsound->setPosition(0);
                }
                else if(bulletsound->state()==QMediaPlayer::StoppedState){
                    bulletsound->play();
                }
            }
            else if (event->key() == Qt::Key_C){
                // create a bullet
                Bulletpro * bulletpro = new Bulletpro();
                bulletpro->setPos(x(),y());
                scene()->addItem(bulletpro);
                if(bulletsound1->state()== QMediaPlayer::PlayingState){
                    bulletsound1->setPosition(0);
                }
                else if(bulletsound1->state()==QMediaPlayer::StoppedState){
                    bulletsound1->play();
                }
            }

    }
    // shoot with the spacebar


    else if (event->key() == Qt::Key_C){
        // create a bullet
        Bulletpro * bulletpro = new Bulletpro();
        bulletpro->setPos(x(),y());
        scene()->addItem(bulletpro);
        if(bulletsound1->state()== QMediaPlayer::PlayingState){
            bulletsound1->setPosition(0);
        }
        else if(bulletsound1->state()==QMediaPlayer::StoppedState){
            bulletsound1->play();
        }
    }
//    else if (event->key() == Qt::Key_R){
//        // create a bullet
//        Bulletend * bulletend = new Bulletend();
//        bulletend->setPos(x(),y());
//        scene()->addItem(bulletend);
//    }
}

void Player::spawn(){
    // create an enemy
    if(game->score->getScore()<10 && game->health->getHealth()>0 ){
        Enemy * enemy = new Enemy();
        scene()->addItem(enemy);
    }
    if(game->score->getScore()>=10 && game->score->getScore()<20 && game->health->getHealth()>0){
        Enemy1 * enemy1 = new Enemy1();
        scene()->addItem(enemy1);
        Enemy4 * enemy4 = new Enemy4();
        scene()->addItem(enemy4);
    }
    if(game->score->getScore()>=20 && flagBoss==0 && game->health->getHealth()>0){
        flagBoss = 1;
        Boss * boss= new Boss();
        boss->setPos(400,0);
        scene()->addItem(boss);
    }

    if(game->score->getScore()>=20 && game->healthboss->getHealthboss()>0 && game->health->getHealth()>0){
        Enemy3 * enemy3 = new Enemy3();
        scene()->addItem(enemy3);
    }

    if(game->healthboss->getHealthboss()<=10 &&game->health->getHealth()>0 &&game->healthboss->getHealthboss()>0){
        Enemy5 * enemy5 = new Enemy5();
        scene()->addItem(enemy5);
    }

    if(game->score->getScore() >= 10){
         nhanvat=2;
    }


}
