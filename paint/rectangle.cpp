#include "rectangle.h"

Rectangle::Rectangle(QWidget *parent)
    : QWidget{parent}
{
    first.setX(0);
    first.setY(0);
    second.setX(0);
    second.setY(0);
    qDebug("213123");

}


void Rectangle::mousePressEvent(QMouseEvent * ev) {
    first = ev->pos();
    qDebug("2222");
}

void Rectangle::mouseMoveEvent(QMouseEvent * ev) {

    second = ev->pos();
    update();
    qDebug("5555");

}

void Rectangle::paintEvent(QPaintEvent*)
{

    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 3));
    QRect rect(first.x(), first.y(), second.x()-first.x(), second.y()-first.y());
    painter.drawRect(rect);
    center_x = first.x() + (second.x() - first.x())/2;
    center_y = first.y() + (second.y() - first.y())/2;
    qDebug("3333");

}




 Rectangle::~Rectangle(){
    qDebug("444444444");
}


