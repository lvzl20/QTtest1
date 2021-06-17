#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    myTimer = new QTimer(this);
    myTimerCount = 0;

    connect(myTimer, &QTimer::timeout, this,
            [=](){
            ++myTimerCount;
            ui->lcdNumber->display(myTimerCount);
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_buttonStart_clicked()
{
    if(myTimer->isActive()) // 如果定时器在活动,直接返回
        return ;
    myTimer->start(100);
}

void Widget::on_buttonStop_clicked()
{
    myTimer->stop();
}
