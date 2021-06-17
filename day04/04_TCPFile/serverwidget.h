#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class serverWidget; }
QT_END_NAMESPACE

class serverWidget : public QWidget
{
    Q_OBJECT

public:
    serverWidget(QWidget *parent = nullptr);
    ~serverWidget();

    void newConnect(); // 建立连接
    void sendData(); // 发送数据

private slots:
    void on_buttonSelect_clicked();

    void on_buttonSend_clicked();

private:
    Ui::serverWidget *ui;

    QTcpServer *tcpserver; // 监听套接字
    QTcpSocket *tcpsocket; // 通信套接字

    QFile file;
    QString fileName; // 将发送文件名字
    qint64 fileSize; // 将发送文件大小
    qint64 sendSize; // 已经发送文件的大小
    QTimer myTimer;
};
#endif // SERVERWIDGET_H
