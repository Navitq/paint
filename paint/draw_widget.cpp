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
    QList <Triangle*> triangle_v;
    QList <Ellipse*> ellipse_v;
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
        current_shape = 1;
        Rectangle *new_rect = new Rectangle();
        //this->layout()->addWidget(new_rect);
        new_rect->setGeometry(this->rect());
        new_rect->setParent(this);
        new_rect->show();
        connect(new_rect, new_rect->is_shape_finished, this, on_shape_finished);
        rectangel_v.push_back(new_rect);
    }

    void Draw_widget::draw_ellipse(){
        current_shape = 3;
        Ellipse *new_ellipse = new Ellipse();
        //this->layout()->addWidget(new_ellipse);
        new_ellipse->setGeometry(this->rect());
        new_ellipse->setParent(this);
        new_ellipse->show();
        connect(new_ellipse, new_ellipse->is_shape_finished, this, on_shape_finished);
        ellipse_v.push_back(new_ellipse);
    }

    void Draw_widget::draw_triangle(){
        current_shape = 2;
        Triangle *new_triangle = new Triangle();
        //this->layout()->addWidget(new_triangle)
        new_triangle->setGeometry(this->rect());
        new_triangle->setParent(this);
        new_triangle->show();
        connect(new_triangle, new_triangle->is_shape_finished, this, on_shape_finished);
        triangle_v.push_back(new_triangle);
    }

    void Draw_widget::shape_moving(){
        delete_shape();
        current_shape = 0;

    }

    void Draw_widget::delete_shape(){
        switch (current_shape) {
        case 1:
            if(rectangel_v.length() < 1){
                return;
            }
            delete rectangel_v[rectangel_v.length()-1];
            rectangel_v.pop_back();
            break;
        case 2:
            if(triangle_v.length() < 1){
                return;
            }
            delete triangle_v[triangle_v.length()-1];
            triangle_v.pop_back();
            break;
        case 3:
            if(ellipse_v.length() < 1){
                return;
            }
            delete ellipse_v[ellipse_v.length()-1];
            ellipse_v.pop_back();
            break;
        default:
            return;
            break;
        }
    }

    void Draw_widget::on_shape_finished(){
        switch (current_shape) {
        case 1:
            draw_rectangle();
            break;
        case 2:
            draw_triangle();
            break;
        case 3:
            draw_ellipse();
            break;
        default:
            return;
            break;
        }
    }




