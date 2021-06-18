#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include "chess.h"

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
    // 绘图事件
    void paintEvent(QPaintEvent *) override;
    // 鼠标按下，移动事件
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent*)override;
private:
    void init(); // 初始化棋子
    bool getChess(int x, int y, int flag); // 在没有选择棋子的情况下,flag = 0得到当前坐标下的棋子传给curSelectChess,当前坐标不在棋子范围则返回false
                                                 // flag = 1 得到目标区域的棋子，如果目标区域没有棋子则返回false
                                                 // flag = 2 代表仅判断是否有棋子
    bool moveTo(int x, int y); // 已经选择了棋子的情况下，将棋子移动, 返回true代表棋子移动一次

    // 不同类型的棋子移动, 返回值为是否成功移动
    bool moveArmyTo(int,int,bool);
    bool movePaoTo(int,int,bool);
    bool moveCarTo(int,int,bool);
    bool moveHorseTo(int,int,bool);
    bool moveXiangTo(int,int,bool);
    bool moveShiTo(int,int,bool);
    bool moveMasteTo(int,int,bool);

    bool done(); // 判断是否游戏结束
//    bool isWillDie();// 判断是否被将军

    int areaBlong(int logicY); // 传入逻辑y值(单位为棋盘的格子)判断当前所在红方还是黑方区域
    void reUpdate(); // 更新棋盘
//signals:
//    void  mysignal();
private:
    Ui::Widget *ui;
    QPoint point;
    // 棋子大小 即 格子大小
    int ChessSize;

    int oldLogicX; // 记录棋子移动前的位置，用于显示光标
    int oldLogicY;
    int curToGo; // 当前行棋的是哪一方

    // 32个棋子
    Chess chess[32];
    QLabel* label[32];

    Chess* curSelectChess; // 当前点击的棋子
    Chess* curToChess; // 将要覆盖掉的棋子

};
#endif // WIDGET_H
