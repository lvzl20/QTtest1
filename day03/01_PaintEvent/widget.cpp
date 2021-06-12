#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    x = 0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *){
//    QPainter p(this);
    // 创建画家对象
    QPainter p;
    // 指定当前窗口为绘图设备
    p.begin(this); // 需要end

    // 绘图操作
    // 画背景图
    // p.drawPixmap(0, 0, width(), height(), QPixmap("../Image/27.jpg"));
    p.drawPixmap(rect(),QPixmap("../Image/37.jpg"));

    // 定义画笔
    QPen pen;
    pen.setWidth(5); // 设置线宽
    pen.setColor(Qt::red); //设置颜色
    pen.setColor(QColor(136, 116, 186)); // rgb设置颜色
    pen.setStyle(Qt::DashLine); // 设置风格

    // 把画笔交给画家
    p.setPen(pen);

    // 画直线
    p.drawLine(50, 50, 150, 50);
    p.drawLine(50, 50, 50, 150);

    // 创建画刷对象
    QBrush brush;
    brush.setColor(Qt::red); // 设置颜色
    brush.setStyle(Qt::Dense1Pattern); //设置样式
    // 将画刷交给画家
    p.setBrush(brush);
    // 画矩形
    p.drawRect(200,200,50,50);

    // 画圆形
    p.drawEllipse(QPoint(150,150),50,25);// 设置圆形和水平、垂直方向的半径，如果两个半径相同就是圆形

    // 画一个图片,用于按钮点击后移动
    p.drawPixmap(x, 200, 50, 50, QPixmap("../Image/27.jpg"));

    p.end();
}

void Widget::on_pushButton_clicked()
{
    x += 50;
    if(x > width()){
        x = 0;
    }
    // 刷新窗口,让窗口重绘
    update(); // 间接调用paintEvent()
}
