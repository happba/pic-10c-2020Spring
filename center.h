#ifndef CENTER_H
#define CENTER_H


#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>
#include <QTimer>

class Hook : public QWidget
{
    Q_OBJECT
public:
    //the qwidget holding the hook
    explicit Hook(QWidget *parent = nullptr);
    //paintevent to draw the rotation
    void paintEvent(QPaintEvent *event) override;
    //destructor
    ~Hook();
    //timer
    QTimer _timer;
    //the maximum angle along one side
    qreal angle = -75.0;

public slots:
    //update the rotation by time
    void AdvanceState();

private:
    QPainter painter;
    int count = 0;
    int control=0;
    int totalitems=4;
};

#endif // CENTER_H
