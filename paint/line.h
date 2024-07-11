#ifndef LINE_H
#define LINE_H

#include <QWidget>
#include "shape.h"

class Line : public QWidget
{
    Q_OBJECT
public:
    explicit Line(QWidget *parent = nullptr);
    Line(Shape *shape_one, Shape *shape_two);

    QPoint first = QPoint(0,0);
    QPoint second = QPoint(0,0);

    Shape* first_shape;
    Shape* second_shape;

    void paintEvent(QPaintEvent*);

    void drawPress(Shape* shape, QPoint point);
    void drawMove(QPoint point);
    void drawRelease(Shape* shape);
    void moveMove(Shape* shape);

    bool points_to(Shape* shape);
    bool points_to_first(Shape* shape);
    bool points_to_second(Shape* shape);

signals:
};

#endif // LINE_H
