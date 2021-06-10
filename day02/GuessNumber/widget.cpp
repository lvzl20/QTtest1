#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>
#include <QTimerEvent>
#include <QTime>
#include <QMovie>
#include <memory.h>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    ui->label_title->setText(QString("<center><h1>猜数字游戏</h1></center>"));
    this->setWindowTitle(QString(" "));
    auto func0 = [this](){
       if(guessNum.length() != 0)
           guessNum += "0";
       ui->lineEdit_inputNum->setText(this->guessNum);
    };
    // 输入数字按钮
    connect(ui->pushButton_num0,&QPushButton::clicked,this, func0);
    connect(ui->pushButton_num1,&QPushButton::clicked,this, [this](){if(this->guessNum.length() < 5) this->guessNum += "1";ui->lineEdit_inputNum->setText(this->guessNum);});
    connect(ui->pushButton_num2,&QPushButton::clicked,this, [this](){if(this->guessNum.length() < 5) this->guessNum += "2";ui->lineEdit_inputNum->setText(this->guessNum);});
    connect(ui->pushButton_num3,&QPushButton::clicked,this, [this](){if(this->guessNum.length() < 5) this->guessNum += "3";ui->lineEdit_inputNum->setText(this->guessNum);});
    connect(ui->pushButton_num4,&QPushButton::clicked,this, [this](){if(this->guessNum.length() < 5) this->guessNum += "4";ui->lineEdit_inputNum->setText(this->guessNum);});
    connect(ui->pushButton_num5,&QPushButton::clicked,this, [this](){if(this->guessNum.length() < 5) this->guessNum += "5";ui->lineEdit_inputNum->setText(this->guessNum);});
    connect(ui->pushButton_num6,&QPushButton::clicked,this, [this](){if(this->guessNum.length() < 5) this->guessNum += "6";ui->lineEdit_inputNum->setText(this->guessNum);});
    connect(ui->pushButton_num7,&QPushButton::clicked,this, [this](){if(this->guessNum.length() < 5) this->guessNum += "7";ui->lineEdit_inputNum->setText(this->guessNum);});
    connect(ui->pushButton_num8,&QPushButton::clicked,this, [this](){if(this->guessNum.length() < 5) this->guessNum += "8";ui->lineEdit_inputNum->setText(this->guessNum);});
    connect(ui->pushButton_num9,&QPushButton::clicked,this, [this](){if(this->guessNum.length() < 5) this->guessNum += "9";ui->lineEdit_inputNum->setText(this->guessNum);});
}

Widget::~Widget()
{
    delete ui;
}

void Widget::Clear_all(){
//    killTimer(timer_endId);
    killTimer(timer_guessId);
//    killTimer(timer_winId);
    msg = nullptr;
    timer_win = 0;
    timer_end = 0;
    timer_guess = 0;
    guess_flag = 0;
    guessNum = "";
    ui->comboBox->setCurrentIndex(0);
    ui->lineEdit_inputNum->clear();
}

void Widget::Guess_win(){
    movie = new QMovie(this);
    movie->setFileName(QString(":/GuessNumImage/win.gif"));
    ui->label_win->setMovie(movie);
    this->timer_winId = this->startTimer(1000);
    this->timer_win = 0;
    movie->start();
    ui->stackedWidget->setCurrentIndex(2);
}

void Widget::Time_end(){
    movie = new QMovie(this);
    movie->setFileName(QString(":/GuessNumImage/fail.gif"));
    ui->label_end->setMovie(movie);
    this->timer_endId = this->startTimer(1000);
    this->timer_end = 0;
    movie->start();
    ui->stackedWidget->setCurrentIndex(3);
}

void Widget::timerEvent(QTimerEvent *e){
    if(e->timerId() == timer_guessId && this->guess_flag != 1){
        int i = ui->progressBar->value();
         // 如果猜测时间已完
        if(i == timer_guess){
//            killTimer(timer_guessId);
             // 如果有弹窗(QMessageBox)，回收
            if(msg != nullptr){
                msg->close();
            }
            this->guess_flag = 1;
            this->Time_end();
        }
        else{
            ui->progressBar->setValue(i+1);
        }
    }
    if(e->timerId() == timer_endId){
         int i = ++timer_end;
         if(i == 5){
            killTimer(timer_endId);
            movie->stop();
            this->Clear_all();
            ui->stackedWidget->setCurrentIndex(0);
         }
    }
    if(e->timerId() == timer_winId){
        int i = ++timer_win;
        if(i == 5){
            killTimer(timer_winId);
            movie->stop();
            this->Clear_all();
            ui->stackedWidget->setCurrentIndex(0);
        }
    }
}

void Widget::on_pushButton_end_clicked()
{
    this->close();
}

void Widget::on_pushButton_start_clicked()
{
    msg = nullptr;
    this->guess_flag = 0;
    // 进入游戏页面
    ui->stackedWidget->setCurrentIndex(1);
    // 初始化猜测时间id
    timer_guessId = this->startTimer(1000);
    // 初始化猜测时间
    switch(ui->comboBox->currentIndex()){
        case 0:
            timer_guess = 20;
        break;
    case 1:
        timer_guess = 40;
        break;
    case 2:
        timer_guess = 60;
        break;
    case 3:
        timer_guess = 80;
        break;
    case 4:
        timer_guess = 100;
        break;
    default:
        break;
    }
    // 根据猜测时间设置进度条
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(timer_guess);
    ui->progressBar->setValue(0);
    // 初始化guessNum 和 随机数
    this->guessNum = "";
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    this->randGuessNum = qrand()%10000 + 1;
    qDebug() << "timer_guess:" << this->timer_guess;
    qDebug() << "randGuessNum:" << this->randGuessNum;
}

void Widget::on_pushButton_back_clicked()
{
//    auto res = QMessageBox::warning(this,"返回主界面","返回主界面之前的数据会清空",QMessageBox::Ok | QMessageBox::No);
//    if(res == QMessageBox::Ok){
//        ui->stackedWidget->setCurrentIndex(0);
//    }
    msg = new QMessageBox(this);
    msg->setWindowTitle("返回主界面");
    msg->setText("返回主界面之前的数据会清空");
    auto *b1 = new QPushButton("确定返回",this);
    auto *b2 = new QPushButton("不返回",this);
    msg->addButton(b1,QMessageBox::YesRole);
    msg->addButton(b2,QMessageBox::NoRole);
    msg->exec();
    if(msg->clickedButton() == b1){       
        ui->stackedWidget->setCurrentIndex(0);
        Clear_all();
    }else{
        ;
    }
}

void Widget::on_pushButton_numDelete_clicked()
{
    if(!this->guessNum.isEmpty()){
        this->guessNum.chop(1);
        ui->lineEdit_inputNum->setText(this->guessNum);
    }
}

void Widget::on_pushButton_numComplete_clicked()
{
    int res = this->guessNum.toInt();
    if(res == this->randGuessNum){ // 猜测成功
            this->Guess_win();
    }else{ // 猜测失败
//        QMessageBox *msg = new QMessageBox;
        msg = new QMessageBox(this);
        msg->setWindowTitle("失败");
        msg->setText("您猜测的数字不正确,请重新尝试");
        QPushButton *b1 = new QPushButton("好的",this);
        msg->addButton(b1,QMessageBox::AcceptRole);
        msg->exec();
    }
}

void Widget::on_pushButton_numTip_clicked()
{
    QString str1("您猜测的数大了!");
    QString str2("您猜测的数小了!");
    QString str3("您猜测的数与实际相等!");
    QString str4("您还未输入猜测的数!");
    QPushButton *b = new QPushButton("好的",this);
    msg = new QMessageBox(this);
    if(this->guessNum.isEmpty()){
        msg->setText(str4);
    }else{
        int res = this->guessNum.toInt();

        if(res > randGuessNum)
            msg->setText(str1);
        else if(res < randGuessNum )
            msg->setText(str2);
        else if(res == randGuessNum)
            msg->setText(str3);
    }
    msg->setWindowTitle("提示");
    msg->addButton(b,QMessageBox::AcceptRole);
    msg->exec();

}
