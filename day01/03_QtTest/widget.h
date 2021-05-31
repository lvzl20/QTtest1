#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include "newwidget.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void mySlot();
    void change(); // 父窗口跳到子窗口函数
    void dealSub(); // 子窗口跳到父窗口函数
private:
    QPushButton b1;
    QPushButton *b2;
    QPushButton b3;
    newWidget nw;
};
#endif // WIDGET_H
