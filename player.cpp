#include "player.h"
#include "bullet.h"
#include "bulletshot.h"
#include<QKeyEvent>
#include<QGraphicsScene>
#include"game.h"
#include "heart.h"
#include "gateway.h"
//game * Game
//Bullet* bb = new Bullet();
extern game * Game;
int specifier = 0;
Player::Player(int Items[23][45], QGraphicsItem * parent):QGraphicsPixmapItem(parent)
{
    row = 9;
    colomn = 23;
    for(int i = 0; i < 23; i++)
    {
        for(int j = 0; j < 45; j++)
        {
            maze[i][j] = Items[i][j];
        }
    }

    QPixmap playerr("C:/Users/HP/Documents/Practice/kirbyright1.png");
    QPixmap p2("C:/Users/HP/Documents/Practice/kirbyright2.png");
    QPixmap p3("C:/Users/HP/Documents/Practice/kirbyright3.png");
//    QPixmap p4("C:/Users/HP/Documents/Practice/right4.png");
//    QPixmap p5("C:/Users/HP/Documents/Practice/right5.png");
//    QPixmap p6("C:/Users/HP/Documents/Practice/right6.png");
    p2 = p2.scaledToHeight(40);
    p2 = p2.scaledToWidth(40);

    p3 = p3.scaledToHeight(40);
    p3 = p3.scaledToWidth(40);

    playerr = playerr.scaledToHeight(40);
     playerr = playerr.scaledToWidth(40);

    anim[0]= playerr;
    anim[1]= p2;
    anim[2] = p3;

    animation[RIGHT].push_back(playerr);
    animation[RIGHT].push_back(p2);
    animation[RIGHT].push_back(p3);

    animation[LEFT].push_back(QPixmap("C:/Users/HP/Documents/Practice/kirbyleft1.png"));
    animation[LEFT].push_back(QPixmap("C:/Users/HP/Documents/Practice/kirbyleft2.png"));
    animation[LEFT].push_back(QPixmap("C:/Users/HP/Documents/Practice/kirbyleft3.png"));

    animation[UPR].push_back(QPixmap("C:/Users/HP/Documents/Practice/kirbyupright1.png"));
    animation[UPR].push_back(QPixmap("C:/Users/HP/Documents/Practice/kirbyupright2.png"));
    animation[UPR].push_back(QPixmap("C:/Users/HP/Documents/Practice/kirbyupright3.png"));

    animation[UPL].push_back(QPixmap("C:/Users/HP/Documents/Practice/kirbyupleft1.png"));
    animation[UPL].push_back(QPixmap("C:/Users/HP/Documents/Practice/kirbyupleft2.png"));
    animation[UPL].push_back(QPixmap("C:/Users/HP/Documents/Practice/kirbyupleft3.png"));

    animation[DOWNR].push_back(QPixmap("C:/Users/HP/Documents/Practice/kirbyrightd1.png"));
    animation[DOWNR].push_back(QPixmap("C:/Users/HP/Documents/Practice/kirbyrightd2.png"));
    animation[DOWNR].push_back(QPixmap("C:/Users/HP/Documents/Practice/kirbyrightd3.png"));

    animation[DOWNL].push_back(QPixmap("C:/Users/HP/Documents/Practice/kirbyleftd1.png"));
    animation[DOWNL].push_back(QPixmap("C:/Users/HP/Documents/Practice/kirbyleftd2.png"));
    animation[DOWNL].push_back(QPixmap("C:/Users/HP/Documents/Practice/kirbyleftd3.png"));

    for(int i = 0; i <animation[LEFT].size(); i++ )
    {
        animation[LEFT][i]= animation[LEFT][i].scaledToHeight(40);
        animation[LEFT][i] = animation[LEFT][i].scaledToWidth(40);
    }

    for(int i = 0; i <animation[UPR].size(); i++ )
    {

        animation[UPR][i]= animation[UPR][i].scaledToHeight(35);
        animation[UPR][i] = animation[UPR][i].scaledToWidth(35);
    }

    for(int i = 0; i <animation[UPL].size(); i++ )
    {

        animation[UPL][i]= animation[UPL][i].scaledToHeight(35);
        animation[UPL][i] = animation[UPL][i].scaledToWidth(35);
    }

    for(int i = 0; i <animation[DOWNR].size(); i++ )
    {

        animation[DOWNR][i]= animation[DOWNR][i].scaledToHeight(35);
        animation[DOWNR][i] = animation[DOWNR][i].scaledToWidth(35);
    }

    for(int i = 0; i <animation[DOWNL].size(); i++ )
    {

        animation[DOWNL][i]= animation[DOWNL][i].scaledToHeight(35);
        animation[DOWNL][i] = animation[DOWNL][i].scaledToWidth(35);
    }
    setPixmap(playerr);
    setPos(690,270);
    player_Direction="right";


//    QPixmap heart("C:/Users/HP/Documents/Practice/heartp.png");
//    heart.scaledToWidth(30);
//    heart.scaledToHeight(30);
//    hearts[0].push_back(heart);
//    hearts[1].push_back(heart);
//    hearts[2].push_back(heart);

}

void Player::reset()
{
    row = 9;
    colomn = 23;
    setPos(690,270);
    player_Direction="right";
    QPixmap playerr("C:/Users/HP/Documents/Practice/kirbyright1.png");
    playerr = playerr.scaledToHeight(40);
    playerr = playerr.scaledToWidth(40);
    setPixmap(playerr);
    setPos(690,270);
    player_Direction="right";
}
void Player::showhearts()
{


    heart * h1 = new heart();
    heart * h2 = new heart();
    heart * h3= new heart();
    hearts.enqueue(h1);
    hearts.enqueue(h2);
    hearts.enqueue(h3);
    h1->setPos(510,610);
    scene()->addItem(h1);
    h2->setPos(540, 610);
    scene()->addItem(h2);
    h3->setPos(570, 610);
    scene()->addItem(h3);
}
void Player::removeheart()
{
    scene()->removeItem(hearts.front());
    hearts.dequeue();
}

void Player::setTime()
{
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this, SLOT(MySlot()));
    timer->start(2000);
}

void Player::MySlot()
{
if (power_up==true)
  {  scene()->removeItem(SQ.front());
    SQ.dequeue();}

    if(SQ.size()==0)
        power_up=false;
}

void Player::keyPressEvent(QKeyEvent* event)
{
    removehouse++;
    if(removehouse == 1)
    {
    Game->scene->removeItem(Game->m1);
    }

    if(Game->cc->hearts.empty())
    {
        Game->stop();
    }
        if ((event->key() == Qt::Key_Left)&&(maze[row][colomn - 1] > 0))
        {
            specifierleftup = 0;
            specifierleftdown = 0;
            colomn--;
            setPos(x()-30,y());
            player_Direction="left";
            //setTransformOriginPoint(15,15);
           // setRotation(180);
            anim_index++;
            qDebug() << anim_index;
            if (anim_index == animation[LEFT].size()) {
                anim_index = 0;
            }
            setPixmap(animation[LEFT][anim_index]);
            specifierleftup++;
            specifierleftdown++;
            player_Direction2 = "left";

        }
        else if ((event->key() == Qt::Key_Right)&&(maze[row][colomn + 1] > 0))
        {
            specifierrightup = 0;
            specifierrightdown = 0;
            colomn++;
            setPos(x()+30,y());
            setTransformOriginPoint(15,15);
            player_Direction="right";
            setRotation(0);
            anim_index++;
            if (anim_index == animation[RIGHT].size()) {
                anim_index = 0;
            }
            setPixmap(animation[RIGHT][anim_index]);
            specifierrightup++;
            specifierrightdown++;
            player_Direction2 = "right";

        }else if ((event->key() == Qt::Key_Up)&&(maze[row-1][colomn] > 0))
        {

            row--;
            setPos(x(),y()- 30);
//            if(player_Direction == "right")
//            {
//               setRotation(270);
//               setTransformOriginPoint(15,15);
//            }
//            else if(player_Direction == "down")
//            {
//                setRotation(270);
//                setTransformOriginPoint(25,25);
//            }
            //setTransformOriginPoint(15,15);
            //player_Direction="up";
            //setRotation(270);
            anim_index++;
            if((player_Direction == "right"))
            {
                player_Direction = "rightup";
                //anim_index++;
                if (anim_index == animation[UPR].size()) {
                    anim_index = 0;
                }
                setPixmap(animation[UPR][anim_index]);
            }
            else if(player_Direction == "left")
            {
                player_Direction = "leftup";
                if (anim_index == animation[UPL].size()) {
                    anim_index = 0;
                }
                setPixmap(animation[UPL][anim_index]);
            }

            else if(player_Direction== "rightup")
            {
                //anim_index++;
                if (anim_index == animation[UPR].size()) {
                    anim_index = 0;
                }
                setPixmap(animation[UPR][anim_index]);
            }

            else if(player_Direction == "leftup")
            {
                if (anim_index == animation[UPL].size()) {
                    anim_index = 0;
                }
                setPixmap(animation[UPL][anim_index]);
            }
            else if(player_Direction == "rightdown")
            {
                player_Direction = "rightup";
                if (anim_index == animation[UPR].size()) {
                    anim_index = 0;
                }
                setPixmap(animation[UPR][anim_index]);
            }
            else if(player_Direction == "leftdown")
            {
                player_Direction = "leftup";
                if (anim_index == animation[UPL].size()) {
                    anim_index = 0;
                }
                setPixmap(animation[UPL][anim_index]);
            }

            player_Direction2 = "up";

        }
        else if((event->key() == Qt::Key_Down)&&(maze[row +1][colomn] > 0))
        {
            row++;
            setPos(x(),y()+30);
            //setTransformOriginPoint(15,15);
            //player_Direction="down";
            //setRotation(90);
            anim_index++;
            if((player_Direction == "right"))
            {
                player_Direction ="rightdown";
                //anim_index++;
                if (anim_index == animation[DOWNR].size()) {
                    anim_index = 0;
                }
                setPixmap(animation[DOWNR][anim_index]);
            }
            else if(player_Direction == "left")
            {
                player_Direction ="leftdown";
                if (anim_index == animation[DOWNL].size()) {
                    anim_index = 0;
                }
                setPixmap(animation[DOWNL][anim_index]);
            }

            else if(player_Direction == "rightdown")
            {
                //anim_index++;
                if (anim_index == animation[DOWNR].size()) {
                    anim_index = 0;
                }
                setPixmap(animation[DOWNR][anim_index]);
            }

            else if(player_Direction == "leftdown")
            {
                if (anim_index == animation[DOWNL].size()) {
                    anim_index = 0;
                }
                setPixmap(animation[DOWNL][anim_index]);
            }

            else if (player_Direction == "rightup")
            {
                player_Direction = "rightdown";
                if (anim_index == animation[DOWNR].size()) {
                    anim_index = 0;
                }
                setPixmap(animation[DOWNR][anim_index]);
            }

            else if(player_Direction == "leftup")
            {
                player_Direction = "leftdown";
                if (anim_index == animation[DOWNL].size()) {
                    anim_index = 0;
                }
                setPixmap(animation[DOWNL][anim_index]);
            }

            //player_Direction="down";


                /*if (anim_index == 3) {
                    anim_index = 0;
                }
                setPixmap(anim[anim_index]);*/
            player_Direction2 = "down";

        }

        else if(event->key()==Qt::Key_Space && this->number_bullets > 0){
            bulletshot* bullet = new bulletshot(0, this->player_Direction2);
            if((this->player_Direction2 == "right") && (maze[row][colomn + 1] > 0))
              {
                bullet->setPos(x() + 20,y() + 10);
                scene()->addItem(bullet);
                scene()->removeItem(BQ.dequeue());
                (this->number_bullets)--;
                (specifier++);
                //qDebug() << "Decresed " << this->number_bullets;

            }
            else if(this->player_Direction2 == "left" &&(maze[row][colomn - 1] > 0))
            {
                bullet->setPos(x() - 30, y() + 7);
                scene()->addItem(bullet);
                scene()->removeItem(BQ.dequeue());
                (this->number_bullets)--;
                (specifier++);
                //qDebug() << "Decresed " << this->number_bullets;
                if(numberofbulletshot == 6 && Game->e1->e1deleted == false && bullet->removed == true)
                {
                    Game->stop();
                }
            }
            else if(this->player_Direction2 == "up"&&(maze[row-1][colomn] > 0))
            {
                bullet->setPos(x() + 2 ,y() - 40);
                scene()->addItem(bullet);
                scene()->removeItem(BQ.dequeue());
                (this->number_bullets)--;
                (specifier++);
                //qDebug() << "Decresed " << this->number_bullets;
            }
            else if (this->player_Direction2 == "down" &&(maze[row +1][colomn] > 0))
            {
                bullet->setPos(x() ,y() + 50);
                scene()->addItem(bullet);
                scene()->removeItem(BQ.dequeue());
                (this->number_bullets)--;
                (specifier++);
                //qDebug() << "Decresed " << this->number_bullets;

            }

        }

        QList<QGraphicsItem*> items = collidingItems();
        for (int i = 0; i < items.size(); i++)
        {
            if (typeid(*items[i]) == typeid(Bullet))
            {

                scene()->removeItem(items[i]);
                (this->number_bullets)++;
                Bullet * b = new Bullet();
                BQ.enqueue(b);
                //qDebug() << "Added1 " <<this->number_bullets;
                if(specifier > 0)
                {
                b->setPos(1030 + 220 - ((number_bullets+specifier) * 30), 650);
                }
                else
                {
                    b->setPos(1030 + 220 - ((number_bullets) * 30), 650);
                }
                qDebug() << "Position " << (1030 + 220 - (number_bullets * 30));
                scene()->addItem(b);
                //(this->number_bullets)++;
                //qDebug() << "Added " <<this->number_bullets;
            }
            else if (typeid(*items[i]) == typeid(enemy1))
            {
                if(this->power_up == false)
                {
                Game->healthplayerr->decrease();
                Game->cc->removeheart();
                if(Game->healthe1->Health > 0)
                {
                /*Game->healthplayerr->decrease();
                Game->cc->removeheart()*/;
                Game->cc->reset();
                if(!Game->e1->e1deleted)
                {
                Game->e1->reset();
                }
                if(!Game->e2->e2deleted)
                {
                Game->e2->reset();
                }
                }
                }
//                else if(Game->healthplayerr->Health == 0)
//                {
//                    Game->stop();
//                    return;
//                }
            }

            else if (typeid(*items[i]) == typeid(enemy2))
            {
                if(this->power_up == false)
                {
                Game->healthplayerr->decrease();
                Game->cc->removeheart();
                /*Game->healthplayerr->decrease();
                Game->cc->removeheart()*/;
                Game->cc->reset();
                qDebug() << "is dleted " << Game->e1->e1deleted;
                if(Game->e1->e11deleted == 0)
                {
                Game->e1->reset();
                }
                if(!Game->e2->e2deleted)
                {
                Game->e2->reset();
                }
                }
//                else if(Game->healthplayerr->Health == 0)
//                {
//                    Game->stop();
//                    //Game->DisplayDeath();
//                    return;
//                }
            }
            else if(typeid(*items[i]) == typeid(gateway))
            {
                Game->win();
            }

        }

        QList<QGraphicsItem*>power_1=collidingItems();
                for(int i=0;i<power_1.size();i++)
                {
                    //this->power_up=true;
                    if(typeid(*power_1[i])==typeid(power))
                {   scene()->removeItem(power_1[i]);

                        this->power_up=true;
                        (this->number_power)++;
                        powersqr *  p_sqr=new powersqr();
                        //scene()->addItem(p_sqr);
                        p_sqr->setPos(770,630);
                        scene()->addItem(p_sqr);
                         SQ.enqueue(p_sqr);
                         powersqr *  p_sqr2=new powersqr();
                         scene()->addItem(p_sqr2);
                         p_sqr2->setPos(810,630);
                          SQ.enqueue(p_sqr2);
                          powersqr *  p_sqr3=new powersqr();
                          scene()->addItem(p_sqr3);
                          p_sqr3->setPos(850,630);
                           SQ.enqueue(p_sqr3);
                           powersqr *  p_sqr4=new powersqr();
                           scene()->addItem(p_sqr4);
                           p_sqr4->setPos(890,630);
                            SQ.enqueue(p_sqr4);
                            powersqr *  p_sqr5=new powersqr();
                            scene()->addItem(p_sqr5);
                            p_sqr5->setPos(930,630);
                             SQ.enqueue(p_sqr5);
                             setTime();

                    }

            }
}


