#include "dialog.h"
#include "ui_dialog.h"
#include "item.h"
#include "ball.h"



float move_x = 2.5;
float move_y = 2.0;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui ->graphicsView->setScene(scene);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene ->setSceneRect(-200,-200,300,300);
    QPen mypenRed = QPen(Qt::red);


    QLineF TopLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
    QLineF LeftLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
    QLineF RightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());
    QLineF BottomLine(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());
    // QLineF TopLine3(scene->sceneRect().left(),-140,scene->sceneRect().right(),-140);

    QLineF Line1 (-140,-200,-140,-140);
    QLineF Line2 (-80,-200,-80,-140);
    QLineF Line3 (-20,-200,-20,-140);
    QLineF Line4 (40,-200,40,-140);

    scene ->addLine(TopLine,mypenRed);
    scene ->addLine(BottomLine,mypenRed);
    scene ->addLine(LeftLine,mypenRed);
    scene ->addLine(RightLine,mypenRed);
    // scene ->addLine(TopLine3,mypenRed);
    scene ->addLine(Line1,mypenRed);
    scene ->addLine(Line2,mypenRed);
    scene ->addLine(Line3,mypenRed);
    scene ->addLine(Line4,mypenRed);

      timer = new QTimer(this);
      connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
      timer->start(100);

      QBrush redBrush (Qt::red);
      QPen blackpen(Qt::black);
      blackpen.setWidth(2);
      const QPointF pt;

    int count = 1;
      for (int i = 0; i < count; i++)
      {
         for ( int j = 0; j < count; j++)
         {
             Ball * ball = new Ball(40*i - 150, 40*j - 150, 20,j);

            // ball ->BallSize(40*i,-100,20);
             scene ->addItem(ball);
             ball->setPen(blackpen);
             ball->setBrush(redBrush);


         }
      }




}

Dialog::~Dialog()
{
    delete ui;
}




