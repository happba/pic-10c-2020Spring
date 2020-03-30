#include "life.h"


Life::Life(QObject *parent): QObject(parent),QGraphicsSimpleTextItem()
{
    life=50;

    setText(QString("Life: ")+QString::number(life));

    setFont(QFont("times",24));


}

Life::~Life()
{

}

void Life::decrease()
{
    //minus the life
    --life;
    setText(QString("Life: ")+QString::number(life));
    //when lift is zero emit signal gameover();
    if(life<=0){
    emit gameover();
    }




}

int Life::get_life()
{

    return life;
}
