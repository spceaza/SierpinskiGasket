#include "mywidget.h"
#include <iostream>
#include <math.h>

using namespace std;

void MyWidget::paintEvent(QPaintEvent *event)
{
    QPainter customPainter(this);
    customPainter.fillRect(rect(), Qt::white);

    //create a QPainter and pass a pointer to the device.
    //A paint device can be a QWidget, a QPixmap or a QImage
    QPainter painter(this);

    //create a black pen that has solid line
    //and the width is 2.
    QPen myPen(Qt::black, 1, Qt::SolidLine);
    painter.setPen(myPen);

    vector<int> pointsX;
    vector<int> pointsY;

    int actualPointX = 0;
    int actualPointY = 0;

    int startPointX = 200;
    int startPointY = 200;

    for (int i = 0; i < num; i++) {
            pointsX.push_back((int) (280 + 275 * cos((i * 2 * M_PI / num) + num-(0.4))));
            pointsY.push_back((int) (290 + 275 * sin((i * 2 * M_PI / num) + num-(0.4))));
    }

    pointsX.push_back(280);
    pointsY.push_back(290);

    for (int i = 0; i < num + three; i++) {
        painter.drawLine(pointsX.at(i), pointsY.at(i), pointsX.at(i),
                         pointsY.at(i));
    }

    for (int i = 0; i < iterations; i++) {

        int indexPoint = rand() % (num+three);

        actualPointX = pointsX.at(indexPoint);
        actualPointY = pointsY.at(indexPoint);

        int newPointX = actualPointX - (int) floor(((actualPointX - startPointX) * morphConst));
        int newPointY = actualPointY - (int) floor(((actualPointY - startPointY) * morphConst));

        startPointX = newPointX;
        startPointY = newPointY;

        painter.drawLine(newPointX, newPointY, newPointX, newPointY);
    }

}

void MyWidget::setNum(int newNum){
    this->num = newNum;
}

void MyWidget::setConst(double newConst){
    this->morphConst = newConst;
}

void MyWidget::setIter(long newIter){
    this->iterations = newIter;
}

void MyWidget::set3D(int a)
{
    this->three = (a > 1) ? (a/a) : a;
}
