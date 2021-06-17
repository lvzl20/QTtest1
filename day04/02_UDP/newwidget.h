#ifndef NEWWIDGET_H
#define NEWWIDGET_H

#include <QWidget>
#include <QUdpSocket>

namespace Ui {
class newWidget;
}

class newWidget : public QWidget
{
    Q_OBJECT

public:
    explicit newWidget(QWidget *parent = nullptr);
    ~newWidget();

    void dealMsg();
private:
    Ui::newWidget *ui;

    QUdpSocket *udpSocket;
};

#endif // NEWWIDGET_H
