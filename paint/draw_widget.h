#ifndef DRAW_WIDGET_H
#define DRAW_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QMouseEvent>


class Draw_widget : public QWidget
{
    Q_OBJECT


public:
    explicit Draw_widget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*) override;
    void draw_rectangle(QPaintEvent*);
    void mouseMoveEvent(QMouseEvent * ev) override;
    void mousePressEvent(QMouseEvent * ev) override;

    QPoint first;
    QPoint second;

signals:
};

#endif // DRAW_WIDGET_H
