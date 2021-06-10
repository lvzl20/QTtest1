#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    // 键盘按下事件
    void keyPressEvent(QKeyEvent *event) override;
    // 定时器事件
    void timerEvent(QTimerEvent *e) override;
    // 关闭事件
    void closeEvent(QCloseEvent *event) override;

    //重写事件
    bool event(QEvent *event) override;
    // 重写事件过滤器
    bool eventFilter(QObject *,QEvent *) override;
private:
    Ui::Widget *ui;
    int timerID;
};
#endif // WIDGET_H
