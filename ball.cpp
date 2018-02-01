#include "ball.h"

Ball::Ball(int x, int y, int r, char text)
{
   BallSize(x,y,r);

    speed = 10;
    int StartX = 0;
    int StartY = 0;


}

void Ball::BallSize(int x1, int y1, int r1)
{
   // setRect(xcenter, ycenter, radius, radius);
   //etRect(xcenter, ycenter, radius, radius);
    setRect(x1, y1, r1, r1);


}





void Ball::advance(int phase)
{

    if (!phase) return;
    QPointF location = this->pos();

    setPos(mapToParent(0,(speed)));



}
void Ball::IfCollision()
{

    if(scene()->collidingItems(this).isEmpty())
    {
        //no collision

    }
    else
    {
        //collision

        //set new position
        DoCollision();
    }
}



/*void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


    QBrush redBrush (Qt::red);
    QBrush blueBrush(Qt::blue);
    QPen blackpen(Qt::black);
    blackpen.setWidth(2);
   // painter ->fillRect(circle,redBrush);
}
*/
void Ball::DoCollision()
{

    //Get a new position

    //change the angle with a little randomess

    if (((qrand() % 1)))
    {
        setRotation(rotation() + (180 + (qrand() % 10)));

    }

    else
    {
        setRotation(rotation() + (180 + (qrand() % -10)));

    }
   // see if the position is in bounds

    QPointF newpoint = mapToParent(-(boundingRect().width()) , -(boundingRect().width() + 2));


    if (!scene()->sceneRect().contains((newpoint)))
    {
        //move it back in bounds
        newpoint = mapToParent(0,0);
    }

    else
    {
        //set new position
        setPos(newpoint);
    }

}



