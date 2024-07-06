#ifndef DRAW_WIDGET_H
#define DRAW_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QMouseEvent>
#include <QList>
#include <QLayout>
#include "rectangle.h"




class Draw_widget : public QWidget
{
    Q_OBJECT


public:
    QList <Rectangle*> rectangel_v;
    explicit Draw_widget(QWidget *parent = nullptr);
    // void paintEvent(QPaintEvent*) override;
    void draw_rectangle();
    // void mouseMoveEvent(QMouseEvent * ev) override;
    // void mousePressEvent(QMouseEvent * ev) override;
    QWidget *appWidget;
    // QPoint first;
    // QPoint second;

signals:
};

#endif // DRAW_WIDGET_H
