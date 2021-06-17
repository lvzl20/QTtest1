#include "newwidget.h"
#include "ui_newwidget.h"
#include <QHostAddress>
newWidget::newWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newWidget)
{
    ui->setupUi(this);

    udpSocket = new QUdpSocket(this);

    udpSocket->bind(8000);

    setWindowTitle("端口地址为:8000");
    connect(udpSocket, &QUdpSocket::readyRead, this, &newWidget::dealMsg);
}

newWidget::~newWidget()
{
    delete ui;
}

void newWidget::dealMsg(){
    char buf[1024] = {0};
    QHostAddress ip; // 对方的IP
    quint16 port; // 对方的地址
    qint64 len = udpSocket->readDatagram(buf, sizeof(buf), &ip, &port);
    if(len > 0){
        QString str = QString("[%1:%2]: %3").arg(ip.toString()).arg(port).arg(buf);
        ui->textEdit->setText(str);
    }
}
