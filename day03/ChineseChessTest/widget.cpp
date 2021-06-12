#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QPen>
#include <QFont>
#include <QBrush>
#include <QColor>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 设置 棋子大小, 即格子大小
    this->ChessSize = 50;

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *){
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::black);
    QPainter p(this);
    p.setPen(pen);
    QBrush brush;
    brush.setColor(QColor(216, 180, 80));
    brush.setStyle(Qt::SolidPattern);
    p.setBrush(brush);

//    p.drawPixmap(rect(),QPixmap(":/ChessImage/back1.jpg"));

    // 取窗口的左上角坐标(left, top) 和 宽高(right, bottom)
    int top = rect().top();
    int bottom = rect().bottom();
    int left = rect().left();
    int right = rect().right();

    // 通过画刷绘制背景, 并取消画刷(防止后面绘制其他图形继续被刷,当然本项目做的简易中国象棋用于练手,应该不会使用了)
    p.drawRect(left, top, right, bottom);
    p.setBrush(Qt::NoBrush);

    // 绘制棋盘的边框
    p.drawLine(left + ChessSize - 5, top + ChessSize - 5, left + ChessSize - 5, bottom - ChessSize + 5);
    p.drawLine(left + ChessSize - 5, top + ChessSize - 5, right - ChessSize + 5, top + ChessSize - 5);
    p.drawLine(right - ChessSize + 5, top + ChessSize - 5, right - ChessSize + 5, bottom - ChessSize + 5);
    p.drawLine(left + ChessSize - 5, bottom - ChessSize + 5, right - ChessSize + 5, bottom - ChessSize + 5);
    pen.setWidth(2);
    p.setPen(pen);

    // 绘制棋盘中的细线
    for(int x = left + ChessSize; x < right; x += ChessSize){
        for(int y = top + ChessSize; y < bottom; y += ChessSize){
            if(x == left + ChessSize){
                     p.drawLine(x, y, right - ChessSize, y);
            }
            if(y == top + ChessSize){
                    p.drawLine(x, y, x, (bottom - ChessSize) / 2);
                    p.drawLine(x, (bottom + ChessSize) / 2, x, bottom - ChessSize);
            }

        }
    }
   p.drawLine((right/2 - ChessSize), top + ChessSize, (right/2 + ChessSize), top + 3*ChessSize);
   p.drawLine((right/2 + ChessSize), top + ChessSize, (right/2 - ChessSize), top + 3*ChessSize);
   p.drawLine((right/2 - ChessSize), bottom - ChessSize, (right/2 + ChessSize), bottom - 3*ChessSize);
   p.drawLine((right/2 + ChessSize), bottom - ChessSize, (right/2 - ChessSize), bottom - 3*ChessSize);

   // 设置分界河标志
   p.setFont(QFont("Arial", 25));
   p.drawText(QPoint(right/2-100, bottom/2+15), "楚河         汉界");

   // 设置炮兵和步兵站位的 '#' 字
   pen.setWidth(4);
   p.setPen(pen);
   int x, y;
   QPoint point[3];
   for(int j = 0; j < 2; j++ )
   for(int i = 1; i <= 9; i++){
       if(i == 4 || i == 6)
           continue;
       x = left + i*ChessSize; // x坐标不会因为上下半区而改变
       if(j == 0){   // 处理上半区
           if(i % 2 == 0) // 处理上半区炮兵的 '#'字
               y = top + 3*ChessSize;
           else           // 处理上半区步兵的'#'字
               y = top + 4*ChessSize;
       }
       else{  // 处理下半区
           if(i % 2 == 0) // 处理下半区炮兵的 '#'字
               y = bottom - 3*ChessSize;
           else           // 处理下半区步兵的 '#'字
               y = bottom - 4*ChessSize;
       }
       // 单独处理两边兵的 '#'字（因为只有一半）
       // drawPokyline第一个参数为数组首地址，第二个参数为数组长度，稍微熟悉点C++就懂了
       // 它的功能是将数组的点依次连接但不填充，如颜色等。(第一次使用，参考的网上)
       if(i == 1){
           point[0] = QPoint(x+5, y-15);
           point[1] = QPoint(x+5, y-5);
           point[2] = QPoint(x+15, y-5);
           p.drawPolyline(point,3);
           point[0] = QPoint(x+5, y+15);
           point[1] = QPoint(x+5, y+5);
           point[2] = QPoint(x+15, y+5);
           p.drawPolyline(point,3);
           continue;
       }
       if(i == 9){
           point[0] = QPoint(x-5, y-15);
           point[1] = QPoint(x-5, y-5);
           point[2] = QPoint(x-15, y-5);
           p.drawPolyline(point,3);
           point[0] = QPoint(x-5, y+15);
           point[1] = QPoint(x-5, y+5);
           point[2] = QPoint(x-15, y+5);
           p.drawPolyline(point,3);
           continue;
       }
       // 其他部分正常(炮兵和中间步兵的 '#'字)
       point[0] = QPoint(x+5, y-15);
       point[1] = QPoint(x+5, y-5);
       point[2] = QPoint(x+15, y-5);
       p.drawPolyline(point,3);
       point[0] = QPoint(x+5, y+15);
       point[1] = QPoint(x+5, y+5);
       point[2] = QPoint(x+15, y+5);
       p.drawPolyline(point,3);
       point[0] = QPoint(x-5, y-15);
       point[1] = QPoint(x-5, y-5);
       point[2] = QPoint(x-15, y-5);
       p.drawPolyline(point,3);
       point[0] = QPoint(x-5, y+15);
       point[1] = QPoint(x-5, y+5);
       point[2] = QPoint(x-15, y+5);
       p.drawPolyline(point,3);
   }

















}
// 鼠标事件用于后面深入制作棋子的移动等.
void Widget::mousePressEvent(QMouseEvent *e){

}

void Widget::mouseMoveEvent(QMouseEvent *e){

}
