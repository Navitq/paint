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
    QHBoxLayout *draw_canvas;
    QPoint first;
    QPoint second;
    ~Triangle();
signals:
};

#endif // TRIANGLE_H
