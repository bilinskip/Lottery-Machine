#ifndef BALL_H
#define BALL_H

#include <QPainter>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>


class Ball: public QGraphicsEllipseItem
{
public:
    Ball(int, int, int, char);
   // QRectF boundingRect() const;
    void BallSize(int, int, int);
    void IfCollision();

   //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //char drawNumber(text);

    int xcenter = -100;
    int ycenter = -150;
    int radius = 20;

protected:

    void advance(int phase);

private:
   void DoCollision();
    qreal speed;




};

#endif // BALL_H
