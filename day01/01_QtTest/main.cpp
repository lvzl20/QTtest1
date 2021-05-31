#include "widget.h"
// 应用程序类
// qt头文件没有.h，头文件和类名一样，以Q开头，前两个大写
#include <QApplication>

int main(int argc, char *argv[])
{
    // 有且只有一个应用程序类的对象
    QApplication a(argc, argv);
    // Widget 继承于QWidget, QWidget是一个窗口基类,所以Widget也是窗口基类
    Widget w;
    // 窗口创建默认是隐藏，需要人为显示
    w.show();
    // a.exec()让程序一直执行，相当于有个while循环，等待事件的发生
    return a.exec();
}
