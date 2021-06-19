#include "logui.h"
#include "ui_logui.h"

LogUi::LogUi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LogUi)
{
    ui->setupUi(this);
    // 初始化系统托盘
    initMyTrayIcon();
    // 托盘信号
    connect(myTrayIcon, &QSystemTrayIcon::activated, this, &LogUi::slotActiveTray);
    // 隐藏系统任务栏
    setWindowFlags(Qt::FramelessWindowHint);
}

LogUi::~LogUi()
{
    delete ui;
}
 // 初始化托盘
void LogUi::initMyTrayIcon(){
    myTrayIcon = new QSystemTrayIcon(this);
    QIcon icon = QIcon(":/Image/red_maste.png");

    // 添加图标
    myTrayIcon->setIcon(icon);

    // 当鼠标悬浮时，显示文字
    myTrayIcon->setToolTip("QQTest");

    // 显示图标
    myTrayIcon->show();
}

 // 点击托盘后执行的槽函数
void LogUi::slotActiveTray(QSystemTrayIcon::ActivationReason reason){
    // 点击托盘显示界面
    if(reason == QSystemTrayIcon::Trigger){
        this->show();
    }

}


// 点击最小化到托盘即隐藏界面
void LogUi::on_buttonHide_clicked()
{
    this->hide();

}

void LogUi::on_buttonClose_clicked()
{
    this->close();
}
