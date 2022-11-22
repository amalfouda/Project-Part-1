#ifndef ENEMY2_H
#define ENEMY2_H
#include<QObject>
#include<QGraphicsPixmapItem>
#include"heart.h"
#include <QQueue>
#include <QTimer>
class enemy2:public QObject, public QGraphicsPixmapItem
{
     Q_OBJECT
public:
    enemy2(int Items[23][45], QGraphicsItem * parent = 0);
    int row;
    int colomn;
    int maze[23][45];
    int zup;
    QQueue<heart *> heartp;
    void showhearts();
    void removeheart();
    void reset();
    QTimer * timer = new QTimer();
    bool e2deleted = false;
public slots:
    void move();
};

#endif // ENEMY2_H
