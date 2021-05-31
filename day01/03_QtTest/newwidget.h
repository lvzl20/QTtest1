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
//    信号必须由signals关键字申明
//    信号没有返回值，但可以有参数
//    信号接收函数的声明，无需定义
    void mySignal();
};

#endif // NEWWIDGET_H
