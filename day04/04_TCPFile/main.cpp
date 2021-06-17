#include "serverwidget.h"
#include "clientwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    serverWidget w;
    w.show();
    clientWidget w2;
    w2.show();
    return a.exec();
}
