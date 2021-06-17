#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QHostAddress>

clientWidget::clientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientWidget)
{
    ui->setupUi(this);

    tcpsocket = new QTcpSocket(this);
    isStart = false;

    connect(tcpsocket, &QTcpSocket::readyRead, this, &clientWidget::recvData);
}

clientWidget::~clientWidget()
{
    delete ui;
}

void clientWidget::recvData(){
    // 取出接受的内容
    QByteArray buf = tcpsocket->readAll();

    if(false == isStart){ // 接收头部信息
        isStart = true;
        // 解析头部信息, 初始化 buf = "hello##1024"
        fileName = QString(buf).section("##",0,0); // section 为拆解字符串, 0,0代表获取第0段开始和第0段结束的字符串
        fileSize = QString(buf).section("##",1,1).toInt();
        recvSize = 0;

        // 打开文件
        file.setFileName(fileName);
        bool isOk = file.open(QIODevice::WriteOnly);
        if(false == isOk){
            qDebug() << "写文件失败";
        }
    }
    else{
                qint64 len = file.write(buf);
                recvSize += len;
                if(recvSize == fileSize){ // 接受完成
                    file.close();
                    QMessageBox::information(this, "完成", "接收文件成功");

                    // 关闭连接
                    tcpsocket->disconnectFromHost();
                    tcpsocket->close();

                    isStart = false; // 使后面仍然能打开
                }
     }
}

void clientWidget::on_buttonConnect_clicked()
{
    // 获取服务器IP和端口
    QString ip = ui->lineEditIp->text();
    quint16 port = ui->lineEditPort->text().toInt();
    tcpsocket->connectToHost(QHostAddress(ip), port);
}
