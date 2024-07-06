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
    double center_x;
    double center_y;
    QHBoxLayout *draw_canvas;
    QPoint first;
    QPoint second;
    ~Rectangle();
signals:
};

#endif // RECTANGLE_H
