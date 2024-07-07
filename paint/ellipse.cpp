#include "ellipse.h"

Ellipse::Ellipse(QWidget *parent)
    : QWidget{parent}
{
    first.setX(0);
    first.setY(0);
    second.setX(0);
    second.setY(0);
    qDebug("213123");
    is_drawing = true;
}

void Ellipse::mousePressEvent(QMouseEvent * ev) {
    if (!is_drawing) {
        return;
    }
    first = ev->pos();
    qDebug("2222");
}



void Ellipse::mouseMoveEvent(QMouseEvent * ev) {
    if (!is_drawing) {
        return;
    }
    second = ev->pos();
    update();
    qDebug("5555");

}

void Ellipse::paintEvent(QPaintEvent*)
{

    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 3));
    painter.drawEllipse(first.x(), first.y(), second.x()-first.x(), second.y()-first.y());
    center_x = first.x() + (second.x() - first.x())/2;
    center_y = first.y() + (second.y() - first.y())/2;
    qDebug("3333");

}

void Ellipse::mouseReleaseEvent(QMouseEvent * ev) {
    if(is_drawing){
        emit is_shape_finished();
    }
    is_drawing = false;

}


Ellipse::~Ellipse(){
    qDebug("444444444");
}
