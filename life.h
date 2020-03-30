#ifndef LIFE_H
#define LIFE_H

#include <QGraphicsTextItem>
#include <QString>
#include <QFont>
#include <QObject>

class Life: public QObject, public QGraphicsSimpleTextItem{
Q_OBJECT
public:
    explicit Life(QObject *parent=0);
    ~Life();
    //minus the life
    void decrease();
    //get the current life
    int get_life();
signals:
    //emit the signal
    void gameover();


private:
    int life=0;

};


#endif // LIFE_H
