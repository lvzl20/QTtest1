#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(700,500);
        // 菜单栏
    QMenuBar *mBar = menuBar();
        // 添加菜单
    QMenu *pFile = mBar->addMenu("文件");
        // 添加菜单项(添加动作)
    QAction *pNew = pFile->addAction("新建");
    connect(pNew,&QAction::triggered,this,
            [=](){
               qDebug() << "新建被按下";
            }
            );
        // 添加分割线
    pFile->addSeparator();
    QAction *pOpen = pFile->addAction("打开");
        // 工具栏(菜单栏下的快捷方式)
    QToolBar *toolBar = addToolBar("toolBar");
        //工具栏添加快捷键
    toolBar->addAction(pNew);
    QPushButton *b = new QPushButton(this);
    b->setText("^_^");
    toolBar->addWidget(b);
    connect(b,&QPushButton::clicked,
            [=](){
                b->setText("123");
            });
        // 状态栏
    QStatusBar *statusBar1 = statusBar();
        // 标签
    QLabel *label = new QLabel(this);
    label->setText("Normal text file");
    statusBar1->addWidget(label);
    statusBar1->addWidget(new QLabel("2",this)); // 标签 从左往右添加
    statusBar1->addPermanentWidget(new QLabel("3",this)); // 标签 从右往左添加
        // 核心控件
    QTextEdit *textedit = new QTextEdit(this);
    setCentralWidget(textedit);
        // 浮动窗口
    QDockWidget *dock = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,dock);
}

MainWindow::~MainWindow()
{
}

