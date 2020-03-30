#include "score.h"


Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //show the unit and gpa
    score=0;
    gpa =0;
    setPlainText(QString("Units: ")+QString::number(score)+QString("\n")
                 +QString("GPA: ")+QString::number(gpa));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",24));

}

Score::~Score()
{

}

void Score::increase()
{
    //update the score
    ++score;
    setPlainText(QString("Score: ")+QString::number(score));
}

int Score::get_score()
{
    return score;
}
double Score::get_gpa()
{
    return gpa;
}

int Score::get_acc()
{
    return accumulate;
}
void Score::add_weight(int i, double grade)
{
    //update the unit and gpa based on the catched classes
    classcount=classcount+1;
    score = score +i;
    accumulate=accumulate+i*grade;
    //calculate the gpa by acculmulate/score
    gpa=accumulate/score;
    setPlainText(QString("Units: ")+QString::number(score)+QString("\n")
                 +QString("GPA: ")+QString::number(gpa));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",24));
}
