#include "mainwindow.h"

#include <QSize>



Mainwindow:: Mainwindow(QWidget* parent)
    :QWidget(parent){
    //home button
    first_page_button = new QPushButton();
    first_page_button->setStyleSheet("border-image:url(:/icon/home_button.png);");
    first_page_button->setFixedSize(80,80);
    first_page_button->setFocusPolicy(Qt::NoFocus);
    //start game button
    second_page_button = new QPushButton();
    second_page_button->setStyleSheet("border-image:url(:/icon/start_button.png);");
    second_page_button->setFixedSize(80,80);
    second_page_button->setFocusPolicy(Qt::NoFocus);
    //instruction button
    instruction_page_button = new QPushButton();
    instruction_page_button->setStyleSheet("border-image:url(:/icon/instruction_icon.png);");
    instruction_page_button->setFixedSize(80,80);
    instruction_page_button->setFocusPolicy(Qt::NoFocus);


    //add button to the horizaontal layout1
    QHBoxLayout* button_layout1 = new QHBoxLayout;
    button_layout1->addWidget(first_page_button);
    button_layout1->addWidget(second_page_button);
    button_layout1->addWidget(instruction_page_button);
    //Added add widgets to layout
    QWidget* button_holder_widget1 = new QWidget;
    button_holder_widget1->setLayout(button_layout1);

    //Set Holder Widget with layout
    main_layout = new QVBoxLayout;
    main_layout->addWidget(button_holder_widget1);

//play background music
theme_song = new QMediaPlayer();
theme_song->setMedia(QUrl("qrc:/music/Riko.mp3"));
theme_song->play();
theme_song->setVolume(40);



stackedwidget= new QStackedWidget;


//add the pages to stackedwidget
firstpage= new FirstPage;
stackedwidget->addWidget(firstpage);

secondpage= new SecondPage;
stackedwidget->addWidget(secondpage);

instruction=new InsPage;
stackedwidget->addWidget(instruction);

winpage=new WinPage;
stackedwidget->addWidget(winpage);

losepage = new LosePage;
stackedwidget->addWidget(losepage);

main_layout->addWidget(stackedwidget);



//music button to mute and turn on music
    mute = new QPushButton();
    mute->setStyleSheet("border-image:url(:/icon/music_icon.png);");
    mute->setFixedSize(50,50);



    //set a quit button to to quit the program
    quit = new QPushButton();
    quit->setFocusPolicy(Qt::NoFocus);
    quit->setStyleSheet("border-image:url(:/icon/quit_icon.png);");
    quit->setFixedSize(50,50);

    //Added buttons to little layout
    QHBoxLayout* button_layout2 = new QHBoxLayout;
    button_layout2->addWidget(mute);
    button_layout2->addWidget(quit);


    QWidget* button_holder_widget2 = new QWidget;
    button_holder_widget2->setLayout(button_layout2);
    main_layout->addWidget(button_holder_widget2);

    this->setLayout(main_layout);

//setting up connections for buttons
connect(first_page_button,SIGNAL(pressed()),this, SLOT(DisplayFirstWidget()));
connect(second_page_button,SIGNAL(pressed()), this, SLOT(DisplaySecondWidget()));
connect(instruction_page_button,SIGNAL(pressed()),this, SLOT(DisplayThirdWidget()));
connect(mute,SIGNAL(pressed()),this, SLOT(music()));
connect(quit,SIGNAL(pressed()),this, SLOT(close()));
//connect the secondpage to transfer score
connect(secondpage, SIGNAL(switchtoendpage(double, double)),this,SLOT(DisplayFourthWidget(double, double)));


}



void Mainwindow::music(){
    //use an integer to pause and restate music
    countformusic++;
    if(countformusic%2!=0){
    theme_song->pause();
    }
    else theme_song->play();
}

void Mainwindow::DisplayFirstWidget()
{
    //show first page
    stackedwidget->setCurrentIndex(stackedwidget->indexOf(firstpage));
}

void Mainwindow::DisplaySecondWidget()
{
    //if the level is less than four
if(secondpage->level<4){
    //if the unit and acc is not zero
    if(unit1 !=0 && accumulate1 !=0){
        //show second page and staart its timer
    stackedwidget->setCurrentIndex(stackedwidget->indexOf(secondpage));
    secondpage->Setfocus();
    secondpage->board1->a_watch->timestart();
    }
}
}


void Mainwindow::DisplayThirdWidget()
{
    //show third window
    stackedwidget->setCurrentIndex(stackedwidget->indexOf(instruction));
}

void Mainwindow::DisplayFourthWidget(double unit, double acc)
{   //displae lose or win page
    unit1=unit;
    accumulate1=acc;
    //if unit and acc are zero, it will go to lsoe page
    if(unit ==0 && acc ==0){   // GPA IS LESS THAN 2 NEED FIXED FROM VINCENT
        stackedwidget->setCurrentIndex(stackedwidget->indexOf(losepage));
    }
    //else go to win page
    else{
        //update the unit and acc
        winpage->update(unit, acc);
        stackedwidget->setCurrentIndex(stackedwidget->indexOf(winpage));
    }

}


Mainwindow::~Mainwindow(){}
