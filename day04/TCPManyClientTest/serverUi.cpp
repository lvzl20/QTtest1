#include "serverui.h"
#include "ui_serverui.h"

serverUi::serverUi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::serverUi)
{
    ui->setupUi(this);
    setWindowTitle("端口地址:8888");

    server = new TcpServerSocket(this);
    connect(server,&TcpServerSocket::upDateserver,this,
            [=](QString msg){
                ui->textEdit->append(msg);
            });
}

serverUi::~serverUi()
{
    delete ui;
}

