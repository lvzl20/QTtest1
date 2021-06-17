#include "widget.h"
#include "newwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    newWidget w2;
    w2.show();
    return a.exec();
}
