#include "shape.h"
#include "qevent.h"

Shape::Shape(QWidget* parent)
    : QWidget{parent}
{}

void Shape::drawPress(QPoint point) {
        first = point;
}

void Shape::movePress(QPoint point) {
    move_point = point;
    dx = point.x()-first.x();
    dy = point.y()-first.y();
}

void Shape::drawMove(QPoint point){
    second = point;
    update();
}

void Shape::moveMove(QPoint point){
    first.setX(point.x() - dx);
    first.setY(point.y() - dy);
    second.setX(point.x() - dx + width);
    second.setY(point.y() - dy + height);
    update();
}

void Shape::drawRelease(QPoint point){
    second = point;
    corner_ordering();
    height = second.y()-first.y();
    width = second.x()-first.x();
    emit shape_finished();
}

void Shape::moveRelease(QPoint point){

}

void Shape::corner_ordering(){
    QPoint first = this->first;
    QPoint second = this->second;

    if(first.x() < second.x() && first.y() > second.y()){
        this->first.setY(second.y());
        this->second.setY(first.y());
    }else if(first.x() > second.x() && first.y() < second.y()){
        this->first.setX(second.x());
        this->second.setX(first.x());
    }else if(first.x() > second.x() && first.y() > second.y()){
        this->first.setX(second.x());
        this->first.setY(second.y());
        this->second.setX(first.x());
        this->second.setY(first.y());
    }
}
