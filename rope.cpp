#include "rope.h"
#include "classes.h"
#include "playboard.h"
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QTimer>
#include <QList>
#include <QPen>
#include <QDebug>
#include <QSoundEffect>
#include <cmath>

extern Life* life;
extern Hook* hook;

Rope::Rope(double a)
{
    // Set up default sound effects, inputed angle, step size
    theme_song = new QSoundEffect();
    QPen pen(Qt::black,3,Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin);

    setPen(pen);
    setLine(0,0,0,0);

    angle =a;

    // Original Implementation
    // setRotation(a);

    ystep = 10;
    xstep = -ystep*tan(angle * M_PI / 180.0);

    // Start a new timer to animate movements
    timermove= new QTimer();
    connect(timermove, SIGNAL(timeout()),this, SLOT(move()));

    // Start timer with 50 milisec interval
    timermove->start(50);
}





void Rope::move()
{
    // Determine if the collided with any of the courses
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i=0; i<colliding_items.size();++i)
    {
        if(typeid(*(colliding_items[i]))==typeid(Classes))
        {
            // If collided with any courses, set the flag, play the
            // sound effect, and emit the signal to be received by playboard
            theme_song->setSource(QUrl("qrc:/music/AorB.wav"));
            theme_song->play();
            theme_song->setLoopCount(0);
            emit collisionhappen();
            collide=1;
        }
    }

    // Determine if the rope exceeded the window range
    if((line().x2()>400)||(line().x2()<-400)||(line().y2()>500))
        outboundary=1;

    // Draw a new line every time with default steps before collision
    if(collide==0&&outboundary==0){
        setLine(0,0,line().x2()+xstep,line().y2()+ystep);
    }
    else{
        // Draw a new line every time with updated steps before collision
        setLine(0,0,line().x2()-xstep,line().y2()-ystep);

        // If the rope comes back to the top, delete the object, set hook visible
        // and emit signal to be received by
        if(line().y2()<10){
           scene()->removeItem(this);
           life->decrease();
           hook->setVisible(true);
           hook->_timer.start();

           delete this;

    }
}

}


void Rope::SetStep(double _xstep, double _ystep)
{
    // If angle within the 60 degree range,
    // attach the rope to the sides of the class,
    // otherwise attach the rope to the top of the class.
    if((angle>60)||(angle<-60))
    {
        // Use the x step of of caught course to determine steps
        xstep = _xstep;
        ystep = -xstep/tan(angle * M_PI / 180.0);

        // qDebug()<<"Angle: "<<angle;
        // qDebug()<<"X step: "<<xstep;
    }
    else
    {
        // Use the y step of of caught course to determine steps
        // qDebug()<<"Angle: "<<angle;
        ystep = _ystep;
        xstep = -ystep*tan(angle * M_PI / 180.0);
    }

}

Rope::~Rope()
{

}
