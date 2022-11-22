#include "bricks.h"

Bricks::Bricks(QGraphicsItem * parent): QGraphicsPixmapItem(parent)
{
    QPixmap bricks("C:/Users/HP/Documents/Practice/brick22.png");
    bricks= bricks.scaledToHeight(30);
    bricks = bricks.scaledToWidth(30);
    setPixmap(bricks);
}
