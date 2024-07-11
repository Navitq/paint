#include "triangle.h"

Triangle::Triangle(Shape *parent)
    : Shape{parent}
{}

Triangle::Triangle(QStringList string)
{
    first.setX(string[0].toInt());
    first.setY(string[1].toInt());
    drawRelease(QPoint(string[2].toInt(),string[3].toInt()));
}

void Triangle::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 3));

    if(first.y() < second.y()){
        painter.drawLine(first.x(),second.y(),second.x(),second.y());
        painter.drawLine(first.x(),second.y(),(first.x()+second.x())/2,first.y());
        painter.drawLine(second.x(),second.y(),(first.x()+second.x())/2,first.y());
    } else {
        painter.drawLine(first.x(),first.y(),second.x(),first.y());
        painter.drawLine(first.x(),first.y(),(first.x()+second.x())/2,second.y());
        painter.drawLine(second.x(),first.y(),(first.x()+second.x())/2,second.y());
    }
}

bool Triangle::point_inside_shape(QPoint pt){
    float d1, d2, d3;
    bool has_neg, has_pos;

    QPoint v1 = QPoint(first.x(),second.y());
    QPoint v2 = QPoint(second.x(),second.y());
    QPoint v3 = QPoint((first.x()+second.x())/2,first.y());

    d1 = sign(pt, v1, v2);
    d2 = sign(pt, v2, v3);
    d3 = sign(pt, v3, v1);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}

float Triangle::sign(QPoint p1, QPoint p2, QPoint p3)
{
    return (p1.x() - p3.x()) * (p2.y() - p3.y()) - (p2.x() - p3.x()) * (p1.y() - p3.y());
}

Triangle::~Triangle(){
}



