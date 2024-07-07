#ifndef DRAW_WIDGET_H
#define DRAW_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QMouseEvent>
#include <QList>
#include <QHBoxLayout>
#include "rectangle.h"
#include "ellipse.h"
#include "triangle.h"



class Draw_widget : public QWidget
{
    Q_OBJECT

public slots:
    void on_shape_finished();

public:
    QList <Rectangle*> rectangel_v;
    QList <Ellipse*> ellipse_v;
    QList <Triangle*> triangle_v;
    short current_shape;
    explicit Draw_widget(QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent *event);
    void draw_rectangle();
    void draw_ellipse();
    void draw_triangle();
    void shape_moving();
    void delete_shape();
    QWidget *appWidget;
signals:
};

#endif // DRAW_WIDGET_H
