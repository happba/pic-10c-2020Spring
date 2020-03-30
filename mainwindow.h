#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QWidget>
#include <QLayout>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QIcon>
#include <QTextEdit>
#include <QMediaPlayer>
#include <QStackedWidget>
#include "firstpage.h"
#include "secondpage.h"
#include "instructionpage.h"
#include "winpage.h"
#include "losepage.h"



class Mainwindow:public QWidget{
    Q_OBJECT
public:
    //stacked window to hold all the window
    Mainwindow(QWidget *parent = nullptr);
    ~Mainwindow();


signals:

public slots:
    //mute music and start music
    void music();
    //display the first window
    void DisplayFirstWidget();
    //display the second window
    void DisplaySecondWidget();
    //display the instruction page
    void DisplayThirdWidget();
    //display the winor lose page
    void DisplayFourthWidget(double, double);

private:
    QStackedWidget* widget_holder = nullptr;
    QVBoxLayout* main_layout = nullptr;
    QPushButton* first_page_button = nullptr;
    QPushButton* second_page_button = nullptr;
    QPushButton* instruction_page_button = nullptr;
    QPushButton* mute = nullptr;
    QPushButton* quit = nullptr;
    QMediaPlayer* theme_song=nullptr;
    QStackedWidget* stackedwidget=nullptr;
    FirstPage* firstpage=nullptr;
    SecondPage* secondpage=nullptr;
    WinPage* winpage=nullptr;
    InsPage* instruction=nullptr;
    LosePage* losepage = nullptr;
    int countformusic=0;
    double accumulate1=1;
    double unit1=1;
};





#endif // MAINWINDOW_H
