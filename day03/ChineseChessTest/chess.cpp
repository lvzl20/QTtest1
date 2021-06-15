#include "chess.h"

Chess::Chess(QWidget *parent) : QWidget(parent)
{

}

void Chess::operator=(const Chess &c){
    x = c.x;
    y = c.y;
    chessType = c.chessType;
    chessBelong = c.chessBelong;
    chessId = c.chessId;
    isDead = c.isDead;
    chessPic = c.chessPic;
}

void Chess::initChess(const int id){
    if(id > 31 || id < 0)
        return ;
    // 初始化棋子id
    chessId = id;

    // 初始化阵营, 上方为黑，下方为紅
    if(id < 16)
        chessBelong = BLACK;
    else
        chessBelong = RED;

    // 初始都棋子都存在
    isDead = false;

    // 初始化棋子类型和位置
    // 初始化顺序为黑方->紅方,黑方从上往下，从左往右初始化
    //                     红方从下往上，从左往右初始化
    // 棋盘左上角坐标为 (1,1)
    switch(id){
        case 0: y = 1, x = 1, chessType = CAR; break;
        case 1: y = 1, x = 2, chessType = HORSE; break;
        case 2: y = 1, x = 3, chessType = XIANG; break;
        case 3: y = 1, x = 4, chessType = SHI; break;
        case 4: y = 1, x = 5, chessType = MASTE; break;
        case 5: y = 1, x = 6, chessType = SHI; break;
        case 6: y = 1, x = 7, chessType = XIANG; break;
        case 7: y = 1, x = 8, chessType = HORSE; break;
        case 8: y = 1, x = 9, chessType = CAR; break;
        case 9: y = 3, x = 2, chessType = PAO; break;
        case 10: y = 3, x = 8, chessType = PAO; break;
        case 11: y = 4, x = 1, chessType = ARMY; break;
        case 12: y = 4, x = 3, chessType = ARMY; break;
        case 13: y = 4, x = 5, chessType = ARMY; break;
        case 14: y = 4, x = 7, chessType = ARMY; break;
         case 15: y = 4, x = 9, chessType = ARMY; break;

        case 16: y = 10, x = 1, chessType = CAR; break;
        case 17: y = 10, x = 2, chessType = HORSE; break;
        case 18: y = 10, x = 3, chessType = XIANG; break;
        case 19: y = 10, x = 4, chessType = SHI; break;
        case 20: y = 10, x = 5, chessType = MASTE; break;
        case 21: y = 10, x = 6, chessType = SHI; break;
        case 22: y = 10, x = 7, chessType = XIANG; break;
        case 23: y = 10, x = 8, chessType = HORSE; break;
        case 24: y = 10, x = 9, chessType = CAR; break;
        case 25: y = 8, x = 2, chessType = PAO; break;
        case 26: y = 8, x = 8, chessType = PAO; break;
        case 27: y = 7, x = 1, chessType = ARMY; break;
        case 28: y = 7, x = 3, chessType = ARMY; break;
        case 29: y = 7, x = 5, chessType = ARMY; break;
        case 30: y = 7, x = 7, chessType = ARMY; break;
        case 31: y = 7, x = 9, chessType = ARMY; break;
    }
    // 初始化图片
    if(id < 16){ // 黑方
        switch (chessType) {
            case ARMY: chessPic = ":/ChessImage/black_army.png"; break;
            case PAO: chessPic = ":/ChessImage/black_pao.png"; break;
            case CAR: chessPic = ":/ChessImage/black_car.png"; break;
            case HORSE: chessPic = ":/ChessImage/black_horse.png"; break;
            case XIANG: chessPic = ":/ChessImage/black_xiang.png"; break;
            case SHI: chessPic = ":/ChessImage/black_shi.png"; break;
            case MASTE: chessPic = ":/ChessImage/black_maste.png"; break;
        }
    }
    else{ // 红方
        switch (chessType) {
            case ARMY: chessPic = ":/ChessImage/red_army.png"; break;
            case PAO: chessPic = ":/ChessImage/red_pao.png"; break;
            case CAR: chessPic = ":/ChessImage/red_car.png"; break;
            case HORSE: chessPic = ":/ChessImage/red_horse.png"; break;
            case XIANG: chessPic = ":/ChessImage/red_xiang.png"; break;
            case SHI: chessPic = ":/ChessImage/red_shi.png"; break;
            case MASTE: chessPic = ":/ChessImage/red_maste.png"; break;
        }
    }
}
