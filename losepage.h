#ifndef LOSEPAGE_H
#define LOSEPAGE_H

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QPalette>
#include <QPixmap>
#include <QMovie>

class LosePage : public QWidget
{
    Q_OBJECT
public:
    LosePage(QWidget *parent = nullptr);
    ~LosePage();

signals:


public slots:
    //update the unit and gpa based on the score value
    void update(int x, int y);




private:
    QLayout *layout1=nullptr;
    QLabel  *label1=nullptr;
    QLabel  *label2=nullptr;
    QLabel  *label3=nullptr;
    //QPixmap background;

};

#endif // LOSEPAGE_H
