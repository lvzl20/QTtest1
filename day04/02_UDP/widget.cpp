#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 分配空间
    udpSocket = new QUdpSocket(this);

    // 绑定
    udpSocket->bind(8888);

    setWindowTitle("服务器端口:8888");

    // 当对方成功发送数据过来,自动触发readyRead()
    connect(udpSocket, &QUdpSocket::readyRead, this, &Widget::dealMsg);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::dealMsg(){
    // 读取对方发送的内容
    char buf[1024] = {0};
    QHostAddress peeradd; // 对方地址
    quint16 port; // 对方端口
    qint64 len = udpSocket->readDatagram(buf, sizeof(buf), &peeradd, &port);
    if(len > 0){
        QString str = QString("[%1:%2]: %3").arg(peeradd.toString()).arg(port).arg(buf);
        // 给编辑区设置内容
        ui->textEdit->setText(str);
    }

}



void Widget::on_buttonSend_clicked()
{
    // 先获取对方的IP和端口
    QString ip = ui->lineEditIp->text();
    qint16 port = ui->lineEditPort->text().toInt();

    // 获取编辑区的内容
    QString str = ui->textEdit->toPlainText();

    // 给指定IP和端口发送数据
    udpSocket->writeDatagram(str.toUtf8(), QHostAddress(ip), port);


}
