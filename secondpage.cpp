#include "secondpage.h"
#include "classes.h"
#include "rope.h"
#include <QIcon>
#include <QSize>
#include <QGraphicsItemGroup>

extern Score* score;

SecondPage::SecondPage(QWidget *parent) : QWidget(parent) {


layout2= new QGridLayout();

//intialzie the game board
board1=new Board;
//add the classes into the board
board1->spawn(0,4);

layout2->addWidget(board1);


this->setLayout(layout2);

//connect the singal from playboard
connect(board1, SIGNAL(gend()),this, SLOT(handlepagechange()));
connect(board1, SIGNAL(gscore(int)),this, SLOT(handlescorechange(int)));
connect(board1, SIGNAL(NextGame()),this, SLOT(toNewLevel()));

}

SecondPage::~SecondPage()
{

}

void SecondPage::Setfocus()
{

    //make item focus
   board1->setFocus();
   //board1->(player);
   qDebug()<<board1->hasFocus();
}

void SecondPage::handlepagechange()
{
    //update the totalunit and totalaccum from the current game
    totalunit=totalunit+score->get_score();
    totalacc=totalacc+score->get_acc();
    qDebug()<<totalunit<<totalacc;
    //emit the scroe the mainwindow then win page
    emit switchtoendpage(totalunit,totalacc);
}

void SecondPage::handlescorechange(int a)
{
    emit updatescore(a);
}

void SecondPage::toNewLevel()
{
    //if less than 2 classes were catched then emit signal to end page
    if(score->classcount<2){
        emit switchtoendpage(0,0);
    }
    //else update score and remove the current board and create the next level
    else{
    totalunit=totalunit+score->get_score();
    totalacc=totalacc+score->get_acc();
    qDebug()<<totalunit<<totalacc;
    layout2->removeWidget(board1);
    delete board1;
    board1 = new Board;
    //start the timer
    board1->a_watch->timestart();
    layout2->addWidget(board1);

    //if level less and equal to 1,
    if(level<=1)
    {
        //create the 4 classes
        board1->spawn(level*4,4);

        qDebug()<<level;}
    else if( level <4)
    {
        //update the totalnumber to 10
        board1->changetotalnumber(10);
        //add 5 classes to the board
        board1->spawn(8+(level-2)*5,5);}
    else{
        //stop the watch
        board1->a_watch->timestop();
        //emit the the unit and acc to the end page
        emit switchtoendpage(totalunit,totalacc);

    }
    ++level;

    //connect the signal from the board to the secondpage
    connect(board1, SIGNAL(gend()),this, SLOT(handlepagechange()));
    connect(board1, SIGNAL(gscore(int)),this, SLOT(handlescorechange(int)));
    connect(board1, SIGNAL(NextGame()),this, SLOT(toNewLevel()));
    Setfocus();
    }
}

