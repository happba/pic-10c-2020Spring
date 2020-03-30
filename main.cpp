#include "mainwindow.h"

#include <QApplication>

Score* score;
Life* life;
Hook* hook;


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    Mainwindow h;
    //set the window title
    h.setWindowTitle("GPA MINER");
    h.show();
    return a.exec();


}

/*

*/
