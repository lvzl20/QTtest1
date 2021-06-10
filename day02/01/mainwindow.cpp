#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QCompleter>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString str = ui->lineEdit->text();
    qDebug() << str;
//    ui->button1->setText("MyButton1");
    // 设置字符串提示,本例用于lineEdit中,也就是输入第一个字符为h或H时会提示
    QStringList List;
    List << "Hello" << "How are you";
    QCompleter *com = new QCompleter(List,this);
    // 忽略大小写
    com->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(com);
    ui->label_3->setText("<a href = \"https://www.baidu.com\">点击打开百度");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_change1_clicked()
{
    static int i = 0;
//    i = ++i % 4;
    ui->stackedWidget->setCurrentIndex( ++i % 2);
    i = i % 2;
}

void MainWindow::on_pushButton_3_clicked()
{
    QString s =  ui->lineEdit->text();
    // 该文本框显示lineEdit中的内容
    ui->lineEdit1->setText(s);
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    // 该文本框以密码形式显示
//    ui->lineEdit->setEchoMode(QLineEdit::Password);
}

void MainWindow::on_pushButton_4_clicked()
{
    // 先选择所有再剪切
    ui->lineEdit1->selectAll();
    ui->lineEdit1->cut();
}

void MainWindow::on_lineEdit_2_textEdited(const QString &arg1)
{
    ui->progressBar1->setValue(arg1.toInt());
}
