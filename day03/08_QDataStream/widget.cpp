#include "widget.h"
#include "ui_widget.h"
#include <QDataStream>
#include <QTextStream>
#include <QFile>
#include <QDebug>

#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    writeData();
    readData();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::writeData(){
    QFile file("../test.txt");

    bool isOK = file.open(QIODevice::WriteOnly);
    if(isOK == true){
        // 创建数据流,和file文件关联
        // 往数据流中写数据,相当于往文件里写数据
        QDataStream stream(&file);
        stream << QString("这是一个test文件") << 1;
        file.close();
    }
}

void Widget::readData(){
    QFile file("../test.txt");

    bool isOK = file.open(QIODevice::ReadOnly);
    if(isOK == true){
        // 创建数据流,和file文件关联
        // 往数据流中写数据,相当于往文件里写数据
        QDataStream stream(&file);

        // 读的时候按写的顺序取数据
        QString str;
        int a;
        stream >> str >> a;
//        qDebug() << str << a;
        cout << str << a;
        file.close();
    }
}
