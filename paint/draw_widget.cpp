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
    setFocusPolicy(Qt::StrongFocus);
    setFocus();
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

void Draw_widget::set_action(int x){
    current_action = x;
}

void Draw_widget::removeShape(Shape* shape){
    for(int i = 0; i < rectangle_v.size(); i++){
        if(rectangle_v[i] == shape){
            delete rectangle_v.takeAt(i);
            return;
        }
    }
    for(int i = 0; i < triangle_v.size(); i++){
        if(triangle_v[i] == shape){
            delete triangle_v.takeAt(i);
            return;
        }
    }
    for(int i = 0; i < ellipse_v.size(); i++){
        if(ellipse_v[i] == shape){
            delete ellipse_v.takeAt(i);
            return;
        }
    }
}

void Draw_widget::shape_display(Shape* shape){
    shape->setGeometry(this->rect());
    shape->setParent(this);
    shape->show();
}

QSize Draw_widget::get_size() {
    return this->parentWidget()->parentWidget()->size();
}

void Draw_widget::save_data(){
    QSize size = get_size();
    QString file_name = QUuid::createUuid().toString();
    file_name.append(".txt");
    QFile *file = new QFile(file_name);
    file->open(QIODevice::WriteOnly | QIODevice::Text);

    QString width = QString::number(size.width()).append(";");
    QString height = QString::number(size.height()).append(";\n");

    if(file->isOpen()){
        QTextStream writeStream(file);
        writeStream << width + height;
        writeStream << get_position_list(rectangle_v);
        writeStream << get_position_list(triangle_v);
        writeStream << get_position_list(ellipse_v);
        writeStream << get_position_list(line_v);
        file->close();
    }
}

void Draw_widget::download_data(QString path){
    for(auto shape: rectangle_v){
        removeShape(shape);
    }
    rectangle_v.clear();
    for(auto shape: triangle_v){
        removeShape(shape);
    }
    triangle_v.clear();
    for(auto shape: ellipse_v){
        removeShape(shape);
    }
    ellipse_v.clear();
    for(int i = 0 ;i < line_v.length();i++){
        auto delete_shape = line_v.last();
        line_v.pop_back();
        delete delete_shape.first;
    }
    line_v.clear();
    QList<QWidget*> children = this->findChildren<QWidget*>();
    for (QWidget* child : children) {
        delete child;
    }
    update();

    QFile *file = new QFile(path);
    file->open(QIODevice::ReadOnly | QIODevice::Text);
    QList<QString> container;
    if(file->isOpen()){
        QTextStream writeStream(file);
        while (!file->atEnd()) {
            container.push_back(file->readLine());
        }
    }

    for(int i = 0;i < container.length();++i){
        switch(i)
        {
        case 0:
            set_dimensions(container[0]);
            break;
        case 1:{
            QStringList shape = split_downloaded_string(container[1]);
            if(shape.length()<1){
                continue;
            }
            shape.pop_back();
            for(int i =0;i < shape.length();++i){
                load_rectangel(shape[i]);
            }
            break;
        }
        case 2:{
            QStringList shape = split_downloaded_string(container[2]);
            if(shape.length()<1){
                continue;
            }
            shape.pop_back();
            for(int i =0;i < shape.length();++i){
                load_triangle(shape[i]);
            }
            break;
        }
        case 3:{
            QStringList shape = split_downloaded_string(container[3]);
            if(shape.length()<1){
                continue;
            }
            shape.pop_back();
            for(int i =0;i < shape.length();++i){
                load_ellipse(shape[i]);
            }
            break;
        }
        case 4:{
            QStringList shape = split_downloaded_string(container[4]);
            if(shape.length()<1){
                continue;
            }
            shape.pop_back();
            for(int i =0;i < shape.length();++i){
                load_link(shape[i]);
            }
            break;
        }
        default:
            break;
        }
    }
}

void Draw_widget::load_rectangel(QString shape){
    Rectangle *new_rect = new Rectangle(split_downloaded_string(shape, ','));
    shape_display(new_rect);
    rectangle_v.push_back(new_rect);
}

void Draw_widget::load_triangle(QString shape){
    Triangle *new_trian = new Triangle(split_downloaded_string(shape, ','));
    shape_display(new_trian);
    triangle_v.push_back(new_trian);
}

void Draw_widget::load_ellipse(QString shape){
    Ellipse *new_elipse = new Ellipse(split_downloaded_string(shape, ','));
    shape_display(new_elipse);
    ellipse_v.push_back(new_elipse);
}



void Draw_widget::load_link(QString shape){
    Shape *shape_one;
    Shape *shape_two;

    switch(QString(shape[0]).toInt())
    {
        case 0:
        {
        shape_one = rectangle_v[QString(shape[1]).toInt()];
            break;
        }
        case 1:
        {
            shape_one = triangle_v[QString(shape[1]).toInt()];
            break;
        }
        case 2:
        {
            shape_one = ellipse_v[QString(shape[1]).toInt()];
            break;
        }
        default:
            break;
    }

        switch(QString(shape[2]).toInt())
        {
        case 0:
        {
            shape_two = rectangle_v[QString(shape[3]).toInt()];
            break;
        }
        case 1:
        {
            shape_two = triangle_v[QString(shape[3]).toInt()];
            break;
        }
        case 2:
        {
            shape_two = ellipse_v[QString(shape[3]).toInt()];
            break;
        }
        default:
            break;
        }

    Line* new_line = new Line(shape_one, shape_two);
    new_line->setGeometry(this->rect());
    new_line->setParent(this);
    new_line->show();
    line_v.push_back(std::make_pair(new_line, false));
}

QStringList Draw_widget::split_downloaded_string(QString string, char separator){
    return string.split(separator);
}

void Draw_widget::set_dimensions(QString demension){
    QStringList sizes = split_downloaded_string(demension);
    this->parentWidget()->parentWidget()->resize(sizes[0].toInt(), sizes[1].toInt());
}

QString Draw_widget::get_position_list(QList<Rectangle*> rectangle) {
    QString positions;
    for (auto rect : rectangle) {
        positions += rect->get_position() + ";";
    }
    positions+="\n";
    return positions;
}


QString Draw_widget::get_position_list(QList<Ellipse*> ellipse) {
    QString positions;
    for (auto ell : ellipse) {
        positions += ell->get_position() + ";";
    }
    positions+="\n";
    return positions;
}

QString Draw_widget::get_position_list(QList<Triangle*> triangle) {
    QString positions;
    for (auto trian : triangle) {
        positions += trian->get_position() + ";";
    }
    positions+="\n";
    return positions;
}

QString Draw_widget::get_position_list(QList <std::pair<Line*, bool>> line_v) {
    QString positions;
    for (auto line : line_v) {
        positions += get_line_position(line.first)  + ";";
    }
    return positions;
}

QString Draw_widget::get_line_position(Line* line){
    QString first_class = line->first_shape->metaObject()->className();
    QString second_class = line->second_shape->metaObject()->className();
    QString line_info = "";
    if(first_class == "Rectangle"){
        line_info.append("0");
            for(int i = 0;i < rectangle_v.length();++i){
                if(rectangle_v[i] == line->first_shape){
                    line_info.append(QString::number(i));
                    break;
                }
            }
    } else if(first_class == "Triangle") {
        line_info.append("1");
        for(int i = 0;i < triangle_v.length();++i){
            if(triangle_v[i] == line->first_shape){
                line_info.append(QString::number(i));
                break;
            }
        }
    } else if (first_class == "Ellipse"){
        line_info.append("2");
        for(int i = 0;i < ellipse_v.length();++i){
            if(ellipse_v[i] == line->first_shape){
                line_info.append(QString::number(i));
                break;
            }
        }
    }

    if(second_class == "Rectangle"){
        line_info.append("0");
        for(int i = 0;i < rectangle_v.length();++i){
            if(rectangle_v[i] == line->second_shape){
                line_info.append(QString::number(i));
                break;
            }
        }
    } else if(second_class == "Triangle") {
        line_info.append("1");
        for(int i = 0;i < triangle_v.length();++i){
            if(triangle_v[i] == line->second_shape){
                line_info.append(QString::number(i));
                break;
            }
        }
    } else if (second_class == "Ellipse"){
        line_info.append("2");
        for(int i = 0;i < ellipse_v.length();++i){
            if(ellipse_v[i] == line->second_shape){
                line_info.append(QString::number(i));
                break;
            }
        }
    }
    return line_info;
}


void Draw_widget::draw_rectangle(){
    Rectangle *new_rect = new Rectangle();
    shape_display(new_rect);
    rectangle_v.push_back(new_rect);
}

void Draw_widget::draw_triangle(){
    Triangle *new_triangle = new Triangle();
    shape_display(new_triangle);
    triangle_v.push_back(new_triangle);
}

void Draw_widget::draw_ellipse(){
    Ellipse *new_ellipse = new Ellipse();
    shape_display(new_ellipse);
    ellipse_v.push_back(new_ellipse);
}

void Draw_widget::draw_line(){
    Line* new_line = new Line();
    new_line->setGeometry(this->rect());
    new_line->setParent(this);
    new_line->show();
    line_v.push_back(std::make_pair(new_line, false));
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
    active_shape = nullptr;
    shape_found = false;
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

void Draw_widget::keyPressEvent(QKeyEvent *ev) {
    qDebug("123123");

    if(ev->key() == Qt::Key_Escape && !is_right_clicked && is_active) {
        if(current_action == 0){
                Rectangle* delete_shape = rectangle_v.last();
                rectangle_v.pop_back();
                delete delete_shape;
        }
        else if(current_action == 1){
                Triangle* delete_shape = triangle_v.last();
                triangle_v.pop_back();
                delete delete_shape;
        }
        else if(current_action == 2){
                Ellipse* delete_shape = ellipse_v.last();
                ellipse_v.pop_back();
                delete delete_shape;
        }
        else if(current_action == 3){
                auto delete_shape = line_v.last();
                line_v.pop_back();
                delete delete_shape.first;
        }
        if(current_action != 5 || current_action != 6 || current_action != 7){
            is_right_clicked = true;
        }
        return;
    }
}

void Draw_widget::mousePressEvent(QMouseEvent* ev){
    if(current_action != 5 || current_action != 6 || current_action != 7){
        is_active = true;
    }

    if (ev->button() == Qt::RightButton) {
        if ((ev->buttons() & Qt::LeftButton) && (ev->button() == Qt::RightButton) && !is_right_clicked) {
            if(current_action == 0){
                Rectangle* delete_shape = rectangle_v.last();
                rectangle_v.pop_back();
                delete delete_shape;
            }
            else if(current_action == 1){
                Triangle* delete_shape = triangle_v.last();
                triangle_v.pop_back();
                delete delete_shape;
            }
            else if(current_action == 2){
                Ellipse* delete_shape = ellipse_v.last();
                ellipse_v.pop_back();
                delete delete_shape;
            }
            else if(current_action == 3){
                auto delete_shape = line_v.last();
                line_v.pop_back();
                delete delete_shape.first;
            }

        }
        if(current_action != 5 || current_action != 6 || current_action != 7){
            is_right_clicked = true;
        }
        return;
    }
    if(current_action == 0){
        draw_rectangle();
        rectangle_v.last()->drawPress(ev->pos());
    }
    else if(current_action == 1){
        draw_triangle();
        triangle_v.last()->drawPress(ev->pos());
    }
    else if(current_action == 2){
        draw_ellipse();
        ellipse_v.last()->drawPress(ev->pos());
    }
    else if(current_action == 3){
        find_shape(ev);
        if(shape_found){
            draw_line();
            line_v.last().first->drawPress(active_shape, ev->pos());
        }
    }
    else if(current_action == 4){
        find_shape(ev);
        if(shape_found){
            for(int i = 0; i < line_v.size(); i++){
                if(line_v[i].first->points_to(active_shape)){
                    line_v[i].second = true;
                }
            }
        }
    }
    else if(current_action == 5){
        find_shape(ev);
        if(shape_found){
            if(!line_v.empty()){
                QList<std::pair<Line*, bool>>::Iterator it = line_v.begin();
                while(it != line_v.end()){
                    if(it->first->points_to(active_shape)){
                        it->first->~Line();
                        it = line_v.erase(it);
                    } else {
                        ++it;
                    }
                }
            }
            removeShape(active_shape);
        }
    }
}

void Draw_widget::mouseMoveEvent(QMouseEvent* ev){
    //qDebug() << "mouseMoveEvent";
    if (ev->buttons() & Qt::RightButton || is_right_clicked ) {
        qDebug() << "strange if statement";
        return;
    }
    if(current_action == 0){
        rectangle_v.last()->drawMove(ev->pos());
    }
    else if(current_action == 1){
        triangle_v.last()->drawMove(ev->pos());
    }
    else if(current_action == 2){
        ellipse_v.last()->drawMove(ev->pos());
    }
    else if(current_action == 3){
        qDebug() << "current_action == 3";
        if(shape_found){
            qDebug() << "shape found in current_action == 3";
            line_v.last().first->drawMove(ev->pos());
        }
    }
    else if(current_action == 4){
        if(shape_found){
            active_shape->moveMove(ev->pos());
            for(int i = 0; i < line_v.size(); i++){
                if(line_v[i].second){
                    line_v[i].first->moveMove(active_shape);
                }
            }
        }
    }
}

void Draw_widget::mouseReleaseEvent(QMouseEvent* ev){
    if(current_action != 5 || current_action != 6 || current_action != 7){
        is_active = false;
    }
    if(ev->buttons() == Qt::NoButton && (current_action == 0 || current_action == 1 ||current_action == 2 || current_action == 3 || current_action == 4)) {
        qDebug()<< QString::number(current_action);
        if(is_right_clicked){
            is_right_clicked = false;
            return;
        }
    } else if (is_right_clicked && (current_action == 0 || current_action == 1 ||current_action == 2 || current_action == 3 || current_action == 4)){
        return;
    }

    if(current_action == 0){
        rectangle_v.last()->drawRelease(ev->pos());
    }
    else if(current_action == 1){
        triangle_v.last()->drawRelease(ev->pos());
    }
    else if(current_action == 2){
        ellipse_v.last()->drawRelease(ev->pos());
    }
    else if(current_action == 3){
        // find_shape(ev);
        // if(shape_found){
        //     draw_line();
        //     line_v.last().first->drawPress(active_shape, ev->pos());
        // }
        if(shape_found){
            qDebug() << "if shape found";
            find_shape(ev);
            if(shape_found && active_shape != line_v.last().first->first_shape){
                line_v.last().first->drawRelease(active_shape);
                active_shape = nullptr;
                shape_found = false;
            } else {
                line_v.last().first->~Line();
                line_v.pop_back();
            }
        }
        else{
            qDebug() << "if shape not found";
            find_shape(ev);
            if(shape_found){
                // this->setMouseTracking(true);
                // if(hasMouseTracking()){
                //     qDebug() << "mouse tracking on";
                // }
                draw_line();
                line_v.last().first->drawPress(active_shape, ev->pos());
                line_v.last().first->setMouseTracking(true);
            }
        }
    }
    else if(current_action == 4){
        if(shape_found){
            active_shape->moveRelease(ev->pos());
            shape_found = false;
            for(int i = 0; i < line_v.size(); i++){
                line_v[i].second = false;
            }
        }
    }
}

