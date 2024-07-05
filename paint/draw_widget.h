#ifndef DRAW_WIDGET_H
#define DRAW_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPalette>


class Draw_widget : public QWidget
{
    Q_OBJECT


public:
    explicit Draw_widget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    void draw_rectangle(QPaintEvent*);
signals:
};

#endif // DRAW_WIDGET_H
