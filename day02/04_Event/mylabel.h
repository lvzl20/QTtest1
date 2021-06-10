#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
//#include <QMouseEvent>
class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);
protected:
    void mouseMoveEvent(QMouseEvent *ev) override;
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;
    // 进入窗口区域
    void enterEvent(QEvent *) override;
    // 离开窗口区域
    void leaveEvent(QEvent *) override;
signals:

};

#endif // MYLABEL_H
