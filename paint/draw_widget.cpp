#include "draw_widget.h"
#include <QMessageBox>

Draw_widget::Draw_widget(QWidget *parent)
    : QWidget{parent}
{
    // first.setX(0);
    // first.setY(0);
    // second.setX(0);
    // second.setY(0);
    QHBoxLayout *draw_canvas = new QHBoxLayout();

    this->setLayout(draw_canvas);

    QWidget *appWidget = new QWidget();
    QPalette Pal(palette());
    Pal.setColor(QPalette::Window, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
    this->show();
    QList <Rectangle*> rectangel_v;


}

// void Draw_widget::mousePressEvent(QMouseEvent * ev) {
//     first = ev->pos();
// }

// void Draw_widget::mouseMoveEvent(QMouseEvent * ev) {
//     second = ev->pos();
//     update();
// }

// void Draw_widget::paintEvent(QPaintEvent*)
// {
//     QPainter painter(this);
//     painter.setPen(QPen(Qt::black, 3));
//     QRect rect(first.x(), first.y(), second.x()-first.x(), second.y()-first.y());
//     painter.drawRect(rect);
// }

    void Draw_widget::draw_rectangle(){
        Rectangle *new_rect = new Rectangle();


        this->layout()->addWidget(new_rect);




        rectangel_v.push_back(new_rect);
    }


