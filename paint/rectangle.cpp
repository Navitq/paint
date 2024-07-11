#include "rectangle.h"

Rectangle::Rectangle(Shape *parent)
    : Shape{parent}
{}


Rectangle::Rectangle(QStringList string)
{
    first.setX(string[0].toInt());
    first.setY(string[1].toInt());
    drawRelease(QPoint(string[2].toInt(),string[3].toInt()));
}


void Rectangle::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 3));
    QRect rect(first.x(), first.y(), second.x()-first.x(), second.y()-first.y());
    painter.drawRect(rect);
}



bool Rectangle::point_inside_shape(QPoint point){
    if(first.x() < point.x() && point.x() < second.x() && first.y() < point.y() && point.y() < second.y()){
        return true;
    }
    return false;
}

 Rectangle::~Rectangle(){
}

