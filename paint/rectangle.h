#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QPushButton>
#include "shape.h"


class Rectangle : public Shape
{
    Q_OBJECT
public:
    explicit Rectangle(Shape *parent = nullptr);
    void paintEvent(QPaintEvent*) override;
    bool point_inside_shape(QPoint point) override;
    QHBoxLayout *draw_canvas;

    ~Rectangle();
signals:
    //void shape_finished();
};

#endif // RECTANGLE_H
