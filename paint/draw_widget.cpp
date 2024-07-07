#include "draw_widget.h"
#include <QMessageBox>

Draw_widget::Draw_widget(QWidget *parent)
    : QWidget{parent}
{
    QHBoxLayout *draw_canvas = new QHBoxLayout(this);

    draw_canvas->setContentsMargins(0, 0, 0, 0);
    draw_canvas->setSpacing(0);

    this->setLayout(draw_canvas);

    QPalette Pal(palette());
    Pal.setColor(QPalette::Window, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
    this->show();

    QList <Rectangle*> rectangel_v;
    QList <Ellipse*> ellipse_v;
    QList <Triangle*> triangle_v;
}

    void Draw_widget::resizeEvent(QResizeEvent *event) {
        QWidget::resizeEvent(event);
        for (auto *rect : rectangel_v) {
            rect->setGeometry(this->rect());
        }
        for (auto *ellipse : ellipse_v) {
            ellipse->setGeometry(this->rect());
        }
        for (auto *triangle : triangle_v) {
            triangle->setGeometry(this->rect());
        }
    }

    void Draw_widget::draw_rectangle(){
        Rectangle *new_rect = new Rectangle();
        //this->layout()->addWidget(new_rect);
        new_rect->setGeometry(this->rect());
        new_rect->setParent(this);
        new_rect->show();

        rectangel_v.push_back(new_rect);
    }

    void Draw_widget::draw_ellipse(){
        Ellipse *new_ellipse = new Ellipse();
        //this->layout()->addWidget(new_ellipse);
        new_ellipse->setGeometry(this->rect());
        new_ellipse->setParent(this);
        new_ellipse->show();
        ellipse_v.push_back(new_ellipse);
    }

    void Draw_widget::draw_triangle(){
        Triangle *new_triangle = new Triangle();
        //this->layout()->addWidget(new_triangle)
        new_triangle->setGeometry(this->rect());
        new_triangle->setParent(this);
        new_triangle->show();;
        triangle_v.push_back(new_triangle);
    }



