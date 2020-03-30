#include "playboard.h"
#include "rope.h"
#include "classes.h"
#include "timer.h"
#include <QGraphicsPixmapItem>
#include <QSoundEffect>

extern Score* score;
extern Life* life;
extern Hook* hook;

Board::Board(QWidget *parent) : QWidget(parent)
{

//graphic scene to hold hook, rope and class
    scene = new QGraphicsScene();

    hook= new Hook();



    score=new Score();
    life=new Life();
    a_watch = new countdown();
    //set the watch to stop when initializing the game
    a_watch->timestop();
    life->setY(y()+25);

    hook->setPalette(Qt::transparent);

    //graphicview to hold the scene
    view = new QGraphicsView (scene);



    QPixmap picture (":/pic/grid.png");

    //set background pic
    picture=picture.scaled(800,800,Qt::IgnoreAspectRatio);
    view->setBackgroundBrush(picture);

    //set the view size
    view->setFixedSize(800,800);
    scene->setSceneRect(0,0,790,786);



    //add items into scene
    scene->addWidget(hook);
    scene->addItem(score);
    scene->addItem(a_watch);

    QGraphicsPixmapItem* player = scene->addPixmap(QPixmap(":/pic/player.png").scaled(100,100));
    player->setPos(330,10);

    scene->update();


    view->setParent(this);

    //use a Qstring to hold the address for classes
    std::vector<QString> address = {":/pic/PIC 10C A.png",":/pic/114 B.png",":/pic/Math33B A.png",":/pic/121 B.png",
                                    ":/pic/Japan3.png",":/pic/150 B.png",":/pic/Japan4.png",
                                    ":/pic/143A B.png",":/pic/172 C.png",":/pic/Af AMer A.png",":/pic/Math 151B D.png",
                                    ":/pic/Japan 50 A.png",":/pic/Math 164 C.png",
                                    ":/pic/Math131A A.png",":/pic/Math171 A.png",
                                    ":/pic/Phys 1B F.png",":/pic/PIC 10B A.png",":/pic/110B C.png"};
    //fetermination of weight and grades
    std::vector<int> weights=   {5,4,3,5,4,3,5,4,3,5,2,4,5,4,2,4,5,3};
    std::vector<double> grades ={4.3,3,4,3,4,3,4,3,2,4,1,4,2,4,4,1,4,2};
        int i = 0;
        int j = 0;
    //push the created classes into the list
        while(j <18)
            {
            a= new Classes(address[i],weights[i], grades[i]);
            list.push_back(a);
            ++i;
            ++j;
        }
    //if life emit gameove, emit handlgameend
    connect(life,SIGNAL(gameover()),this, SLOT(handlegend()));
    //if time reeaches 15s, emit gotonextgame
    connect(a_watch, SIGNAL(toNextGame()), this, SLOT(GoNextGame()));


}

//chnage the current total number in the scene
void Board::changetotalnumber(int x)
{
    totalitems=x;
}

//geenrate classes based on the integers
void Board::spawn(int start, int num)
{

    int j =0;
    while(j <num)
    {
        //add the classes into the scene
        qDebug()<<list.size();
        scene->addItem(list[start+j]);

        ++j;
    }
}







void Board::keyPressEvent(QKeyEvent *event)
{
    //add the sound effect when the space is pressed
    QSoundEffect* q   = new QSoundEffect();
        q->setSource(QUrl("qrc:/music/CorD.wav"));

        //if space is pressed create a rope
            if(event->key() == Qt::Key_Space){
               //play soundeffects
                q->play();
                q->setLoopCount(0);
    //make the hook stop rotating and invisible
            hook->_timer.stop();
            hook->setVisible(false);

    //create a list to see how many items in the scene
            QList<QGraphicsItem*> list=scene->items();
            qDebug()<<list.size();
            int items=list.size();

            //if items equals to the totoalnumebr create a rope
            if(items==totalitems){
            //create rope using the hook's angle
                Rope * b=new Rope(hook->angle);
                //connect the rope with classes signal
                connect(b, SIGNAL(collisionhappen()), this, SLOT(EmitSpeedSignial()));
                connect(this, SIGNAL(SpeedSignal(double, double)), b, SLOT(SetStep(double, double)));

                b->setPos(375,100);
                scene->addItem(b);
        }
            //if items being removed fomr the scene update the total numebr and create rope
            else if (items<totalitems){
                totalitems=items;
                 //create rope using the hook's angle
                Rope * b=new Rope(hook->angle);
                //connect the rope with classes signal
                connect(b, SIGNAL(collisionhappen()), this, SLOT(EmitSpeedSignial()));
                connect(this, SIGNAL(SpeedSignal(double, double)), b, SLOT(SetStep(double, double)));
                b->setPos(375,100);
                scene->addItem(b);

            }
        }

}

void Board::handlegend()
{
 emit gend();
}

void Board::handlescore(int score)
{
    emit gscore(score);
}

void Board::GoNextGame()
{
    emit NextGame();
}


void Board::EmitSpeedSignial()
{
    //get theh speed for rope
    double x_step = get_x_step();
    double y_step = get_y_step();


    emit SpeedSignal(x_step, y_step);
}

double Board::get_x_step()
{
    //determines the x-step based on the catched classes
    for(int i = 0; i < list.size(); i++)
    {
        if((list[i]->count==1)&&(list[i]->arrived!=1))
            return list[i]->x_step;
    }
}

double Board::get_y_step()
{
       //determines the y-step based on the catched classes
    for(int i = 0; i < list.size(); i++)
    {
        if((list[i]->count==1)&&(list[i]->arrived!=1))
            return list[i]->y_step;
    }
}


Board::~Board()
{

}
