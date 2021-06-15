#ifndef CHESS_H
#define CHESS_H

#include <QWidget>

class Chess : public QWidget
{
    Q_OBJECT
public:
    explicit Chess(QWidget *parent = nullptr);
    void operator=(const Chess& c); // 重载赋值构造函数

    // 棋子类型 从0开始为 兵,車,馬,象(相),士(仕),将(帅)
    enum TYPE{ARMY,PAO,CAR,HORSE,XIANG,SHI,MASTE};

    // 棋子所属阵营 red = 0, black = 1
    enum BELONG{RED,BLACK};

signals:
public:
    // 初始化棋子
    void initChess(const int);
public:
    int x;
    int y;// 棋子所在x,y坐标，移动会改变 (也可以使用行列表示,但x,y更直观)
    int chessType; // 棋子类型
    int chessBelong; // 棋子所属阵营
    int chessId; // 棋子ID
    bool isDead; // 棋子是否被吃
    QString chessPic; // 棋子图片
};

#endif // CHESS_H
