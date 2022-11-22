#include "game.h"
#include"ice.h"
#include<QGraphicsScene>
#include<QFile>
#include<QDebug>
#include"player.h"
#include"bullet.h"
#include "bulletbox.h"
#include"bulletage.h"
#include<QGraphicsPixmapItem>
#include "bricks.h"
#include "enemy2image.h"
#include"enemyimage.h"
#include "playerimage.h"
#include <QWidget>
#include <QGraphicsRectItem>
#include "house.h"
#include "housee.h"
game::game(QWidget * parent)
{
   //QGraphicsScene * scene = new QGraphicsScene();
   scene = new QGraphicsScene();
   QImage Background("C:/Users/HP/Documents/Practice/background.jpg");
   QGraphicsView * view = new QGraphicsView(scene);
   view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   //setFixedSize(1400,800);
   view->setFixedSize(1300,800);
   scene ->setSceneRect(0,0,1300,800);
   view->setBackgroundBrush(QBrush(Background));
   QFile file("C:/Users/HP/Documents/Practice/map.txt");
   file.open(QIODevice::ReadOnly);
      QTextStream stream(&file);
      int boardData[23][45];
      QGraphicsPixmapItem* dataimage[23][45];
      QString temp;
      for (int i = 0; i < 23; i++)
      {
          for (int j = 0; j < 45; j++)
          {
              stream >> temp;
              //qDebug() << temp;
              //qDebug() << temp.toInt();
              boardData[i][j] = temp.toInt();
              qDebug() << i << " " << j << boardData[i][j]; // boardData is for determining where will they enter the image
          }


      }

      //qDebug() << boardData[1][1];

          for(int i = 0; i < 23; i++)
          {
              for(int j = 0; j < 45; j++)
              {
                  if(boardData[i][j] ==-1)
                  {

                      dataimage[i][j] = new Ice();
                      scene->addItem(dataimage[i][j]);
                      dataimage[i][j]->setPos((j * 30) , (i * 30));
                  }
                  if(boardData[i][j] % 2 == 0 && boardData[i][j] == 4)
                  {
                      dataimage[i][j] = new Bricks();
                      scene->addItem(dataimage[i][j]);
                      dataimage[i][j]->setPos((j * 30) , (i * 30));
                  }
                  if(boardData[i][j] % 2 ==0 && boardData[i][j] == -2)
                  {
                      dataimage[i][j] = new Bricks();
                      scene->addItem(dataimage[i][j]);
                      dataimage[i][j]->setPos((j * 30) , (i * 30));
                      dataimage[i][j] = new house();
                      scene->addItem(dataimage[i][j]);
                      dataimage[i][j]->setPos((j * 30) , (i * 30));
              }
                  if(boardData[i][j] % 2 ==0 && boardData[i][j] == -8)
                  {
                      dataimage[i][j] = new Bricks();
                      scene->addItem(dataimage[i][j]);
                      dataimage[i][j]->setPos((j * 30) , (i * 30));
                      dataimage[i][j] = new housee();
                      scene->addItem(dataimage[i][j]);
                      dataimage[i][j]->setPos((j * 30) , (i * 30));
              }

              }
          }


          //QPixmap enemyimage("C:/Users/HP/Documents/Practice/enemy1.png");
          cc = new Player(boardData);
          //make player focusable
          cc->setFlag(QGraphicsItem::ItemIsFocusable);
          cc->setFocus();
          scene->addItem(cc);

          Gate = new gateway(boardData);

          //scene->addItem(Gate);
          //cc->showhearts();

//          Bullet * b = new Bullet();
//          b->setPos(1030, 650);
//          scene->addItem(b);
//          // add item to scene
          //scene->addItem(cc);
          m1=new housemario();
          m1->setPos(740,270);
          scene->addItem(m1);


          bulletbox *b_box=new bulletbox();
          //b_box->title();
          b_box->setPos(1000,490);
          scene->addItem(b_box);

          bulletAge * ba = new bulletAge();
          ba->setPos(1070,610);
          ba->setScale(0.5);
          scene->addItem(ba);

          //healthbox->setScale(0.5);
          healthboxplayer->setPos(110, 490);
          scene->addItem(healthboxplayer);

          powerbox->setPos(710,490);
          scene->addItem(powerbox);

          pw->setPos(740,610);
          scene->addItem(pw);

          healthh->setPos(410,490);
          scene->addItem(healthh);

          cc->showhearts();

//          Bullet * b = new Bullet();
//          b->setPos(1030, 600);
//          scene->addItem(b);

         // scene->addItem(b_box);
          Bullet * bb = new Bullet();
          scene->addItem(bb);
          bb->setPos(30,90);

          Bullet * bb1 = new Bullet();
          scene->addItem(bb1);
          bb1->setPos(1230,30);

          Bullet * bb2 = new Bullet();
          scene->addItem(bb2);
          bb2->setPos(810,360);

          Bullet * bb3 = new Bullet();
          scene->addItem(bb3);
          bb3->setPos(390,360);

          Bullet * bb4 = new Bullet();
          scene->addItem(bb4);
          bb4->setPos(420,150);

          Bullet * bb5 = new Bullet();
          scene->addItem(bb5);
          bb5->setPos(1110,540);

          e1 = new enemy1(boardData);
          scene->addItem(e1);
          e1->showhearts();

          e2 = new enemy2(boardData);
          scene->addItem(e2);
          e2->showhearts();


          enemyimage *eimage = new enemyimage();
          eimage->setPos(170, 610);
          scene->addItem(eimage);


          enemy2image * e2image = new enemy2image();
          e2image->setPos(170, 645);
          scene->addItem(e2image);

          playerimage* play = new playerimage();
          play->setPos(480,610);
          scene->addItem(play);


          p1->setPos(150,500);
          scene->addItem(p1);


          p2->setPos(490,40);
          scene->addItem(p2);//270.345
          //p2->setPos(490,40);


//      for (int i=0;i<40;i++)
//      {
//          for (int j=0;j<14;j++)
//          {
//              if(boardData[i][j]<=0)
//              {
//                  //add bricks to scene
//                  dataimage[i][j] = new Ice();
//                  scene->addItem(dataimage[i][j]);
//                  dataimage[i][j]->setPos(100*j,100*i);
//             }
//          }
//      }



   //qDebug() << "hi";
   view->show();
}

void game::stop()
{
    qDebug() << "I am in game the 7aga is" << this->e1->e1deleted;
    if(this->e1->e11deleted == 0)
    {
    this->e1->timer->stop();
    e1->setEnabled(false);
    }
    if(!this->e2->e2deleted)
    {
    this->e2->timer->stop();
    e2->setEnabled(false);
    }
    cc->setEnabled(false);

    this->DisplayDeath();

        //cc->setFlag(QGraphicsItem::ItemIs);
}


bool game::DisplayDeath()
{
    QGraphicsRectItem *deathpanel = new QGraphicsRectItem(0,0,500,500);
    deathpanel->setPos(400, 100);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    deathpanel->setBrush(brush);
    deathpanel->setOpacity(0.5);
    scene->addItem(deathpanel);

    QPixmap gameOver("C:/Users/HP/Desktop/CCS2/gameover.png");
    gameOver= gameOver.scaledToHeight(400);
    gameOver = gameOver.scaledToWidth(400);
    QGraphicsPixmapItem * gameeO = new QGraphicsPixmapItem(gameOver);
    gameeO->setPos(450, 100);
    scene->addItem(gameeO);

}

void game::win()
{
    cc->setEnabled(false);
    QGraphicsRectItem *deathpanel = new QGraphicsRectItem(0,0,500,500);
    deathpanel->setPos(400, 100);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    deathpanel->setBrush(brush);
    deathpanel->setOpacity(0.5);
    scene->addItem(deathpanel);

    QPixmap gameOver("C:/Users/HP/Desktop/CCS2/youwin.png");
    gameOver= gameOver.scaledToHeight(400);
    gameOver = gameOver.scaledToWidth(400);
    QGraphicsPixmapItem * gameeO = new QGraphicsPixmapItem(gameOver);
    gameeO->setPos(450, 100);
    scene->addItem(gameeO);
}

//void game::endgame()
//{
//    DisplayDeath();
//}
