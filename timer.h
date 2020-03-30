#ifndef TIMER_H
#define TIMER_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QGraphicsTextItem>


class countdown:public QObject, public QGraphicsSimpleTextItem
{
    Q_OBJECT
public:
    countdown(QGraphicsItem *parent=0);
    ~countdown();
    //stop the timer
    void timestop();
    //start the timer
    void timestart();
signals:
    //when time stops, to next game
    void toNextGame();

private slots:
    //when time=30 countdown to 0, stop timer
    void myslot();

private:

    QTimer * stop_watch;
    int temp = 30;
    QLabel* display_timer = nullptr;
};

#endif // TIMER_H
