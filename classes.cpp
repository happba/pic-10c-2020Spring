#include "classes.h"
#include "rope.h"
#include "playboard.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <QDebug>
#include <cmath>

extern Score* score;

Classes::Classes(QString address, int w, double g)
{
    //set random position based on weight and grade
    weight = w;
    grade = g;
    int random_number1 = 0;
    //weight determineds the x position
    if(w==5)
        random_number1= rand() %101+500;
    else if(w==4)
        random_number1= rand() %101+300;
    else
        random_number1= rand() %101+100;

    int random_number2=0;
     QPixmap picture (address);
     //grade determines the y position
    if(g==4)
    {
        random_number2 =rand()%101+450;
        picture=picture.scaled(70, 35);
    }
    else if(g==4.3)
    {
        random_number2 =rand()%101+150;
        picture=picture.scaled(100, 50);
    }

    else if(g==3)
    {
           random_number2 =rand()%101+300;
            picture=picture.scaled(100, 50);

    }
    else if(g==2){
         picture=picture.scaled(125,75);
        random_number2 =rand()%101+150;
    }
    else {
         picture=picture.scaled(175,100);
        random_number2 =rand()%101+250;
    }
    //set the classes with picture of classes


    //int trial = w*g;

    setPixmap(picture);
    //set the s and y position
    setPos(random_number1+50,random_number2);
    //speed determined by weight and grade
    speed = w*g/2;
    //determines the length of the class to the center
    double length = sqrt((y()-10)*(y()-10) + (x()-360)*(x()-360));
    //determines the times needs to go to the center
    double time = length/speed;

    x_step = (x()-360)/time;
    y_step = (y()-10)/time;

    //connect timers to the movement of class

    QTimer *timer= new QTimer();
    connect(timer, SIGNAL(timeout()),this, SLOT(move()));

    //50 milisec
    timer->start(50);
}

Classes::~Classes()
{

}
int Classes::get_weight() const
{
    return weight;
}
void Classes::set_weight(int w)
{
    weight=w;
}
void Classes::move()
{

    //If class will collide with rope
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i=0; i<colliding_items.size();++i){
        if(typeid(*(colliding_items[i]))==typeid(Rope)){
            count=1;
        }
        }
    if(count==1){
    //move classes back
    setPos(x()-x_step,y()-y_step);
    //if the class move out of bound it will delete
    if(pos().y()<80&&(pos().x()>=365||pos().x()<=385)){
        int i = this->get_weight();
        double g = this->get_grade();
        //remove from the scene
        scene()->removeItem(this);
        delete this;
        //add the score
        score->add_weight(i,g);
        arrived = 1;
    }
    }
}

int Classes::get_grade() const{
    return grade;
}
