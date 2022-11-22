#include "housee.h"

housee::housee(QGraphicsItem * parent): QGraphicsPixmapItem(parent)
               {
                   QPixmap h("C:/Users/HP/Documents/Practice/house.png");
                   h = h.scaledToHeight(30);
                   h = h.scaledToWidth(30);
                   setPixmap(h);


               }

