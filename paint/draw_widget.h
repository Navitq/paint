#ifndef DRAW_WIDGET_H
#define DRAW_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QMouseEvent>
#include <QList>
#include <QHBoxLayout>
#include "shape.h"
#include "rectangle.h"
#include "ellipse.h"
#include "triangle.h"



class Draw_widget : public QWidget
{
    Q_OBJECT

public slots:
    void on_shape_finished();

public:
    QList <Rectangle*> rectangle_v;
    QList <Ellipse*> ellipse_v;
    QList <Triangle*> triangle_v;
    Shape* active_shape;
    bool shape_found = false;
    short current_action;
    explicit Draw_widget(QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent *event) override;
    void draw_rectangle();
    void draw_ellipse();
    void draw_triangle();
    void shape_moving();
    void delete_shape();
    void mousePressEvent(QMouseEvent * ev) override;
    void mouseMoveEvent(QMouseEvent * ev) override;
    void mouseReleaseEvent(QMouseEvent * ev) override;
    void draw_shape(Shape* shape);
    void find_shape(QMouseEvent* ev);
    bool check_shape(Shape* shape, QMouseEvent* ev);
    void shape_display(Shape* shape);
    QWidget *appWidget;
signals:
};

#endif // DRAW_WIDGET_H
