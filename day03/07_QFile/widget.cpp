#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>
#include <QDataStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_buttonRead_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "open", "../",
                                                "TXT(*.txt)");
    if(path.isEmpty() == false){
        // 文件对象
        QFile file(path);

        // 打开文件,只读方式
        bool isOK = file.open(QIODevice::ReadOnly);
        if(isOK == true){
#if 0
            // 一次性读完文件, 默认只识别utf-8编码
            QByteArray array = file.readAll();
            ui->textEdit->setText(QString(array));
#endif
            QByteArray array;
            while(file.atEnd() == false){
                // 读一行
                array += file.readLine();
            }
            ui->textEdit->setText(QString(array));
        }

        // 关闭文件
        file.close();

        // 打印文件信息
        QFileInfo info(path);
        qDebug() << "文件名字" << info.fileName();
        qDebug() << "文件后缀" << info.suffix();
        qDebug() << "文件大小" << info.size();
        qDebug() << "文件创建时间" << info.created().toString("yyyy-MM-dd hh:mm:ss");
    }
}

void Widget::on_buttonWrite_clicked()
{
    QString path = QFileDialog::getSaveFileName(this, "save", "../", "TXT(*.txt)");
    if(path.isEmpty() == false){
        QFile file; // 创建文件对象
        file.setFileName(path);

        // 打开文件,只写方式
        bool isOK = file.open(QIODevice::WriteOnly);
        if(isOK == true){
            // 获取编辑区内容
            QString str = ui->textEdit->toPlainText();
            // 写文件

//             QString -> QByteArray
            file.write(str.toUtf8());

//            // QString -> C++ string -> char*
//            file.write(str.toStdString().data());

//            // 转换为本地编码
//            file.write(str.toLocal8Bit());

            // QByteArray -> char *
            char *b = str.toUtf8().data();
        }

        file.close();
    }
}
