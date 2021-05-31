#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(400,300); // 设置窗口大小
    b1.setParent(this);
    b1.setText("关闭");
    b1.move(100,100);

    b2 = new QPushButton(this);
    b2->setText("按钮2");
    b2->move(200,100);

    connect(&b1, &QPushButton::pressed, this,&Widget::close); // 关闭窗口
    /* &b1：信号发送者, 指针类型
     * &QPushButton::pressed：处理的信号, <&发送者的名字::信号名字>
     * this 信号接收者
     * &Widget::close: 槽函数，信号处理函数 <&接收的类名::槽函数名字>
     *
    */

    /* 自定义槽
     * Qt5: 任意的成员函数，普通全局函数，静态函数
     * 槽函数需要和信号一致（参数，返回值）
     * 由于信号没有返回值，所以槽函数一定没有返回值
    */
    connect(b2, &QPushButton::released, this, &Widget::mySlot); //
    setWindowTitle("老大"); // 等价于this->setwindowtitle;
    b3.setText("切换到子窗口");
    b3.move(300,100);
    b3.setParent(this);

//    nw.show();
    connect(&b3, &QPushButton::released, this, &Widget::change);
    // 处理子窗口的信号
    connect(&nw, &newWidget::mySignal, this, &Widget::dealSub);

}

void Widget::dealSub(){
    // 父窗口显示
    this->show();
    // 子窗口隐藏
    nw.hide();
}

void Widget::change(){
    // 子窗口显示
    nw.show();
    // 本窗口隐藏
    hide(); // 或this->hide();
}

void Widget::mySlot(){
    b2->setText("123");
}

Widget::~Widget()
{
}

