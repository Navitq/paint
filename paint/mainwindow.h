#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include "draw_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void add_rectangle();
    void add_triangle();
    void add_ellipse();
    void add_link();
    void moving_shape();
    void removing_shape();
    void uploading_shape();
    void downloading_shape();

private:
    Ui::MainWindow *ui;
    QVBoxLayout *main_layout;
    QHBoxLayout *draw_layout;
    QHBoxLayout *buttons_layout;
    Draw_widget *canvas;
};


#endif // MAINWINDOW_H
