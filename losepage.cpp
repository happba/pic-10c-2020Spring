#include "losepage.h"


LosePage::LosePage(QWidget *parent):QWidget(parent)
{
    //add the gif
    QMovie* game_lose = new QMovie(":/pic/game_over.gif");
    QLabel* label = new QLabel(this);
    label->setMovie(game_lose);
    game_lose->start();

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(label);
    this->setLayout(layout);
    
}

LosePage::~LosePage()
{

}

void LosePage::update(int unit, int acc)
{
  //update the unit and gpa
  double gpa=acc/unit;
  label2->setText(QString("Units: ")+QString::number(unit)+QString("\n")
                  +QString("GPA: ")+QString::number(gpa));
  label2->setAlignment(Qt::AlignCenter);
  label2->setFont(QFont("italic",24,75));
}
