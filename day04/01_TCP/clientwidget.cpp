#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QHostAddress>

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);


    // 分配空间指定父对象
    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket, &QTcpSocket::connected, this,
            [=](){
                ui->textEditRead->append("[系统消息]: 成功和服务器建立连接");
            });
    //  接受数据
    connect(tcpSocket, &QTcpSocket::readyRead, this,
            [=](){
                 // 获取对方发送的内容
                 QByteArray array = tcpSocket->readAll();
                 // 追加到编辑区中
                 auto str = QString("[服务器消息]: %1").arg(array.toStdString().data());
                 ui->textEditRead->append(str);
            });
    connect(tcpSocket, &QTcpSocket::disconnected, this,
            [=](){
                    ui->textEditRead->append("[系统消息]: 与服务器断开连接");
            });
}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_buttonConnect_clicked()
{
    // 获取服务器IP和端口
    QString ip = ui->lineEditIp->text();
    qint16 port = ui->lineEditPort->text().toInt();

    // 主动和服务器建立连接
    tcpSocket->connectToHost(QHostAddress(ip),port);

}

void ClientWidget::on_buttonSend_clicked()
{
    // 获取编辑区内容
    QString str = ui->textEditWrite->toPlainText();
    // 发送数据
    tcpSocket->write(str.toUtf8().data());

}

void ClientWidget::on_buttonDisconnect_clicked()
{
    // 主动和对方断开连接
    tcpSocket->disconnectFromHost();
    tcpSocket->close();

}
