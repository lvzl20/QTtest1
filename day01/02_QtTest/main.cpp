#include <QApplication>
#include <QWidget>
#include<QPushButton>
int main(int argc, char **argv){
    QApplication app(argc,argv);
    QWidget w;
    QPushButton b;
    w.setWindowTitle(QString("Hello QT!")); //设置标题
    b.setText("按钮1"); // 设置按钮 如果不指定父对象，对象和对象没有关系，独立。如果想b放在w上面，就需要w为b的父对象
                        // 指定父对象 1.setParent() 2. 通过构造函数传参
                        // 只需要父对象显示
    b.setParent(&w); // 通过函数指定父对象
    b.move(100,100); //移动坐标，以窗口左上角为起点，像素为单位
    QPushButton b1(&w);
    b1.setText("按钮2"); // 通过构造函数指定父对象
    b1.move(200,100);
    w.show();
    return app.exec();
}
