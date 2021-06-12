#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QBitmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

// QPixmap: 针对屏幕进行优化,和平台相关,不能对图片进行修改
// QImage:  和平台无关，可以对图片进行修改,可以在线程绘图
// QPicture：保存绘图的状态(二进制文件),从另外一个平台或程序读出的一样
// 三者用法几乎相同,前两个保存是图片，第三个是二进制文件

void Widget::paintEvent(QPaintEvent *){
    QPainter p(this);
    p.drawPixmap(0, 0, 100, 100, QPixmap("../Image/27.jpg"));

    p.drawPixmap(0, height()/2, 100, 100, QBitmap("../Image/27.jpg"));

    QPixmap pixmap;
    pixmap.load("../Image/27.jpg");
    p.drawPixmap(200, 0, 100, 100, pixmap);

    QBitmap bitmap;
    bitmap.load("../Image/27.jpg");
    p.drawPixmap(200, height()/2, 100, 100, bitmap);
}

