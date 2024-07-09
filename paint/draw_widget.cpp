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

}
    void Draw_widget::resizeEvent(QResizeEvent *event) {
        QWidget::resizeEvent(event);
        for (auto *rect : rectangle_v) {
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
        current_action = 1;
        Rectangle *new_rect = new Rectangle();
        shape_display(new_rect);
        rectangle_v.push_back(new_rect);
    }

    void Draw_widget::draw_triangle(){
        current_action = 2;
        Triangle *new_triangle = new Triangle();
        shape_display(new_triangle);
        triangle_v.push_back(new_triangle);
    }

    void Draw_widget::draw_ellipse(){
        current_action = 3;
        Ellipse *new_ellipse = new Ellipse();
        shape_display(new_ellipse);
        ellipse_v.push_back(new_ellipse);
    }

    void Draw_widget::shape_display(Shape* shape){
        shape->setGeometry(this->rect());
        shape->setParent(this);
        shape->show();
        connect(shape, shape->shape_finished, this, on_shape_finished);
    }

    bool Draw_widget::check_shape(Shape* shape, QMouseEvent* ev){
        if(shape->point_inside_shape(ev->pos())){
            active_shape = shape;
            active_shape->movePress(ev->pos());
            shape_found = true;
            return true;
        }
        return false;
    }

    void Draw_widget::find_shape(QMouseEvent* ev){
        for (Rectangle* shape:rectangle_v){
            if(check_shape(shape, ev)){
                return;
            }
        }
        for (Triangle* shape:triangle_v){
            if(check_shape(shape, ev)){
                return;
            }
        }
        for (Ellipse* shape:ellipse_v){
            if(check_shape(shape, ev)){
                return;
            }
        }
    }

    void Draw_widget::mousePressEvent(QMouseEvent* ev){
        if(current_action == 0){
            if(!shape_found){
                find_shape(ev);
            } else {
                active_shape->movePress(ev->pos());
            }
        }
        else if(current_action == 1){
            rectangle_v.last()->drawPress(ev->pos());
        }
        else if(current_action == 2){
            triangle_v.last()->drawPress(ev->pos());
        }
        else if(current_action == 3){
            ellipse_v.last()->drawPress(ev->pos());
        }
    }

    void Draw_widget::mouseMoveEvent(QMouseEvent* ev){
        if(current_action == 0){
            if(shape_found){
                active_shape->moveMove(ev->pos());
            }
        }
        else if(current_action == 1){
            rectangle_v.last()->drawMove(ev->pos());
        }
        else if(current_action == 2){
            triangle_v.last()->drawMove(ev->pos());
        }
        else if(current_action == 3){
            ellipse_v.last()->drawMove(ev->pos());
        }
    }

    void Draw_widget::mouseReleaseEvent(QMouseEvent* ev){
        if(current_action == 0){
            if(shape_found){
                active_shape->moveRelease(ev->pos());
                shape_found = false;
            }
        }
        else if(current_action == 1){
            rectangle_v.last()->drawRelease(ev->pos());
        }
        else if(current_action == 2){
            triangle_v.last()->drawRelease(ev->pos());
        }
        else if(current_action == 3){
            ellipse_v.last()->drawRelease(ev->pos());
        }
    }

    void Draw_widget::shape_moving(){
        delete_shape();
        current_action = 0;
    }

    void Draw_widget::delete_shape(){
        switch (current_action) {
        case 1:
            if(rectangle_v.length() < 1){
                return;
            }
            delete rectangle_v[rectangle_v.length()-1];
            rectangle_v.pop_back();
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
        switch (current_action) {
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




