#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    /*
     * 对于主窗口，坐标系统相当于屏幕
     * 原点：相对于屏幕左上角
    */
    resize(400,300);
    move(300,100);
    QPushButton *b1 = new QPushButton(this);
    b1->setText("按钮1");
    b1->resize(100,100);
    QPushButton *b2 = new QPushButton(b1);
    b2->setText(("按钮2"));
    b2->move(10,10);
}

Widget::~Widget()
{
}

