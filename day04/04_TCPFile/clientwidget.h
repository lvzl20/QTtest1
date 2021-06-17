#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QFile>

namespace Ui {
class clientWidget;
}

class clientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit clientWidget(QWidget *parent = nullptr);
    ~clientWidget();
    void recvData();

private slots:
    void on_buttonConnect_clicked();

private:
    Ui::clientWidget *ui;

    QTcpSocket *tcpsocket; // 通信套接字

    QFile file;
    QString fileName; // 将接受文件名字
    qint64 fileSize; // 将接受文件大小
    qint64 recvSize; // 已经接收文件的大小

    bool isStart; // 是否接受了头部
};

#endif // CLIENTWIDGET_H
