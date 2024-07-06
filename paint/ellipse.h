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
    QHBoxLayout *draw_canvas;
    QPoint first;
    QPoint second;
    ~Ellipse();
signals:
};

#endif // ELLIPSE_H
