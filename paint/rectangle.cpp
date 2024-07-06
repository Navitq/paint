#include "rectangle.h"

Rectangle::Rectangle(QWidget *parent)
    : QWidget{parent}
{
    first.setX(0);
    first.setY(0);
    second.setX(0);
    second.setY(0);
    qDebug("11111");

}

void Rectangle::mousePressEvent(QMouseEvent * ev) {
    first = ev->pos();
    qDebug("11111");
}

void Rectangle::mouseMoveEvent(QMouseEvent * ev) {

    second = ev->pos();
    update();
    qDebug("11111");

}

void Rectangle::paintEvent(QPaintEvent*)
{

    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 3));
    QRect rect(first.x(), first.y(), second.x()-first.x(), second.y()-first.y());
    painter.drawRect(rect);
    qDebug("444444444");

}

 Rectangle::~Rectangle(){
    qDebug("444444444");
}


