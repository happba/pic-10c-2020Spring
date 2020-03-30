#include "firstpage.h"
#include <QPainter>



FirstPage::FirstPage(QWidget *parent) : QWidget(parent) {
//set the background
    this->setAutoFillBackground(true);
    //set the background picture
    QPixmap picture (":/pic/front_page_1.png");
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(picture.scaled(700,700).scaled(900, 650)));
    this->setPalette(palette);



}

FirstPage::~FirstPage()
{

}


