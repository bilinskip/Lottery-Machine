#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    QGraphicsScene *hole;
    QGraphicsTextItem *text;
    QGraphicsEllipseItem *ellipse;
protected:


    QTimer *timer;

private slots:

};

#endif // DIALOG_H
