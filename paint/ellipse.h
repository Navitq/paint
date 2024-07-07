#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QPushButton>

class Ellipse : public QWidget
{
    Q_OBJECT
public:
    explicit Ellipse(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*) ;
    void mouseMoveEvent(QMouseEvent * ev) override;
    void mousePressEvent(QMouseEvent * ev) override;
    void mouseReleaseEvent(QMouseEvent * ev);
    bool is_drawing;
    double center_x;
    double center_y;
    QHBoxLayout *draw_canvas;
    QPoint first;
    QPoint second;
    ~Ellipse();
signals:
    void is_shape_finished();
};

#endif // ELLIPSE_H
