#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMovie>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    // 清除所有信息
    void Clear_all();
    // 猜测成功
    void Guess_win();
    // 时间结束
    void Time_end();
protected:
    void timerEvent(QTimerEvent *);
private slots:
    void on_pushButton_end_clicked();

    void on_pushButton_start_clicked();


    void on_pushButton_back_clicked();

    void on_pushButton_numDelete_clicked();

    void on_pushButton_numComplete_clicked();

    void on_pushButton_numTip_clicked();

private:
    Ui::Widget *ui;
    // 猜测数字时间
    int timer_guessId;
    int timer_guess;
    // 成功加载动画时间
    int timer_win;
    int timer_winId;
    // 失败加载动画时间
    int timer_endId;
    int timer_end;
    // 猜测时间时的标志，如果为1则下次不进入timer_guessId
    int guess_flag;
    // 记录猜测的数字
    QString guessNum;
    // 产生随机数
    int randGuessNum;

    QMessageBox *msg;
//    QMessageBox *msg;
    QMovie *movie;
};
#endif // WIDGET_H
