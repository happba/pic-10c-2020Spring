#ifndef PLAYBOARD_H
#define PLAYBOARD_H

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
#include "rope.h"
#include "center.h"
#include "hook.h"
#include "score.h"
#include "life.h"
#include "timer.h"
#include "classes.h"



//signal and slot require qobject
class Board : public QWidget{
    Q_OBJECT
public:
    Board( QWidget *parent = nullptr );
    void changetotalnumber(int x);
    void spawn(int start, int num);
    //Hook * hook= nullptr;
    QVector<Classes*> list;
    Classes* a=nullptr;
    QGraphicsScene *scene=nullptr;
    countdown* a_watch = nullptr;
    ~Board();

signals:
    //emit when gameend
   void gend();
   //emit wh
   void gscore(int);
   //emit when timer ends
   void NextGame();
   //trasnfer the speed of the x-step and y-step of classes
   void SpeedSignal(double, double);

public slots:
   //keypressevent to create a rope
   void keyPressEvent(QKeyEvent *event) override;

   //handle the game end fail
   void handlegend();

   //handle the score and transfer its value
   void handlescore(int score);

   //when timer ends go to next level
   void GoNextGame();

   //when collide of class ans rope, emit signal
   void EmitSpeedSignial();

private:

   QGraphicsView *view=nullptr;
   QTimer  *timer=nullptr;
   int totalitems=9;
   double get_x_step();
   double get_y_step();

};


#endif // PLAYBOARD_H
