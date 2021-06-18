#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class TcpClient;
}

class TcpClient : public QWidget
{
    Q_OBJECT

public:
    explicit TcpClient(QWidget *parent = nullptr);
    ~TcpClient();

protected slots:
    // 连接成功
    void slotLinkSuccess();
    // 读取数据
    void slotReadData();
    // 退出成功
    void slotOutSuccess();
private slots:
    // 连接/退出聊天室
    void on_buttonJoin_clicked();
    // 发送数据
    void on_buttonSend_clicked();
private:
    Ui::TcpClient *ui;

    QTcpSocket *clientSocket; // 用户的套接字

    bool status; // 是否加入聊天室
    QString userName;
};

#endif // TCPCLIENT_H
