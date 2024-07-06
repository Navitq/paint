#include "draw_widget.h"
#include <QMessageBox>

Draw_widget::Draw_widget(QWidget *parent)
    : QWidget{parent}
{
    QHBoxLayout *draw_canvas = new QHBoxLayout();

    this->setLayout(draw_canvas);

    QWidget *appWidget = new QWidget();
    QPalette Pal(palette());
    Pal.setColor(QPalette::Window, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
    this->show();

    QList <Rectangle*> rectangel_v;
    QList <Ellipse*> ellipse_v;
    QList <Triangle*> triangle_v;
}

    void Draw_widget::draw_rectangle(){
        Rectangle *new_rect = new Rectangle();
        this->layout()->addWidget(new_rect);
        rectangel_v.push_back(new_rect);
    }

    void Draw_widget::draw_ellipse(){
        Ellipse *new_ellipse = new Ellipse();
        this->layout()->addWidget(new_ellipse);
        ellipse_v.push_back(new_ellipse);
    }

    void Draw_widget::draw_triangle(){
        Triangle *new_triangle = new Triangle();
        this->layout()->addWidget(new_triangle);
        triangle_v.push_back(new_triangle);
    }

