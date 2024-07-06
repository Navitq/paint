#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QHBoxLayout *buttons_layout = new QHBoxLayout();
    QHBoxLayout *draw_layout = new QHBoxLayout();
    QVBoxLayout *main_layout = new QVBoxLayout();

    canvas = new Draw_widget();


    main_layout->addLayout(buttons_layout, 0);
    main_layout->addLayout(draw_layout, 1);

    draw_layout->addWidget(canvas, 0);


    QPushButton *rectangle = new QPushButton("Прямоугольник");
    connect(rectangle, SIGNAL(clicked()), this, SLOT(add_rectangle()));

    QPushButton *triangle = new QPushButton("Треугольник");
    connect(triangle, SIGNAL(clicked()), this, SLOT(add_triangle()));

    QPushButton *ellipse = new QPushButton("Эллипис");
    connect(ellipse, SIGNAL(clicked()), this, SLOT(add_ellipse()));

    QPushButton *shapes_link = new QPushButton("Связь");
    connect(shapes_link, SIGNAL(clicked()), this, SLOT(add_link()));


    QPushButton *move_shape = new QPushButton("Переместить");
    connect(move_shape, SIGNAL(clicked()), this, SLOT(moving_shape()));

    QPushButton *remove_shape = new QPushButton("Удалить");
    connect(remove_shape, SIGNAL(clicked()), this, SLOT(removing_shape()));


    QPushButton *upload_pic = new QPushButton("Загрузить");
    connect(upload_pic, SIGNAL(clicked()), this, SLOT(uploading_shape()));

    QPushButton *download_pic = new QPushButton("Сохранить");
    connect(download_pic, SIGNAL(clicked()), this, SLOT(downloading_shape()));




    buttons_layout->addWidget(rectangle, 0);
    buttons_layout->addWidget(triangle, 1);
    buttons_layout->addWidget(ellipse, 2);

    buttons_layout->addWidget(shapes_link, 3);

    buttons_layout->addWidget(move_shape, 4);
    buttons_layout->addWidget(remove_shape, 5);

    buttons_layout->addWidget(upload_pic, 6);
    buttons_layout->addWidget(download_pic, 7);

    QWidget *appWidget = new QWidget();

    appWidget->setLayout(main_layout);
    setCentralWidget(appWidget);
}

void MainWindow::add_rectangle(){
    canvas->draw_rectangle();
}

void MainWindow::add_triangle(){
    canvas->draw_triangle();
}

void MainWindow::add_ellipse(){
    canvas->draw_ellipse();
}

void MainWindow::add_link(){
    qDebug()<<"3";
}

void MainWindow::moving_shape(){
    qDebug()<<"4";
}

void MainWindow::removing_shape(){
    qDebug()<<"5";
}

void MainWindow::uploading_shape(){
    qDebug()<<"6";
}

void MainWindow::downloading_shape(){
    qDebug()<<"7";
}

MainWindow::~MainWindow(){
    delete ui;
}
