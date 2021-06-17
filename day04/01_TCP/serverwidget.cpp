#include "serverwidget.h"
#include "ui_serverwidget.h"

ServerWidget::ServerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerWidget)
{
    ui->setupUi(this);

    setWindowTitle("服务器: 8888");

    // 监听套接字 指定父对象, 让其自动回收空间
    tcpServer = new QTcpServer(this);

    tcpSocket = nullptr;
        // QHostAddress::Any 绑定当前网卡的所有地址
    tcpServer->listen(QHostAddress::Any, 8888);

    connect(tcpServer, &QTcpServer::newConnection, this, &ServerWidget::new_connect);

}

ServerWidget::~ServerWidget()
{
    delete ui;
}


void ServerWidget::new_connect(){
    // 取出建立好连接的套接字
    tcpSocket = tcpServer->nextPendingConnection();

    // 获取对方的IP和端口
    QString ip = tcpSocket->peerAddress().toString();
    qint16 port = tcpSocket->peerPort();
    QString temp = QString("[%1:%2]:成功连接").arg(ip).arg(port);
    ui->textEditRead->append(temp);
    // 获取内容
    connect(tcpSocket, &QTcpSocket::readyRead, this,
            [=](){
                    // 从通信套接字中取出内容
                    QByteArray array = tcpSocket->readAll();
                    // 追加数据
                    auto str = QString("[%1:%2]消息: %3").arg(ip).arg(port).arg(array.toStdString().data());
                    ui->textEditRead->append(str);
             });
    // 检测断开连接
   connect(tcpSocket,&QTcpSocket::disconnected, this,
           [=](){
                  auto str = QString("[%1,%2]:断开连接").arg(ip).arg(port);
                  ui->textEditRead->append(str);
            });
}

void ServerWidget::on_buttonSend_clicked()
{
    if(nullptr == tcpSocket)
        return ;
    // 获取编辑区内容
    QString str = ui->textEditWrite->toPlainText();

    // 给对方发送数据, 使用套接字tcpSocket
    tcpSocket->write(str.toUtf8().data());
}

void ServerWidget::on_buttonClose_clicked()
{
    if(nullptr == tcpSocket)
        return;
    // 主动和客户端断开连接
    tcpSocket->disconnectFromHost();
    tcpSocket->close();

    tcpSocket = nullptr;
}
