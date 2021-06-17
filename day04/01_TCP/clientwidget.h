#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class ClientWidget;
}

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWidget(QWidget *parent = nullptr);
    ~ClientWidget();

private slots:
    void on_buttonConnect_clicked();

    void on_buttonSend_clicked();

    void on_buttonDisconnect_clicked();

private:
    Ui::ClientWidget *ui;

    // 通信套接字
    QTcpSocket *tcpSocket;
};

#endif // CLIENTWIDGET_H
