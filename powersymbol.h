#ifndef POWERSYMBOL_H
#define POWERSYMBOL_H
#include<QObject>
#include<QGraphicsPixmapItem>
#include<QGraphicsItem>

class powersymbol: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    powersymbol(QGraphicsItem *parent=0);
};

#endif // POWERSYMBOL_H
