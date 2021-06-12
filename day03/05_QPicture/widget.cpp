#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPicture>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPicture picture;
    QPainter p;
    p.begin(&picture);

    p.drawPixmap(0, 0, 80, 80, QPixmap("../Image/27.jpg"));
    p.drawLine(50, 50, 150, 50);

    p.end();
    picture.save("../picture.png");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *){
 #if 0
    QPainter p(this);
    //  加载保存的二进制图片
    QPicture pic;
    pic.load("../picture.png");
    p.drawPicture(0, 0,pic);
 #endif
    // QPixmap 和 QImage 相互转换
    QPainter p(this);
    QPixmap pixmap;
    pixmap.load("../Image/27.jpg");
    QImage temImage = pixmap.toImage();
    p.drawImage(0, 0, temImage);

    QPixmap temPixmap = QPixmap::fromImage(temImage);
    p.drawPixmap(0, 250, temPixmap);

}

