#ifndef ITEM_H
#define ITEM_H

#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>



class Item: public QGraphicsItem
{
public:
    Item();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


protected:

    void advance(int phase);


private:
    qreal angle;
    qreal speed;
    void DoCollision();

};

#endif // ITEM_H
