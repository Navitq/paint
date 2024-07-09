#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QPushButton>
#include "shape.h"

class Ellipse : public Shape
{
    Q_OBJECT
public:
    explicit Ellipse(Shape *parent = nullptr);
    void paintEvent(QPaintEvent*) override;
    bool point_inside_shape(QPoint point) override;
    QHBoxLayout *draw_canvas;
    ~Ellipse();
signals:
    //void shape_finished();
};

#endif // ELLIPSE_H
