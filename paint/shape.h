#ifndef SHAPE_H
#define SHAPE_H

#include <QWidget>

class Shape : public QWidget
{
    Q_OBJECT
public:
    explicit Shape(QWidget *parent = nullptr);
    QPoint first = QPoint(0,0);
    QPoint second = QPoint(0,0);

    void drawPress(QPoint point);
    void movePress(QPoint point);
    void drawMove(QPoint point);
    void moveMove(QPoint point);
    void drawRelease(QPoint point);
    void moveRelease(QPoint point);
    QPoint getOrigin();
    void corner_ordering();
    virtual bool point_inside_shape(QPoint point) = 0;

    QPoint move_point;
    int dx;
    int dy;
    int height;
    int width;

signals:
};

#endif // SHAPE_H
