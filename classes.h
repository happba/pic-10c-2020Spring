#ifndef CLASSES_H
#define CLASSES_H

#include <QGraphicsRectItem>
#include <QGraphicsObject>



class Classes :public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Classes(QString address, int w, double g);
    ~Classes();
    int count=0;
    double y_step = 0;
    double x_step = 0;
    int arrived = 0;

public slots:
    //move the classes based on the weight and grade
    void move();
    //get the weight of class
    int get_weight() const;
    //set the weight of class
    void set_weight(int w);
    //get the grade of the class
    int get_grade() const;

signals:
    //transfer the value of the moving speed
    void SpeedValueTransfer(int);

private:

    int weight=0;
    double grade =0;

    int speed = 0;
    QString a;
};

#endif // CLASSES_H
