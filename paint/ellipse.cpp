#include "ellipse.h"
#include <cmath>

Ellipse::Ellipse(Shape* parent)
    : Shape{parent}
{}

bool Ellipse::point_inside_shape(QPoint p){
    // (h,k) origin
    // rx,ry radiuses
    int rx = width/2;
    int ry = height/2;
    int h = first.x()+rx;
    int k = first.y()+ry;
    if(pow(p.x()-h,2)/pow(rx, 2)+pow(p.y()-k,2)/pow(ry, 2) <= 1){
        return true;
    }
    return false;
}

void Ellipse::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 3));
    painter.drawEllipse(first.x(), first.y(), second.x()-first.x(), second.y()-first.y());
}

Ellipse::~Ellipse(){
}
