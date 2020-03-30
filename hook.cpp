//#include "hook.h"
//#include <QDebug>
//#include <QTransform>



//hook::hook(QGraphicsItem *parent, int width, int height):QGraphicsItem(parent),_width(width),_height(height)
//{
//    _animation = new QGraphicsItemAnimation(this);
//    _timeline = new QTimeLine(5000,this);

//    _animation->setItem(this);
//    _animation->setTimeLine(_timeline);

//    //this->setTransform(QTransform().translate(_width, _height).rotate(0).translate(_width/2, _height));

//    for(int i = 0;i <= 180; i+=18){

//        _animation ->setRotationAt(i/360.0, i-90.0);

//    }
//    for(int i = 0; i <= 180; i+=18){

//        _animation ->setRotationAt((i+180.0)/360.0, 180.0-i-90.0);

//    }

//    _timeline->setCurveShape(QTimeLine::LinearCurve);
//    _timeline->setLoopCount(0);
//    _timeline->start();
//}

//hook::~hook()
//{

//}

//void hook::keyPressEvent(QKeyEvent *event){
//    if(event->key() == Qt::Key_Space){
//        this->hide();
//    }
//}

//QRectF hook::boundingRect() const
//{
//    return QRectF(_width/2,_width/2,_width,_height);
//}

//void hook::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//    painter->drawPixmap(_width/2,_width/2,_width,_height, QPixmap(":/pic/hook.png"));
//}


#include "hook.h"
#include <QDebug>



hook::hook()
{
    QPixmap picture (":/pic/hook1.png");
    picture = picture.scaled(100,50);
    setPixmap(picture);

    //set random position
    int random_number1 =rand() % 700;
    int random_number2 =rand() % 500+100;

    setPos(0,0);

    _animation = new QGraphicsItemAnimation(this);
    _timeline = new QTimeLine(5000,this);

    _animation->setItem(this);
    _animation->setTimeLine(_timeline);

    for(int i = 0;i <= 180; i+=18){
        _animation ->setRotationAt(i/360.0, i-90.0);

    }
    for(int i = 0; i <= 180; i+=18){
        _animation ->setRotationAt((i+180.0)/360.0, 180.0-i-90.0);
    }

    _timeline->setCurveShape(QTimeLine::LinearCurve);
    _timeline->setLoopCount(0);
    _timeline->start();
}

hook::~hook()
{

}







