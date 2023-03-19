#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Player2.h"
#include "Score.h"
#include "Health.h"
#include "Healthboss.h"


class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Player2 * player2;
    Score * score;
    Health * health;
    Healthboss * healthboss;
    void draw();
private:
    int picture;
};

#endif // GAME_H
