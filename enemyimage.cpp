#include "enemyimage.h"

enemyimage::enemyimage(QGraphicsItem * parent): QGraphicsPixmapItem(parent)
{
    QPixmap enemyimage("C:/Users/HP/Documents/Practice/enemy1.png");
    enemyimage = enemyimage.scaledToHeight(45);
    enemyimage = enemyimage.scaledToWidth(45);
    setPixmap(enemyimage);


}
