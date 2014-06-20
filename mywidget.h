#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QtGui>
#include <QWidget>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    void setNum(int newNum);
    void setConst(double newConst);
    void setIter(long newIter);
    void set3D(int a);

protected:
    void paintEvent(QPaintEvent *event);
    int num = 3;
    int three = 0;
    double morphConst = 0.5;
    long iterations = 10000;
signals:

public slots:

};

#endif // MYWIDGET_H
