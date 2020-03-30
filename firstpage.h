#ifndef FIRSTPAGE_H
#define FIRSTPAGE_H

#include <QMainWindow>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QPixmap>

class FirstPage : public QWidget
{
    Q_OBJECT
public:
    //the firstpage which is the mainwindow
    FirstPage(QWidget *parent = nullptr);
    ~FirstPage();


signals:


public slots:


private:
    QLabel  *title= nullptr;
    QLabel  *image=nullptr;

};


#endif // FIRSTPAGE_H


