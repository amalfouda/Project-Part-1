#include "enemy2image.h"

enemy2image::enemy2image(QGraphicsItem * parent): QGraphicsPixmapItem(parent)
                         {
                             QPixmap enemyimage("C:/Users/HP/Documents/Practice/enemy2resize.png");
                             enemyimage = enemyimage.scaledToHeight(45);
                             enemyimage = enemyimage.scaledToWidth(45);
                             setPixmap(enemyimage);
                          }


