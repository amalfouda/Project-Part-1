#ifndef GAME_H
#define GAME_H
#include<QGraphicsView>
#include <QObject>
#include<QGraphicsScene>
#include "player.h"
#include "enemy1.h"
#include "health.h"
#include"bulletbox.h"
#include "enemy2.h"
#include "power.h"
#include "powersymbol.h"
#include "gateway.h"
#include "housemario.h"
//#include "powersqr.h"
class game: public QGraphicsView
{
        Q_OBJECT;
public:
    game(QWidget * parent = 0);
    QGraphicsScene * scene;
    Player* cc;
    enemy1 * e1;
    health * healthe1 = new health();
    bulletbox * healthboxplayer = new bulletbox();
    bulletbox* healthh = new bulletbox();
    bulletbox* powerbox = new bulletbox();
    enemy2* e2;
    health * healthe2 = new health();
    health * healthplayerr = new health();
    power *p1=new power();
    power *p2=new power();
    powersymbol *pw = new powersymbol();
    gateway * Gate;
    housemario *m1;
    void stop();
    void win();
//    void endgame();
    bool DisplayDeath();
};

#endif // GAME_H
