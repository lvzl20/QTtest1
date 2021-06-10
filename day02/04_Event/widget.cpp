#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QKeyEvent>
#include <QTimerEvent>
#include <QCloseEvent>
#include <QMessageBox>
#include <QEvent>
#include <QMouseEvent>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 启动定时器
    // timerID 为 定时器id
    timerID = this->startTimer(1000); // ms为单位

    connect(ui->pushButton,&MyButton::clicked,this,
            [=](){
                qDebug() << "按钮被按下";
            });
    // 安装过滤器
    ui->label_2->installEventFilter(this);
    ui->label_2->setMouseTracking(tr);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *e){

    qDebug() << e->key();
}

void Widget::timerEvent(QTimerEvent *e){
    // 使用if语句可以判断多个定时器事件,处理对应的事件
    if(e->timerId() == this->timerID){
        static int sec = 0;
        sec++;
        auto timetext = QString("<center><h1>time:%1</h1></center>").arg(sec);
        ui->label->setText(timetext);
        // 5s后停止定时器
        if(sec == 5){
            this->killTimer(this->timerID);
        }
    }
}

void Widget::closeEvent(QCloseEvent *e){
   int ret = QMessageBox::question(this,"question","是否需要关闭窗口");
   if(ret == QMessageBox::Yes){
       // 关闭窗口,处理关闭窗口事件
       e->accept();
   }else{
       // 不关闭 忽略
       e->ignore();
   }
}

bool Widget::event(QEvent *e){
    // 事件分发
    switch (e->type()) {
        case QEvent::Close:
//            return true; 如果 加上了return true 那么该事件就会停止传播
            closeEvent(static_cast<QCloseEvent*>(e));
            return true;
        break;
    case QEvent::MouseMove:
        mouseMoveEvent(static_cast<QMouseEvent*>(e));
        break;
    case QEvent::KeyPress:
        auto env = static_cast<QKeyEvent*>(e);
        qDebug() << env->key();
        break;
//        keyPressEvent();
    }
     // 按原来的事件传播r
    return QWidget::event(e);
}

bool Widget::eventFilter(QObject *obj, QEvent *e){
    if(obj == ui->label_2){
        // 判断事件
        auto mouseMoveE = static_cast<QMouseEvent*>(e);
        if(e->type() == QEvent::MouseMove){
           ui->label_2->setText(QString("Mouse move:(%1,%2)").arg(mouseMoveE->x()).arg(mouseMoveE->y()));
           return true;
        }
    }
    return QWidget::eventFilter(obj,e);
}
