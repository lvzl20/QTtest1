#ifndef SERVERUI_H
#define SERVERUI_H

#include <QWidget>
#include <tcpserversocket.h>

// 用于展示服务器内容的Ui
QT_BEGIN_NAMESPACE
namespace Ui { class serverUi; }
QT_END_NAMESPACE

class serverUi : public QWidget
{
    Q_OBJECT

public:
    serverUi(QWidget *parent = nullptr);
    ~serverUi();

private:
    Ui::serverUi *ui;
    TcpServerSocket *server;
};
#endif // SERVERUI_H
