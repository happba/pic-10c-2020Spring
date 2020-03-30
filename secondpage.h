#ifndef SECONDPAGE_H
#define SECONDPAGE_H

#include <QWidget>
#include <QLayout>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QTextEdit>
#include <QMediaPlayer>
#include <QStackedWidget>
#include <QAction>
#include "center.h"
#include "hook.h"
#include "playboard.h"


class SecondPage : public QWidget
{
    Q_OBJECT
public:
    SecondPage(QWidget *parent = nullptr);
    ~SecondPage();
    Board* board1=nullptr;
    int totalacc=0;
    int totalunit=0;
    int level = 1;


signals:
    //emit the unit and acc to the mainpage
    void switchtoendpage(double, double);
    //update the score
    void updatescore(int);

public slots:
    //set the focus on the center
    void Setfocus();
    //transfer the unit and acc to the mainpage
    void handlepagechange();
    //handle the score change
    void handlescorechange(int a);
    //create 4 level of boards based on the game
    void toNewLevel();



private:
    QLayout *layout2=nullptr;



};


#endif // SECONDPAGE_H
