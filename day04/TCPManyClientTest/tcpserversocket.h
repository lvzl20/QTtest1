#ifndef TCPSERVERSOCKET_H
#define TCPSERVERSOCKET_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>


// 用于监听和通讯的服务器类,因为要使用incomingConnection, 所以要继承于QTcpServer,
class TcpServerSocket : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServerSocket(QObject *parent = nullptr);
protected slots:
    // 槽函数
    // 接收客户发来的消息
    void slotReadData();
    // 当有客户点开连接,就从list中移出对应的套接字
    void slotDisconnect();
protected:
    void incomingConnection(qintptr handle) override;

private:
    // 用于存储连接进来的用户套接字
    QList<QTcpSocket *> clientSocketList;
signals:
    // 发出信号给Ui 用于更新界面
    void upDateserver(QString);
};

#endif // TCPSERVERSOCKET_H
