#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 所有标签的样式
    this->setStyleSheet("QLabel{color:rgb(0,255,255);"
                        "background-color:red"
                         "}");
    // 特定标签的样式
    ui->label->setStyleSheet("QLabel{color:rgb(0,255,255);"
                            "background-color:green;"
                             // "background-image:url(:/Image/10.jpg);" // 背景图片
                             "border-image:url(:/Image/10.jpg);" // 自动适应图片大小(平铺)
                             "}");
    ui->pushButton->setStyleSheet("QPushButton{"
                                  "border-image:url(:/Image/10.jpg);"
                                  "}"
                                  "QPushButton:hover{"
                                  "border-image:url(:/Image/11.jpg);"
                                  "}"
                                  "QPushButton:pressed{"
                                  "border-image:url(:/Image/2.jpg);"
                                  "}"
                                  );
}

MainWindow::~MainWindow()
{
    delete ui;
}

