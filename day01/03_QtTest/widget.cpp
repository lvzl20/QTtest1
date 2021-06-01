#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent),flag(0)
{
    resize(400,300);
    b1.setParent(this);
    b1.setText("关闭­");
    b1.move(50,100);

    b2 = new QPushButton(this);
    b2->setText("显示/隐藏关闭按钮");
    b2->move(150,100);

    connect(&b1, &QPushButton::pressed, this,&Widget::close);
    connect(b2, &QPushButton::released, this, &Widget::mySlot); //


    setWindowTitle("老大");
    b3.setText("跳转到子窗口");
    b3.move(300,100);
    b3.setParent(this);

//    nw.show();
    connect(&b3, &QPushButton::released, this, &Widget::change);

//    void (newWidget::*func1)() = &newWidget::mySignal;
    void (newWidget::*func2)(int,QString) = &newWidget::mySignal;
    connect(&nw, func2, this, &Widget::dealSlot);

    // lambda表达式
    QPushButton *b4 = new QPushButton;
    b4->setParent(this);
    b4->setText(QStringLiteral("Lambda表达式1"));
    int a = 3;
    b4->move(100,200);
    connect(b4,&QPushButton::released,this,
            [=]()mutable {
                a = 4;
                b4->setText("123");
                qDebug() << "123" << a;
            }
            );


}

void Widget::dealSub(){
    this->show();
    nw.hide();
}

void Widget::dealSlot(int a,QString str){
    qDebug() << a << str.toUtf8().data() <<endl;
    this->show();
    nw.hide();
}

void Widget::change(){
    nw.show();
    hide();
}

void Widget::mySlot(){
    if(flag == 0){
        b1.hide();
        flag = 1;
    }else{
        b1.show();
        flag = 0;
    }
}

Widget::~Widget()
{
}

