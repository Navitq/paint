#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QPushButton>


class Rectangle : public QWidget
{
    Q_OBJECT
public:
    explicit Rectangle(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*) ;
    void mouseMoveEvent(QMouseEvent * ev) override;
    void mousePressEvent(QMouseEvent * ev) override;
    void mouseReleaseEvent(QMouseEvent * ev);
    double center_x;
    double center_y;
    bool is_drawing;
    QHBoxLayout *draw_canvas;
    QPoint move_point;
    QPoint first;
    QPoint second;
    ~Rectangle();
signals:
    void is_shape_finished();
};

#endif // RECTANGLE_H
