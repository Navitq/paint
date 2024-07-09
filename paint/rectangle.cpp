#include "rectangle.h"

Rectangle::Rectangle(Shape *parent)
    : Shape{parent}
{}

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

