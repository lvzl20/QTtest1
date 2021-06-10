#include "mybutton.h"
#include <QMouseEvent>
#include <QDebug>
MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

}
void MyButton::mousePressEvent(QMouseEvent *e){
    // 按下左键
    if(e->button() == Qt::RightButton){
        qDebug() << "按下的是右键";
        // ignore()后事件传递给父组件而不是父类
//        e->ignore();
    }
            //    // 否则忽略，接受下一个
            //    else{
            //        QPushButton::mousePressEvent(e);
            //    }
    QPushButton::mousePressEvent(e);
}
