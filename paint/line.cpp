#include "line.h"
#include "qpainter.h"

Line::Line(QWidget *parent)
    : QWidget{parent}
{}

Line::Line(Shape *shape_one, Shape *shape_two)
{
    first_shape = shape_one;
    second_shape = shape_two;
    first = first_shape->getOrigin();
    second = second_shape->getOrigin();
}

void Line::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 3));
    QLine line(first.x(), first.y(), second.x(),second.y());
    painter.drawLine(line);
}

void Line::drawPress(Shape* shape, QPoint point){
    first_shape = shape;
    first = first_shape->getOrigin();
    second = point;
}

void Line::drawMove(QPoint point){
    second = point;
    update();
}

void Line::drawRelease(Shape* shape){
    second_shape = shape;
    second = second_shape->getOrigin();
}

void Line::moveMove(Shape* shape){
    if(points_to_first(shape))
        first = QPoint(shape->getOrigin());
    if(points_to_second(shape))
        second = QPoint(shape->getOrigin());
    update();
}

bool Line::points_to(Shape* shape){
    if(first_shape == shape || second_shape == shape)
        return true;
    return false;
}

bool Line::points_to_first(Shape* shape){
    if(first_shape == shape)
        return true;
    return false;
}

bool Line::points_to_second(Shape* shape){
    if(second_shape == shape)
        return true;
    return false;
}
