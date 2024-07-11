#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QPushButton>
#include <shape.h>

class Triangle : public Shape
{
    Q_OBJECT
public:
    explicit Triangle(Shape *parent = nullptr);
    Triangle(QStringList string);
    void paintEvent(QPaintEvent*) override;
    bool point_inside_shape(QPoint point) override;
    float sign(QPoint p1, QPoint p2, QPoint p3);
    QHBoxLayout *draw_canvas;
    ~Triangle();
signals:
    //void shape_finished();
};

#endif // TRIANGLE_H
