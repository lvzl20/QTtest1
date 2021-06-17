#include "widget.h"
#include "ui_widget.h"
#include <QBuffer>
#include <QDebug>
#include <QDataStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
#if 0
    QBuffer memFile; // 创建内存文件
    memFile.open(QIODevice::WriteOnly);

    memFile.write("123");
    memFile.write("2222");

    memFile.close();
    qDebug() << memFile.buffer();
#endif
    QByteArray array;
    QBuffer memFile(&array);
    memFile.open(QIODevice::WriteOnly);
    memFile.write("123");
    memFile.write("321");

    memFile.close();
    qDebug() << array;

    //................................
    QBuffer mem1;
    mem1.open(QIODevice::WriteOnly);
    QDataStream  stream(&mem1);
    stream << QString("测试") << 250;
    mem1.close();

    qDebug() << mem1.buffer();

    mem1.open(QIODevice::ReadOnly);
    stream.setDevice(&mem1);

    QString str;
    int a;
    stream >> str >> a;

    mem1.close();
    qDebug() << str << a;

}

Widget::~Widget()
{
    delete ui;
}

