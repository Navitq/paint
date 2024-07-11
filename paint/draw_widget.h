#ifndef DRAW_WIDGET_H
#define DRAW_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QMouseEvent>
#include <QList>
#include <QHBoxLayout>
#include <QUuid>
#include <QFile>
#include <QTextStream>
#include "shape.h"
#include "rectangle.h"
#include "ellipse.h"
#include "triangle.h"
#include "line.h"


class Draw_widget : public QWidget
{
    Q_OBJECT

public slots:
    //void on_shape_finished();

public:
    QList <Rectangle*> rectangle_v;
    QList <Ellipse*> ellipse_v;
    QList <Triangle*> triangle_v;
    QList <std::pair<Line*, bool>> line_v;
    Shape* active_shape;
    Shape* active_shape2;
    bool shape_found = false;
    bool shape_found2 = false;
    short current_action;
    explicit Draw_widget(QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent *event) override;
    void draw_rectangle();
    void draw_ellipse();
    void draw_triangle();
    void delete_shape();
    void mousePressEvent(QMouseEvent * ev) override;
    void mouseMoveEvent(QMouseEvent * ev) override;
    void mouseReleaseEvent(QMouseEvent * ev) override;
    void draw_shape(Shape* shape);
    void find_shape(QMouseEvent* ev);
    bool check_shape(Shape* shape, QMouseEvent* ev);
    void find_shape2(QMouseEvent* ev);
    bool check_shape2(Shape* shape, QMouseEvent* ev);
    void shape_display(Shape* shape);
    void save_data();
    QSize get_size();
    QString get_position_list(QList<Ellipse*> ellipse);
    QString get_position_list(QList<Rectangle*> rectangle);
    QString get_position_list(QList<Triangle*> triangle);
    void download_data(QString path);
    QWidget *appWidget;
    void set_action(int x);

    void draw_line();
signals:
};

#endif // DRAW_WIDGET_H
