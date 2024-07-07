#include "rectangle.h"

Rectangle::Rectangle(QWidget *parent)
    : QWidget{parent}
{
    is_drawing = true;
    first.setX(0);
    first.setY(0);
    second.setX(0);
    second.setY(0);
    qDebug("213123");
}

void Rectangle::mousePressEvent(QMouseEvent * ev) {
    if (is_drawing) {
        first = ev->pos();
    } else {
        move_point = ev->pos();
    }
}

void Rectangle::mouseMoveEvent(QMouseEvent * ev) {
    if (is_drawing) {
        second = ev->pos();
    } else {
        // first.setX(first.x() + ev->pos().x() - move_point.x());
        // first.setY(first.y() + ev->pos().y() - move_point.y());
        // second.setX(second.x() + ev->pos().x() - second.x());
        // second.setY(second.y() + ev->pos().y() - second.y());
    }

    update();
}

void Rectangle::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 3));
    QRect rect(first.x(), first.y(), second.x()-first.x(), second.y()-first.y());
    painter.drawRect(rect);
    center_x = first.x() + (second.x() - first.x())/2;
    center_y = first.y() + (second.y() - first.y())/2;
}

 Rectangle::~Rectangle(){
}

 void Rectangle::mouseReleaseEvent(QMouseEvent * ev) {
     if(is_drawing){
        emit is_shape_finished();
     } else {

     }
    is_drawing = false;
 }
