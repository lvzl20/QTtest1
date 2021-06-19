#include "serverui.h"
#include "tcpclient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    serverUi w;
    w.show();
//    TcpClient w2;
//    w2.show();
    return a.exec();
}
