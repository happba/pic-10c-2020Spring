#include "timer.h"
#include <QtCore>
#include <QTimer>
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QBoxLayout>


countdown::countdown(QGraphicsItem *parent): QGraphicsSimpleTextItem(parent)
{

    setText(QString("Time Left: ")+QString::number(temp));
    setPos(500,10);

    setFont(QFont("Microsoft YaHei",24));
    //intialize the QTimer
    stop_watch = new QTimer(this);
    //connect the timer to the update a signal to next level
    connect(stop_watch, SIGNAL(timeout()), this, SLOT(myslot()));

    stop_watch->start(1000);
}


void countdown::myslot(){
    //count down from set time 30
    --temp;

    if(temp==0){
        stop_watch->stop();
        emit toNextGame();
    }

    setText(QString("Time Left: ")+QString::number(temp));
}


countdown::~countdown(){}

void countdown::timestop()
{
    stop_watch->stop();
}

void countdown::timestart()
{
    stop_watch->start();
}
