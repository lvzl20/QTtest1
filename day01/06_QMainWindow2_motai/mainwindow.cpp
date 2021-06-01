#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(700,500);
    setWindowTitle("模态与非模态");
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);
    QMenu *menu = mBar->addMenu("对话框");
    QAction *q1 = menu->addAction("模态对话框");
    connect(q1,&QAction::triggered,this,
            [=](){
                QDialog dig;
                dig.exec();
            });
    QAction *q2 = menu->addAction("非模态对话框");
    connect(q2,&QAction::triggered,this,
            [=](){
                    // 使用局部变量看不到对话框，一瞬间就没了
//                QDialog dig;
//                dig.show();
                    // 使用指针指定父对象为this,这样生命周期会一直存在直到父对象灭亡,但反复进入会反复创建,浪费资源（内存泄漏）
//                QDialog *p = new QDialog(this);
//                p->show();
                    // 可以使用内置方法来释放资源(不指定父对象)，或者将其作为类的成员传进来
                  QDialog *p = new QDialog;
                  p->setAttribute(Qt::WA_DeleteOnClose);
                  p->show();
            });
    QAction *q3 = menu->addAction("关于对话框");
    connect(q3,&QAction::triggered,this,
            [=](){
               QMessageBox::about(this,"about","关于qt");
             });
    QAction *q4 = menu->addAction("问题对话框");
    connect(q4,&QAction::triggered,this,
            [=](){
                int ret = QMessageBox::question(this,"question","Are you ok?",
                                                QMessageBox::Yes | QMessageBox::No);
                                                    // 可以自己指定，具体 可以在QMessageBox按下F1查看enum
                switch(ret){
                    case QMessageBox::Yes:
                        qDebug() << "Yes"; break;
                    case QMessageBox::No:
                        qDebug() << "No"; break;
                    default:
                        break;
                }

             });
    QAction *q5 = menu->addAction("文件对话框");
    connect(q5,&QAction::triggered,this,
            [=](){
              QString path =  QFileDialog::getOpenFileName(
                            this,       // 父对象
                            "open",     // 对话框标题
                            "../",      // 当前目录下
                            "source(*.cpp *.h);;Text(*.txt);;all(*.*)" //根据需要显示需要的文件类型
                            );
              qDebug() << path;

             });
}

MainWindow::~MainWindow()
{
}

