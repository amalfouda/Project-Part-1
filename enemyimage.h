#ifndef ENEMYIMAGE_H
#define ENEMYIMAGE_H
#include<QGraphicsPixmapItem>
#include<QGraphicsItem>

class enemyimage:public QObject,public QGraphicsPixmapItem
{
   Q_OBJECT;
public:
    enemyimage(QGraphicsItem * parent = 0);

};

#endif // ENEMYIMAGE_H
