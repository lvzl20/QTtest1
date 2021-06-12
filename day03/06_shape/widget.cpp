#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QMouseEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 去窗口边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    // 把窗口背景设置为透明,需要和Qt::FramelessWindowHint配合使用
    setAttribute(Qt::WA_TranslucentBackground);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *){
    QPainter p(this);
    p.drawPixmap(0, 0, QPixmap("../Image/3.jpg"));
}


void Widget::mousePressEvent(QMouseEvent *e){
    if(e->button() == Qt::RightButton){
        // 右键关闭窗口
        this->close();
    }
    else if(e->button() == Qt::LeftButton){
        // 求坐标差值
        // 当前点击坐标 - 窗口左上角坐标
        point = e->globalPos() - this->frameGeometry().topLeft();
        e->accept();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *e){
    if(e->buttons() & Qt::LeftButton){
        move(e->globalPos() - point);
        e->accept();
    }
}
