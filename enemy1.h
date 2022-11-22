#ifndef ENEMY1_H
#define ENEMY1_H
#include<QObject>
#include<QGraphicsPixmapItem>
#include <QQueue>
#include "heart.h"
#include <QTimer>
class enemy1:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
public:
    enemy1(int Items[23][45], QGraphicsItem * parent = 0);
    int row;
    int colomn;
    int maze[23][45];
    QQueue<heart *> heartp;
    void showhearts();
    void removeheart();
    void reset();
    QTimer * timer = new QTimer();
    void freezeinPlace();
    bool e1deleted = false;
    int e11deleted = 0;
    //bool check();
    //QPixmap anim[2];
    //void flicker();
public slots:
    void move();
};

#endif // ENEMY1_H
