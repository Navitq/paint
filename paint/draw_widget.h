#ifndef DRAW_WIDGET_H
#define DRAW_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QMouseEvent>
#include <QList>
#include <QLayout>
#include "rectangle.h"
#include "ellipse.h"
#include "triangle.h"



class Draw_widget : public QWidget
{
    Q_OBJECT


public:
    QList <Rectangle*> rectangel_v;
    QList <Ellipse*> ellipse_v;
    QList <Triangle*> triangle_v;
    explicit Draw_widget(QWidget *parent = nullptr);
    void draw_rectangle();
    void draw_ellipse();
    void draw_triangle();
    QWidget *appWidget;
signals:
};

#endif // DRAW_WIDGET_H
