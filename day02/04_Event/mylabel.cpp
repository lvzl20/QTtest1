#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>
MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

}

void MyLabel::mouseMoveEvent(QMouseEvent *ev){
//    qDebug() << ev->x() << "  " << ev->y();
}

void MyLabel::mousePressEvent(QMouseEvent *ev){
    int i = ev->x();
    int j = ev->y();
    QString text = QString("<center><h1>mouse: pressed: pos(%1,%2)</h1></center>")
            .arg(i).arg(j);
    this->setText(text);
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev){
//    qDebug() << ev->x() << "  " << ev->y();
}

void MyLabel::enterEvent(QEvent *e){
    QString text = QString("<center><h1>mouse: enter</h1></center>");
    this->setText(text);
}
void MyLabel::leaveEvent(QEvent *e){
    QString text = QString("<center><h1>mouse: leave</h1></center>");
    this->setText(text);
}
