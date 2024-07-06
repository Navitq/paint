#include "ellipse.h"

Ellipse::Ellipse(QWidget *parent)
    : QWidget{parent}
{
    first.setX(0);
    first.setY(0);
    second.setX(0);
    second.setY(0);
    qDebug("213123");
}

void Ellipse::mousePressEvent(QMouseEvent * ev) {
    first = ev->pos();
    qDebug("2222");
}

void Ellipse::mouseMoveEvent(QMouseEvent * ev) {

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

Ellipse::~Ellipse(){
    qDebug("444444444");
}
