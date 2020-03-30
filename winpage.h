#ifndef WINPAGE_H
#define WINPAGE_H

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QPalette>
#include <QPixmap>

class WinPage : public QWidget
{
    Q_OBJECT
public:
    WinPage(QWidget *parent = nullptr);
    ~WinPage();


public slots:
    //update the timer
    void update(double x, double y);




private:
    QLayout *layout1=nullptr;
    QLabel  *label1=nullptr;
    QLabel  *label2=nullptr;
    QLabel  *label3=nullptr;
    QPixmap picture;

};


#endif // WINPAGE_H
