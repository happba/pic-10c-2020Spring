#include "center.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include <QBrush>
#include <QTransform>

Hook::Hook(QWidget *parent) : QWidget(parent),painter(this)
{
//setup connection between timer and update angle
    connect(&_timer, SIGNAL(timeout()), this, SLOT(AdvanceState()));
    _timer.start(10);

}

void Hook::paintEvent(QPaintEvent *event)
{
    //use the painter to draw angle rotation
    painter.begin(this);
    //use the pic as hook
    QPixmap pixmap(":/pic/hookupdate12.png");
    pixmap = pixmap.scaled(100,100, Qt::KeepAspectRatio);


    //location of the hook
    qreal xc = pixmap.width()/2;
    qreal yc = 0;
    //painter
    painter.translate(xc+350, yc+100);
    //rotate the hook
    painter.rotate(angle);

    qreal rx = -(0);
    qreal ry = 0;
    painter.drawPixmap(rx, ry, pixmap);
    painter.end();

}


void Hook::AdvanceState(){
    //perioddiclly update the angle and count to 150 degree
    if((count/150)%2 == 0 ){
        angle++;
        count++;
    }
    else{
        angle--;
        count++;
    }

    update();
}

Hook::~Hook()
{

}

