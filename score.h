#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QString>
#include <QFont>

class Score: public QGraphicsTextItem{
public:
    explicit Score(QGraphicsItem *parent=0);
    ~Score();
    //when classes delete, increasr the score
    void increase();
    //get the score
    int get_score();
    //get the gpa
    double get_gpa();
    //get the accumlate unit
    int get_acc();
    //add the score based on the wight and grade
    void add_weight(int w, double grade);
    int classcount=0;
private:
    int score=0;
    double accumulate =0;
    double gpa=0;
};


#endif // SCORE_H
