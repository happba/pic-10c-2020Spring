#ifndef ROPE_H
#define ROPE_H
#define _USE_MATH_DEFINES

#include <QGraphicsRectItem>
#include <QGraphicsObject>
#include <QMediaPlayer>
#include <QSoundEffect>

//signal and slot require qobject
class Rope :public QObject, public QGraphicsLineItem{
    Q_OBJECT
public:
    Rope(double a);                 // constructor with angle argument
    ~Rope();                        // destructor

public slots:
    void move();                    // define how the rope moves in each step
    void SetStep(double, double);   // set up the step size

signals:
    // void catchcomplete();           // signal when the caught class reaches the top
    void collisionhappen();         // signal when collision happens

private:
     QTimer *timermove= nullptr;           // timer for the animating movements of rope
     QSoundEffect* theme_song = nullptr;   // sound effect for class caught

     int collide=0;                 // flag for collision happened
     int outboundary=0;             // flag for rope out of bound
     int angle=0;                   // rope angle from the middle
     double xstep = 0;              // x stepsize
     double ystep = 0;              // y stepsize
};

#endif // ROPE_H
