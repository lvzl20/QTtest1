#ifndef NEWWIDGET_H
#define NEWWIDGET_H

#include <QWidget>
#include <QPushButton>

class newWidget : public QWidget
{
    Q_OBJECT
public:
    explicit newWidget(QWidget *parent = nullptr);

private:
    QPushButton b;
public slots:
    void sendSlot();
signals:
//    信号必须有signals关键字申明
//    信号没有返回值，但可以有参数
//    信号接收函数的声明，无需定义
//      使用的时候: emit mySignal();
//     信号可以重载
   // 一个信号可以连接多个槽函数，槽函数的执行顺序是随机的，不能控制
    // 一个槽函数可以被多个信号连接
    // 信号槽连接成功后，可以断开连接disconnect
    // 槽函数可以是lambda表达式
    void mySignal();
    void mySignal(int,QString); // 带参信号
};

#endif // NEWWIDGET_H
