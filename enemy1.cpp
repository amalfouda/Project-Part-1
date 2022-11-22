#include "enemy1.h"
#include "player.h"
#include "bullet.h"
#include "bulletshot.h"
#include "game.h"
#include<QTimer>
#include"heart.h"
extern game * Game;

enemy1::enemy1(int Items[23][45], QGraphicsItem * parent):QGraphicsPixmapItem(parent)
{
    row = 18;
    colomn = 14;

    for(int i = 0; i < 23; i++)
    {
        for(int j = 0; j < 45; j++)
        {
            maze[i][j] = Items[i][j];
        }
    }

    QPixmap enemy1("C:/Users/HP/Documents/Practice/enemy1.png");
    enemy1 = enemy1.scaledToHeight(45);
    enemy1 = enemy1.scaledToWidth(45);
    setPixmap(enemy1);
    setPos(420, 540);
    //QTimer * timer = new QTimer();
   connect(timer,SIGNAL(timeout()), this, SLOT(move()));
    timer->start(1000);

//    heart * h1 = new heart();
//    heart * h2 = new heart();
//    heart * h3= new heart();
//    heartp.enqueue(h1);
//    heartp.enqueue(h2);
//    heartp.enqueue(h3);
    //scene()->addItem(h1);
}


void enemy1::reset()
{
    row = 18;
    colomn = 14;
    QPixmap enemy1("C:/Users/HP/Documents/Practice/enemy1.png");
    enemy1 = enemy1.scaledToHeight(45);
    enemy1 = enemy1.scaledToWidth(45);
    setPixmap(enemy1);
    setPos(420, 540);
//    QTimer * timer = new QTimer();
//   connect(timer,SIGNAL(timeout()), this, SLOT(move()));
//    timer->start(1000);
}

void enemy1::showhearts()
{


    heart * h1 = new heart();
    heart * h2 = new heart();
    heart * h3= new heart();
    heartp.enqueue(h1);
    heartp.enqueue(h2);
    heartp.enqueue(h3);
    h1->setPos(200,610);
    scene()->addItem(h1);
    h2->setPos(230, 610);
    scene()->addItem(h2);
    h3->setPos(260, 610);
    scene()->addItem(h3);
}
void enemy1::removeheart()
{
    //this->check();
    scene()->removeItem(heartp.front());
    heartp.dequeue();
}
void enemy1::move()
{
    if(Game->cc->numberofbulletshot == 6 && e1deleted == false)
    {
        Game->stop();
    }

    if(Game->cc->hearts.empty())
    {
        Game->stop();
    }
    //this->check();
//    heartp.front()->setPos(110,490);
//    scene()->addItem(heartp.front());
    if((this->colomn > Game->cc->colomn))
    {
        if(row < 20)
        {
        colomn--;
        setPos(x()-30,y());
        }
    }
    else if((this->colomn < Game->cc->colomn))
    {
        if( row  <20)
        {
        colomn++;
        setPos(x()+30,y());
        }
    }
    else if((this->row < Game->cc->row ) )
    {
        if( row <20)
        {
        row++;
        setPos(x(), y() + 30);
        }
    }
    else if((this->row > Game->cc->row))
    {
        if(row <20)
        {
        row--;
        setPos(x(), y() - 30);
        }
    }



    QList <QGraphicsItem *> colliding_item = collidingItems();
        int n = colliding_item.size();
        for(int i = 0; i < n; ++i)
        {
            if(Game->cc->power_up == false)
            {
            if(typeid(*(colliding_item[i])) == typeid(Player))
            {

                Game->healthplayerr->decrease();
                qDebug()<< Game->healthplayerr->Health;
                Game->cc->removeheart();
//                Game->healthplayerr->decrease();
//                Game->cc->removeheart();
                Game->cc->reset();
                if(Game->e1->e11deleted==0)
                {
                Game->e1->reset();
                }
                if(!Game->e2->e2deleted)
                {
                Game->e2->reset();
                }
        }
            }
    }
}

