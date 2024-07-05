#include "draw_widget.h"

Draw_widget::Draw_widget(QWidget *parent)
    : QWidget{parent}
{

    QPalette Pal(palette());

    Pal.setColor(QPalette::Window, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
    this->show();
}

void Draw_widget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QRect rect(10, 10.0, 20.0, 70.0);
    painter.drawRect(rect);
}

void Draw_widget::draw_rectangle(QPaintEvent*){

}
