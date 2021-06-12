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
    // 绘图事件
    void paintEvent(QPaintEvent *) override;
    // 鼠标按下，移动事件
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent*)override;
private:
    Ui::Widget *ui;
    QPoint point;
    // 棋子大小 即 格子大小
    int ChessSize;
};
#endif // WIDGET_H
