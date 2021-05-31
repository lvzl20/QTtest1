#include "newwidget.h"

newWidget::newWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("小弟");
    b.setText("切换到主窗口");
    b.setParent(this);
    b.move(100,100);

    connect(&b, &QPushButton::clicked, this, &newWidget::sendSlot);
}

void newWidget::sendSlot(){
    emit mySignal();
}
