#ifndef ENEMY2IMAGE_H
#define ENEMY2IMAGE_H
#include<QGraphicsPixmapItem>
#include<QGraphicsItem>

class enemy2image:public QObject,public QGraphicsPixmapItem
{
   Q_OBJECT;
public:
    enemy2image(QGraphicsItem * parent = 0);
};

#endif // ENEMY2IMAGE_H
