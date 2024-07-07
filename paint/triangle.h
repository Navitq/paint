#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QPushButton>

class Triangle : public QWidget
{
    Q_OBJECT
public:
    explicit Triangle(QWidget *parent = nullptr);
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
    ~Triangle();
signals:
    void is_shape_finished();
};

#endif // TRIANGLE_H
