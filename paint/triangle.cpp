#include "triangle.h"

Triangle::Triangle(QWidget *parent)
    : QWidget{parent}
{
    first.setX(0);
    first.setY(0);
    second.setX(0);
    second.setY(0);
    qDebug("213123");
}

void Triangle::mousePressEvent(QMouseEvent * ev) {
    first = ev->pos();
    qDebug("2222");
}

void Triangle::mouseMoveEvent(QMouseEvent * ev) {

    second = ev->pos();
    update();
    qDebug("5555");

}

void Triangle::paintEvent(QPaintEvent*)
{

    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 3));
    painter.drawLine(first.x(), first.y(), second.x(), second.y());
    painter.drawLine( second.x(), second.y(), (second.x()-first.x())/2-(second.y()-first.y())/2+first.x() , (second.x()-first.x())*sqrt(3)/2+(second.y()-first.y())*sqrt(3)/2+first.y());
    painter.drawLine((second.x()-first.x())/2-(second.y()-first.y())/2+first.x() , (second.x()-first.x())*sqrt(3)/2+(second.y()-first.y())*sqrt(3)/2+first.y(), first.x(), first.y());

    qDebug("3333");

}

Triangle::~Triangle(){
    qDebug("444444444");
}
