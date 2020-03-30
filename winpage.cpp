#include "winpage.h"
#include "score.h"
#include "secondpage.h"
#include <QMovie>
#include <QWidget>



WinPage::WinPage(QWidget *parent):QWidget(parent)

{

    //setbackground
    this->setAutoFillBackground(true);
    QPixmap picture (":/pic/congrats2.png");
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(picture.scaled(700,700).scaled(800, 650)));
    this->setPalette(palette);

    label2= new QLabel(QString::number(0)+QString::number(0));
    QColor col (219, 158, 59);
    label2->setStyleSheet(QStringLiteral("QLabel{ font: bold 30px 'Calibri' }"));
    label2->setGeometry(600, 600, 20, 30);

    layout1= new QVBoxLayout();

    layout1->addWidget(label2);

    this->setLayout(layout1);




}

WinPage::~WinPage()
{

}

void WinPage::update(double unit, double acc)
{

    double gpa = 0;
    //check the unit, if it is not zero, update signal
    if(unit !=0){
        gpa=acc/unit;
    }

  label2->setText(QString("\n")+QString("\n")+QString("\n\n\n\n")+QString("Units: ")+QString::number(unit)+QString("\n")
                  +QString("GPA: ")+QString::number(gpa,'f',2));
  label2->setAlignment(Qt::AlignCenter);
  label2->setFont(QFont("italic",24,75));
}
