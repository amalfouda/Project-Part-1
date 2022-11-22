#include "ice.h"

Ice::Ice(QGraphicsItem * parent): QGraphicsPixmapItem(parent)
{
    QPixmap ice("C:/Users/HP/Documents/Practice/ice.png");
    ice = ice.scaledToHeight(30);
    ice = ice.scaledToWidth(30);
    setPixmap(ice);
}
