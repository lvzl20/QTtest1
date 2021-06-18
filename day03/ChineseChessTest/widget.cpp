#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QPen>
#include <QFont>
#include <QBrush>
#include <QColor>
#include <QLabel>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 设置 棋子大小, 即格子大小
    this->ChessSize = 50;
    // 固定窗口大小为棋盘大小
    this->setMinimumSize(500,550);
    this->setMaximumSize(500,550);

    // 当前行棋为初始化为红色方
    this->curToGo = Chess::RED;

    // 初始化棋子在棋盘上
    init();


    this->oldLogicX = -1;
    this->oldLogicY = -1;

}

Widget::~Widget()
{
    delete ui;
}


void Widget::init(){
    for(int i = 0; i < 32; i++){
        chess[i].initChess(i);
        // 利用QLabel加载棋子图片
        label[i] = new QLabel(this);
        label[i]->resize(ChessSize,ChessSize);
        label[i]->setPixmap(QPixmap(chess[i].chessPic));
                // 自动适应图片大小
        label[i]->setScaledContents(true);
        label[i]->setGeometry(chess[i].x*ChessSize - ChessSize/2,
                           chess[i].y*ChessSize - ChessSize/2,
                           ChessSize,
                           ChessSize
                           );
        label[i]->show();
    }
}

int Widget::areaBlong(int logicY){
    if(logicY <= 5)
        return Chess::BLACK;
    else
        return Chess::RED;
}

void Widget::reUpdate(){
    for(int i = 0; i < 32; i++){
        label[i]->setGeometry(
                    chess[i].x*ChessSize - ChessSize/2,
                    chess[i].y*ChessSize - ChessSize/2,
                    ChessSize,
                    ChessSize
                    );
        if(chess[i].isDead)
            label[i]->hide();
    }
    update();
}

bool Widget::getChess(int x, int y, int flag){
    for(int i = 0; i < 32; i++){
            if(!chess[i].isDead){
                int lx = label[i]->x() + ChessSize/2, ly = label[i]->y() + ChessSize/2;
                int r = (x-lx)*(x-lx) + (y-ly)*(y-ly); // 虽然加载的是方形图片含透明部分,但判断的时候只需要判断鼠标点击棋子实体部分
                if(r <= ChessSize*ChessSize/4) // 鼠标点击的坐标在棋盘上某个棋子里面则找到
                {
                    if(flag == 0){
                        if(chess[i].chessBelong != curToGo) //如果不轮到当前点击的棋子的那一方行棋，则直接返回
                            return false;
                        curSelectChess = &chess[i];
                        oldLogicX = curSelectChess->x;
                        oldLogicY = curSelectChess->y;
                        update();
                    }
                    else if(flag == 1)
                        curToChess = &chess[i];
                    else
                        ;

                    return true;
                }
            }
    }
    return false;
}

bool Widget::moveTo(int x, int y){
    int logicX = (x+ChessSize/2)/ChessSize;
    int logicY = (y+ChessSize/2)/ChessSize; // 目标的逻辑x，y值，即单位为棋盘的格子
    int newx = logicX*ChessSize - ChessSize/2;
    int newy = logicY*ChessSize - ChessSize/2;

    // 棋子移动到原来位置不算
    if(logicX == curSelectChess->x && logicY == curSelectChess->y)
        return false;

    // 棋子不能移动到棋盘外
    if(newx < rect().left() || newy < rect().top() || newx > rect().right()-ChessSize || newy > rect().bottom()-ChessSize)
        return true;
//    int id = curSelectChess->chessId; // 当前选择棋子的ID
    int type = curSelectChess->chessType;
    bool HasChess = getChess(x, y, 1); // 判断目标区域有没有棋子，有则赋值给curToChess
    bool isComplete = false;
    switch (type) { // 对应类型的棋子到对应的函数进行判断是否移动或吃掉对方棋子
        case Chess::ARMY: isComplete =  moveArmyTo(logicX,logicY,HasChess); break;
        case Chess::PAO: isComplete =  movePaoTo(logicX,logicY,HasChess); break;
        case Chess::CAR: isComplete =  moveCarTo(logicX,logicY,HasChess); break;
        case Chess::HORSE: isComplete =  moveHorseTo(logicX,logicY,HasChess); break;
        case Chess::XIANG: isComplete =  moveXiangTo(logicX,logicY,HasChess); break;
        case Chess::SHI: isComplete =  moveShiTo(logicX,logicY,HasChess); break;
        case Chess::MASTE: isComplete =  moveMasteTo(logicX,logicY,HasChess); break;
    }
    if(isComplete == true){ // 已经移动棋子,该对方行棋了
        // 设置对方行棋
        if(curToGo == Chess::RED)
            curToGo = Chess::BLACK;
        else
            curToGo = Chess::RED;
    }
    reUpdate();
    return true;
}

bool Widget::moveArmyTo(int logicX,int logicY,bool HasChess){
    bool isComplete = false; // 是否完成移动
        if(curSelectChess->chessBelong == Chess::BLACK) // 选择的棋子为黑方卒
         {
            if(areaBlong(curSelectChess->y) == Chess::BLACK){ // 所处区域为黑色方, 只能前进一格
                if(HasChess){ // 如果目标区域有棋子, 且在黑色卒可执行范围且为红色棋子,则吃掉
                    if(curSelectChess->x == curToChess->x && curSelectChess->y+1 == curToChess->y && curToChess->chessBelong == Chess::RED)
                        isComplete = true;
                }
                else{ // 如果目标区域无棋子, 且在黑色卒的可执行范围，则移动过去
                    if(curSelectChess->x == logicX && curSelectChess->y+1 == logicY){
                         isComplete = true;
                    }
                }
            }
            else{ // 所处区域为红色方,可以选择前进一格或左右移动
                if(HasChess){ //如果目标区域有棋子, 且在黑色卒可执行范围且为红色棋子,则吃掉
                    if(curSelectChess->x == curToChess->x && curSelectChess->y+1 == curToChess->y && curToChess->chessBelong == Chess::RED)
                        isComplete = true;
                    else if(curSelectChess->x+1 == curToChess->x && curSelectChess->y == curToChess->y && curToChess->chessBelong == Chess::RED)
                        isComplete = true;
                    else if(curSelectChess->x-1 == curToChess->x && curSelectChess->y == curToChess->y && curToChess->chessBelong == Chess::RED)
                        isComplete = true;
                }
                else{ //目标区域无棋子,且在黑色卒的可执行范围
                    if(curSelectChess->x == logicX && curSelectChess->y+1 == logicY)
                        isComplete = true;
                    else if(curSelectChess->x+1 == logicX && curSelectChess->y == logicY)
                        isComplete = true;
                    else if(curSelectChess->x-1 == logicX && curSelectChess->y == logicY)
                        isComplete = true;
                }
            }
        }
        else{ // 选择的棋子为红色方
            if(areaBlong(curSelectChess->y) == Chess::RED){ // 所处区域为紅色方, 只能前进一格
                if(HasChess){ // 如果目标区域有棋子, 且在紅色卒可执行范围且为黑色棋子,则吃掉
                    if(curSelectChess->x == curToChess->x && curSelectChess->y-1 == curToChess->y && curToChess->chessBelong == Chess::BLACK)
                        isComplete = true;
                }
                else{ // 如果目标区域无棋子, 且在紅色卒的可执行范围，则移动过去
                    if(curSelectChess->x == logicX && curSelectChess->y-1 == logicY){
                        isComplete = true;
                    }
                }
            }
            else{ // 所处区域为黑色方,可以选择前进一格或左右移动
                if(HasChess){ //如果目标区域有棋子, 且在紅色卒可执行范围且为黑色棋子,则吃掉
                    if(curSelectChess->x == curToChess->x && curSelectChess->y-1 == curToChess->y && curToChess->chessBelong == Chess::BLACK)
                        isComplete = true;
                    else if(curSelectChess->x+1 == curToChess->x && curSelectChess->y == curToChess->y && curToChess->chessBelong == Chess::BLACK)
                        isComplete = true;
                    else if(curSelectChess->x-1 == curToChess->x && curSelectChess->y == curToChess->y && curToChess->chessBelong == Chess::BLACK)
                        isComplete = true;

                }
                else{ //目标区域无棋子,且在紅色卒的可执行范围
                    if(curSelectChess->x == logicX && curSelectChess->y-1 == logicY)
                         isComplete = true;
                    else if(curSelectChess->x+1 == logicX && curSelectChess->y == logicY)
                        isComplete = true;
                    else if(curSelectChess->x-1 == logicX && curSelectChess->y == logicY)
                        isComplete = true;
                }
            }
        }
        if(isComplete && !HasChess) //目标区域无棋子, 且可以移动
        {
            curSelectChess->x = logicX;
            curSelectChess->y = logicY;
        }
        if(isComplete && HasChess) // 目标区域有对方棋子
        {
            curSelectChess->x = logicX;
            curSelectChess->y = logicY;
            curToChess->isDead = true;
        }
        return isComplete;
}

bool Widget::movePaoTo(int logicX,int logicY,bool HasChess){
    bool isComplete = false; // 是否完成移动
    // 当前棋子和目标区域不在同一条线,直接返回
    if(curSelectChess->x != logicX && curSelectChess->y != logicY)
        return isComplete;
    int count = 0; // 统计当前棋子到目标区域之间有多少个棋子
    if(curSelectChess->x == logicX){ //x轴相同的情况
        for(int i = 0; i < 32; i++){
            if(!chess[i].isDead)
            if(chess[i].x == logicX)
            if((chess[i].y > curSelectChess->y && chess[i].y < logicY) ||
                    (chess[i].y < curSelectChess->y && chess[i].y >logicY))
                ++count;
        }
    }
    else{ // y轴相同的情况
        for(int i = 0; i < 32; i++){
            if(!chess[i].isDead)
            if(chess[i].y == logicY)
            if((chess[i].x > curSelectChess->x && chess[i].x < logicX) ||
                    (chess[i].x < curSelectChess->x && chess[i].x >logicX))
                ++count;
        }
    }
    if(!HasChess) // 目标区域没有棋子,需要判断当前棋子到目标区域是否有棋子
    {   if(count >= 1)  // 当前棋子到目标区域有棋子，直接返回
            return isComplete;
        else{ // 当前棋子到目标区域没有棋子, 可以移动
            isComplete = true;
        }
    }
    else{ // 目标区域有棋子
        // 目标棋子为自己阵营, 直接返回
        if((curSelectChess->chessBelong == Chess::BLACK && curToChess->chessBelong == Chess::BLACK) ||
                (curSelectChess->chessBelong == Chess::RED && curToChess->chessBelong == Chess::RED))
            return isComplete;
        if(count != 1) // 目标棋子和当前棋子之间棋子个数不等于1, 之间返回
            return isComplete;
        // 可以移动, 目标棋子被吃, 当前棋子坐标更改
        isComplete = true;
    }
    if(isComplete && !HasChess) //目标区域无棋子, 且可以移动
    {
        curSelectChess->x = logicX;
        curSelectChess->y = logicY;
    }
    if(isComplete && HasChess) // 目标区域有对方棋子
    {
        curSelectChess->x = logicX;
        curSelectChess->y = logicY;
        curToChess->isDead = true;
    }
    return isComplete;
}

bool Widget::moveCarTo(int logicX,int logicY,bool HasChess){
    bool isComplete = false;
    // 当前棋子和目标区域不在同一条线,直接返回
    if(curSelectChess->x != logicX && curSelectChess->y != logicY)
        return isComplete;
    int count = 0; // 统计当前棋子到目标区域之间有多少个棋子
    if(curSelectChess->x == logicX){ //x轴相同的情况
        for(int i = 0; i < 32; i++){
            if(!chess[i].isDead)
            if(chess[i].x == logicX)
            if((chess[i].y > curSelectChess->y && chess[i].y < logicY) ||
                    (chess[i].y < curSelectChess->y && chess[i].y >logicY))
                ++count;
        }
    }
    else{ // y轴相同的情况
        for(int i = 0; i < 32; i++){
            if(!chess[i].isDead)
            if(chess[i].y == logicY)
            if((chess[i].x > curSelectChess->x && chess[i].x < logicX) ||
                    (chess[i].x < curSelectChess->x && chess[i].x >logicX))
                ++count;
        }
    }
    if(!HasChess){ //如果目标区域没有棋子
        if(count > 0) // 当前棋子到目标区域有棋子,直接返回
            return isComplete;
        else{ // 当前棋子到目标区域没有棋子, 可以移动
            isComplete = true;
        }
    }
    else{ // 目标区域有棋子
        // 目标棋子为自己阵营,直接返回
        if((curSelectChess->chessBelong == Chess::BLACK && curToChess->chessBelong == Chess::BLACK) ||
                (curSelectChess->chessBelong == Chess::RED && curToChess->chessBelong == Chess::RED))
            return isComplete;
        if(count > 0) // 当前棋子到目标棋子之间有棋子, 直接返回
            return isComplete;
        // 可以移动，吃掉目标棋子,更改当前棋子坐标
        isComplete = true;
    }
    if(isComplete && !HasChess) //目标区域无棋子, 且可以移动
    {
        curSelectChess->x = logicX;
        curSelectChess->y = logicY;
    }
    if(isComplete && HasChess) // 目标区域有对方棋子
    {
        curSelectChess->x = logicX;
        curSelectChess->y = logicY;
        curToChess->isDead = true;
    }
    return isComplete;
}

bool Widget::moveHorseTo(int logicX,int logicY,bool HasChess){
    bool isComplete = false;
    // 馬的可移动范围
    int x[8] = {curSelectChess->x-2, curSelectChess->x-1, curSelectChess->x+1, curSelectChess->x+2,
                    curSelectChess->x-2, curSelectChess->x-1, curSelectChess->x+1, curSelectChess->x+2};
    int y[8] = {curSelectChess->y+1, curSelectChess->y+2, curSelectChess->y+2, curSelectChess->y+1,
                    curSelectChess->y-1, curSelectChess->y-2, curSelectChess->y-2, curSelectChess->y-1};
    // 阻碍馬移动的范围
    int tx[8] = {curSelectChess->x-1, curSelectChess->x, curSelectChess->x, curSelectChess->x+1,
                    curSelectChess->x-1, curSelectChess->x, curSelectChess->x, curSelectChess->x+1};
    int ty[8] = {curSelectChess->y, curSelectChess->y+1, curSelectChess->y+1, curSelectChess->y,
                    curSelectChess->y, curSelectChess->y-1, curSelectChess->y-1, curSelectChess->y};
    bool flag = false;
    for(int i = 0; i < 8; i++){ // 判断目标区域是否在可移动范围
        if(x[i] == logicX && y[i] == logicY){
            flag = true;
            break;
        }
    }
    if(!flag) // 不在可移动范围,直接返回
        return isComplete;
    // 判断是否有阻碍, 有就直接返回
    for(int i = 0; i < 32; i++){
        if(!chess[i].isDead)
        for(int j = 0; j < 8; j++){
            if(chess[i].x == tx[j] && chess[i].y == ty[j] && x[j] == logicX && y[j] == logicY){
                return isComplete;
            }
        }
    }
    // 判断目标有棋子的情况, 是否是自己阵营的棋子
    if(HasChess && curSelectChess->chessBelong == curToChess->chessBelong)
        return isComplete;
    else
        isComplete = true;

    // 可以移动
    if(isComplete && !HasChess) //目标区域无棋子, 且可以移动
    {
        curSelectChess->x = logicX;
        curSelectChess->y = logicY;
    }
    if(isComplete && HasChess) // 目标区域有对方棋子,且可以移动
    {
        curSelectChess->x = logicX;
        curSelectChess->y = logicY;
        curToChess->isDead = true;
    }
    return isComplete;

}

bool Widget::moveXiangTo(int logicX,int logicY,bool HasChess){
    bool isComplete = false;
    // 象的可移动区域
    int x[4] = {curSelectChess->x-2, curSelectChess->x+2, curSelectChess->x-2, curSelectChess->x+2};
    int y[4] = {curSelectChess->y+2, curSelectChess->y+2, curSelectChess->y-2, curSelectChess->y-2};
    // 阻碍象移动的区域
    int tx[4] = {curSelectChess->x-1, curSelectChess->x+1, curSelectChess->x-1, curSelectChess->x+1};
    int ty[4] = {curSelectChess->y+1, curSelectChess->y+1, curSelectChess->y-1, curSelectChess->y-1};
    // 处理黑色方
    if(curSelectChess->chessBelong == Chess::BLACK){
        if(areaBlong(logicY) == Chess::RED) // 如果目标区域在红色方,直接返回
            return isComplete;
    }
    else{ // 处理红色方
        if(areaBlong(logicY) == Chess::BLACK) // 如果目标区域在红色方,直接返回
            return isComplete;
    }
    bool flag = false; // 判断移动区域是否在象的可执行区域
    // 判断是否有阻碍象移动的棋子
    for(int i = 0; i < 4; i++){
        if(x[i] == logicX && y[i] == logicY){
            for(int j = 0; j < 32; j++){
                if(!chess[j].isDead)
                    for(int k = 0; k < 4; k++){
                        if(chess[j].x == tx[k] && chess[j].y == ty[k] && k == i) // 有阻碍象移动的棋子,直接返回
                            return isComplete;
                    }
            }
            flag = true;
            break;
        }
    }
    if(!flag) // 移动区域不在象的可执行区域
        return isComplete;
    // 可以移动
    if(!HasChess) //目标无棋子
    {
        isComplete = true;
    }
    else{ // 目标有棋子
        if(curToChess->chessBelong == curSelectChess->chessBelong) // 不能吃掉己方棋子
            return isComplete;
        isComplete = true;// 可以吃掉
    }

    if(isComplete && !HasChess) //目标区域无棋子, 且可以移动
    {
        curSelectChess->x = logicX;
        curSelectChess->y = logicY;
    }
    if(isComplete && HasChess) // 目标区域有对方棋子,且可以移动
    {
        curSelectChess->x = logicX;
        curSelectChess->y = logicY;
        curToChess->isDead = true;
    }
    return isComplete;
}

bool Widget::moveShiTo(int logicX,int logicY,bool HasChess){
    bool isComplete = false;
    int x[4] = {curSelectChess->x+1, curSelectChess->x+1, curSelectChess->x-1, curSelectChess->x-1};
    int y[4] = {curSelectChess->y+1, curSelectChess->y-1, curSelectChess->y+1, curSelectChess->y-1};
    // 判断目标区域是否在士的可移动范围
    if(curSelectChess->chessBelong == Chess::RED){ // 判断红方
        int tx[5] = {4,4,5,6,6};
        int ty[5] = {8,10,9,8,10};
        bool flag = false;
        for(int i = 0; i < 5; i++){
            if(tx[i] == logicX && ty[i] == logicY)
             {
                flag = true; break;
            }
        }
        if(!flag)
            return isComplete;
    }else{ // 判断黑方
        int tx[5] = {4,4,5,6,6};
        int ty[5] = {1,3,2,1,3};
        bool flag = false;
        for(int i = 0; i < 5; i++){
            if(tx[i] == logicX && ty[i] == logicY)
             {
                flag = true; break;
            }
        }
        if(!flag)
            return isComplete;
    }
    for(int i = 0; i < 4; i++){
        if(x[i] == logicX && y[i] == logicY){ // 目标区域在当前士位置的可移动区域
            if(!HasChess){ // 目标区域没有棋子,直接移动
                isComplete = true;
                break;
            }
            else{ // 目标区域有棋子,需要判断是否是对方的
                    // 是自己阵营的棋子,返回false,移动失败
                if(curToChess->chessBelong == curSelectChess->chessBelong){
                    return isComplete;
                }else{ // 是对方的棋子, 吃掉
                    isComplete = true;
                    break;
                }
            }
        }
    }
    if(isComplete && !HasChess) //目标区域无棋子, 且可以移动
    {
        curSelectChess->x = logicX;
        curSelectChess->y = logicY;
    }
    if(isComplete && HasChess) // 目标区域有对方棋子
    {
        curSelectChess->x = logicX;
        curSelectChess->y = logicY;
        curToChess->isDead = true;
    }
    return isComplete;
}

bool Widget::moveMasteTo(int logicX,int logicY,bool HasChess){
    bool isComplete = false;
    int x[4] = {curSelectChess->x+1, curSelectChess->x, curSelectChess->x-1, curSelectChess->x};
    int y[4] = {curSelectChess->y, curSelectChess->y+1, curSelectChess->y, curSelectChess->y-1};
    // 判断目标区域是否在master的可移动范围,不在直接返回
    if(curSelectChess->chessBelong == Chess::RED){ // 判断红方
        if(logicX < 4 || logicX > 6 || logicY < 8)
            return isComplete;
    }else{ // 判断黑方
        if(logicX < 4 || logicX > 6 || logicY > 3)
            return isComplete;
    }
    for(int i = 0; i < 4; i++){
        if(x[i] == logicX && y[i] == logicY){ // 目标区域在master的可移动范围
            if(!HasChess){ //目标区域无棋子,可以移动
                isComplete = true;
                break;
            }
            else{
                if(curSelectChess->chessBelong == curToChess->chessBelong) // 目标区域有棋子且为自己阵营，直接返回
                    return isComplete;
                // 可以移动
                isComplete = true;
                 break;
            }
        }
    }
    if(isComplete && !HasChess) //目标区域无棋子, 且可以移动
    {
        curSelectChess->x = logicX;
        curSelectChess->y = logicY;
    }
    if(isComplete && HasChess) // 目标区域有对方棋子
    {
        curSelectChess->x = logicX;
        curSelectChess->y = logicY;
        curToChess->isDead = true;
    }
    return isComplete;
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

   // 绘制聚焦
    pen.setWidth(3);
    pen.setColor(Qt::blue);
    p.setPen(pen);
    int realx = curSelectChess->x*ChessSize;
    int realy = curSelectChess->y*ChessSize;
    if(oldLogicX >= 0 && oldLogicY >= 0){
        int oldRealx = oldLogicX*ChessSize;
        int oldRealy = oldLogicY*ChessSize;
        // 绘制将移动棋子的聚焦光标
        point[0] = QPoint(oldRealx-ChessSize/2, oldRealy);
        point[1] = QPoint(oldRealx-ChessSize/2, oldRealy-ChessSize/2);
        point[2] = QPoint(oldRealx, oldRealy-ChessSize/2);
        p.drawPolyline(point, 3);
        point[0] = QPoint(oldRealx+ChessSize/2, oldRealy);
        point[1] = QPoint(oldRealx+ChessSize/2, oldRealy-ChessSize/2);
        point[2] = QPoint(oldRealx, oldRealy-ChessSize/2);
        p.drawPolyline(point, 3);
        point[0] = QPoint(oldRealx+ChessSize/2, oldRealy);
        point[1] = QPoint(oldRealx+ChessSize/2, oldRealy+ChessSize/2);
        point[2] = QPoint(oldRealx, oldRealy+ChessSize/2);
        p.drawPolyline(point, 3);
        point[0] = QPoint(oldRealx-ChessSize/2, oldRealy);
        point[1] = QPoint(oldRealx-ChessSize/2, oldRealy+ChessSize/2);
        point[2] = QPoint(oldRealx, oldRealy+ChessSize/2);
        p.drawPolyline(point, 3);
    }
    // 跟踪将移动棋子绘制光标
    point[0] = QPoint(realx-ChessSize/2, realy);
    point[1] = QPoint(realx-ChessSize/2, realy-ChessSize/2);
    point[2] = QPoint(realx, realy-ChessSize/2);
    p.drawPolyline(point, 3);
    point[0] = QPoint(realx+ChessSize/2, realy);
    point[1] = QPoint(realx+ChessSize/2, realy-ChessSize/2);
    point[2] = QPoint(realx, realy-ChessSize/2);
    p.drawPolyline(point, 3);
    point[0] = QPoint(realx+ChessSize/2, realy);
    point[1] = QPoint(realx+ChessSize/2, realy+ChessSize/2);
    point[2] = QPoint(realx, realy+ChessSize/2);
    p.drawPolyline(point, 3);
    point[0] = QPoint(realx-ChessSize/2, realy);
    point[1] = QPoint(realx-ChessSize/2, realy+ChessSize/2);
    point[2] = QPoint(realx, realy+ChessSize/2);
    p.drawPolyline(point, 3);

}


// 鼠标事件用于制作棋子的移动等.
void Widget::mousePressEvent(QMouseEvent *e){
    if(e->button() != Qt::LeftButton) // 只处理鼠标左键
        return ;
    static bool isSelect = false; // 是否选择了棋子
    if(isSelect == false){
        bool isChess = getChess(e->x(), e->y(), 0); //如果是棋子则将isSelect置为true，并将棋子赋值给curSelectChess
        if(isChess) isSelect = true;

    }else{ // 处理棋子将要移动的地方
        if(moveTo(e->x(),e->y()) == true){
            isSelect = false;
        }
    }

}

void Widget::mouseMoveEvent(QMouseEvent *e){

}
