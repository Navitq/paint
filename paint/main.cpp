#include "mainwindow.h"

#include <QApplication>
#include <QLabel>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
// QLabel *label = new QLabel("Paint");
// label->resize(500,500);
// label->show();
    return a.exec();
}
