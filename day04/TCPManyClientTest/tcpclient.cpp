//#include "tcpclient.h"
//#include "ui_tcpclient.h"
//#include <QHostAddress>
//#include <QMessageBox>

//TcpClient::TcpClient(QWidget *parent) :
//    QWidget(parent),
//    ui(new Ui::TcpClient)
//{
//    ui->setupUi(this);

//    // 初始未加入聊天室
//    status = false;
//    ui->lineEditIp->setEnabled(true);
//    ui->lineEditPort->setEnabled(true);
//    ui->lineEditUserName->setEnabled(true);

//    ui->buttonSelectFile->setEnabled(false);
//    ui->textEditSendMsg->setEnabled(false);
//    ui->buttonSend->setEnabled(false);

//    setWindowTitle("聊天室门口");

//    不能在此处初始化,否则后面信号可能会出问题
//    clientSocket = new QTcpSocket(this);
//}

//TcpClient::~TcpClient()
//{
//    delete ui;
//}

//void TcpClient::slotLinkSuccess(){
//    QMessageBox::information(this, "成功", "成功加入聊天室");
//    // 加入就不能修改数据
//    ui->lineEditIp->setEnabled(false);
//    ui->lineEditPort->setEnabled(false);
//    ui->lineEditUserName->setEnabled(false);

//    ui->buttonSelectFile->setEnabled(true);
//    ui->textEditSendMsg->setEnabled(true);
//    ui->buttonSend->setEnabled(true);

//    QString msg = userName + ":加入群聊";
//    clientSocket->write(msg.toUtf8().data());

//    status = true; // 加入了聊天室
//    setWindowTitle(QString("%1").arg(userName));

//    ui->buttonJoin->setText("退出聊天室"); // 再次点击就退出聊天室
//}

//void TcpClient::slotOutSuccess(){
//    QMessageBox::information(this, "成功", "成功退出聊天室");
//    // 可以修改数据
//    ui->lineEditIp->setEnabled(true);
//    ui->lineEditPort->setEnabled(true);
//    ui->lineEditUserName->setEnabled(true);

//    ui->buttonSelectFile->setEnabled(false);
//    ui->textEditSendMsg->setEnabled(false);
//    ui->buttonSend->setEnabled(false);

//    status = false; // 退出了聊天室
//    setWindowTitle("聊天室门口");
//    ui->buttonJoin->setText("加入聊天室"); // 再次点击就加入聊天室
//}

//void TcpClient::slotReadData(){
//    QByteArray array = clientSocket->readAll();
//    QString msg = array;
//    ui->textEditShowMsg->append(msg);
//}

//void TcpClient::on_buttonJoin_clicked()
//{
//    //判断用户是否在聊天室
//    if(false == status){ // 加入聊天室
//        QString ip = ui->lineEditIp->text();
//        quint16 port = ui->lineEditPort->text().toUInt();
//        if(ui->lineEditUserName->text() == ""){
//            QMessageBox::warning(this,"警告","用户名字不能为空");
//            return ;
//        }

//        userName = ui->lineEditUserName->text();


//        // 每次连接在这初始化
//        clientSocket = new QTcpSocket(this);
//        clientSocket->connectToHost(QHostAddress(ip),port);

//        // 连接成功
//        connect(clientSocket, &QTcpSocket::connected, this, &TcpClient::slotLinkSuccess);

//        // 接受消息
//        connect(clientSocket, &QTcpSocket::readyRead, this, &TcpClient::slotReadData);
//    }
//    else{ // 退出聊天室

//        QString msg = userName + ":退出群聊";
//        clientSocket->write(msg.toUtf8().data());

//        clientSocket->disconnectFromHost();
//        clientSocket->close();
//        connect(clientSocket, &QTcpSocket::disconnected, this, &TcpClient::slotOutSuccess);
//    }
//}


//void TcpClient::on_buttonSend_clicked()
//{
//    if(ui->textEditSendMsg->toPlainText() == ""){
//        QMessageBox::warning(this, "警告", "发送的消息不能为空");
//        return ;
//    }
//    QString msg = userName+ ":\n" + ui->textEditSendMsg->toPlainText();
//    clientSocket->write(msg.toUtf8().data());

//    // 清空发送框
//    ui->textEditSendMsg->clear();
//}
