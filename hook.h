#ifndef HOOK_H
#define HOOK_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QLabel>
#include <QPixmap>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QKeyEvent>

//class hook : public QObject, public QGraphicsItem
//{
//   Q_OBJECT
//public:
//    hook(QGraphicsItem* parent = nullptr, int width = 48, int height = 48);
//    ~hook()override;
//    //void keyPressEvent(QKeyEvent* event)override;
//    //void paintEvent(QPaintEvent* event) override;
//    QRectF boundingRect() const override;
//    void keyPressEvent(QKeyEvent *event) override;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
////public slots:
////    void hook_move();
//private:
//    QPixmap pixmap;
//    QGraphicsItemAnimation *_animation = nullptr;
//    int _width;
//    int _height;
//    QTimeLine* _timeline = nullptr;

//};

class hook : public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT
public:
    hook();
    ~hook() override;
    //void keyPressEvent(QKeyEvent* event)override;
    //void paintEvent(QPaintEvent* event) override;
    // QRectF boundingRect() const override;
    // void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    //public slots:
//    void hook_move();
private:
    QPixmap pixmap;
    QGraphicsItemAnimation *_animation = nullptr;
    // int _width;
    // int _height;
    QTimeLine* _timeline = nullptr;

};

#endif // HOOK_H
