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
    if (!is_drawing) {
        qDebug("7777777");
        return;
    }
    first = ev->pos();
}

void Rectangle::mouseMoveEvent(QMouseEvent * ev) {
    if (!is_drawing) {
        return;
    }
    second = ev->pos();
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
     }
    is_drawing = false;
 }
