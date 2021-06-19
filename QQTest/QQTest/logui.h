#ifndef LOGUI_H
#define LOGUI_H

#include <QWidget>
#include <QSystemTrayIcon> // 系统托盘

QT_BEGIN_NAMESPACE
namespace Ui { class LogUi; }
QT_END_NAMESPACE

class LogUi : public QWidget
{
    Q_OBJECT

public:
    LogUi(QWidget *parent = nullptr);
    ~LogUi();

    void initMyTrayIcon(); // 初始化系统托盘
protected slots:

    void slotActiveTray(QSystemTrayIcon::ActivationReason ); // 激活托盘执行操作
private slots:

    void on_buttonHide_clicked(); // 最小化至托盘

    void on_buttonClose_clicked();

private:
    Ui::LogUi *ui;
    QSystemTrayIcon *myTrayIcon; // 托盘

};
#endif // LOGUI_H
