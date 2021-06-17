#include "serverwidget.h"
#include "ui_serverwidget.h"
#include <QFileDialog>
#include <QDebug>
#include <QFileInfo>

serverWidget::serverWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::serverWidget)
{
    ui->setupUi(this);

    // 监听套接字
    tcpserver = new QTcpServer(this);
    tcpserver->listen(QHostAddress::Any, 8888);

    setWindowTitle("服务器端口:8888");

    // 没有连接客户端时, 两个按钮都不能按
    ui->buttonSelect->setEnabled(false);
    ui->buttonSend->setEnabled(false);

    // 如果客户端和服务器成功连接
    connect(tcpserver, &QTcpServer::newConnection, this, &serverWidget::newConnect);

    connect(&myTimer, &QTimer::timeout, this,
            [=](){
                 // 关闭定时器
                 myTimer.stop();

                 // 发送数据
                 sendData();
            });
}

serverWidget::~serverWidget()
{
    delete ui;
}


void serverWidget::newConnect(){
    // 取出建立好连接的套接字
    tcpsocket = tcpserver->nextPendingConnection();

    // 获取对方的IP和端口
    QString ip = tcpsocket->peerAddress().toString();
    quint16 port = tcpsocket->peerPort();

    // 显示连接成功在屏幕
    QString str = QString("[%1:%2]: 成功连接").arg(ip).arg(port);
    ui->textEdit->setText(str);

    // 成功连接, 可以选择文件
    ui->buttonSelect->setEnabled(true);
}

// 选择文件
void serverWidget::on_buttonSelect_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "open", "../");
    if(false == path.isEmpty()){ // 如果选择文件路径有效
        fileName.clear();
        fileSize = 0;
        sendSize = 0;
        // 获取文件信息
        QFileInfo info(path);
        fileName = info.fileName();
        fileSize = info.size();

        // 只读方式打开文件
        file.setFileName(path);
        bool isOk = file.open(QIODevice::ReadOnly);

        if(true == isOk){
            ui->buttonSelect->setEnabled(false);
            ui->buttonSend->setEnabled(true);
            ui->textEdit->append(QString("[选择的文件路径]: %1").arg(path));
        }else{
            qDebug() << "打开文件失败";
        }

    }else{
        qDebug() << "选择文件路径出错";
    }
}

void serverWidget::on_buttonSend_clicked()
{
    // 先发送文件头信息, 文件名##文件大小
    QString head = QString("%1##%2").arg(fileName).arg(fileSize);
    int len = tcpsocket->write(head.toUtf8());

    if(len > 0 ){ // 头部信息发送成功
        // 发送文件真正的信息
        // 防止TCP粘包问题, 需要定时器延时20ms
        myTimer.start(20);

    }else{
        qDebug() << "头部信息发送失败";
        file.close();
        ui->buttonSend->setEnabled(true);
        ui->buttonSelect->setEnabled(false);
    }

}

void serverWidget::sendData(){
    qint64 len = 0;
    do{
        // 每次发送数据的大小
        char buf[4*1024] = {0};
        len = 0;

        // 从文件中读数据
        len = file.read(buf, sizeof(buf));
        // 发送数据,读多少,发多少
        len = tcpsocket->write(buf, len);

        // 发送数据的累计
        sendSize += len;

    }while(len > 0); // 直到发送数据长度不大于0就结束

    // 是否发送文件完毕
    if(sendSize == fileSize){
        ui->textEdit->append("文件发送完毕");
        file.close();

        // 把客户端断开
        tcpsocket->disconnectFromHost();
        tcpsocket->close();
        ui->buttonSend->setEnabled(false);
    }
}
