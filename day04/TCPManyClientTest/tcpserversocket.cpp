#include "tcpserversocket.h"

TcpServerSocket::TcpServerSocket(QObject *parent) : QTcpServer(parent)
{
    this->listen(QHostAddress::Any, 8888);
}

void TcpServerSocket::incomingConnection(qintptr handle){
    // 新生成一个连接就产生一个新的handle
    QTcpSocket *newClientSocket = new QTcpSocket(this);

    // 指定新生成的套接字描述符
    newClientSocket->setSocketDescriptor(handle);

    // 将套接字加入到列表中
    clientSocketList.append(newClientSocket);

    // 对加入的套接字添加connect
    connect(newClientSocket, &QTcpSocket::readyRead, this, &TcpServerSocket::slotReadData);
    connect(newClientSocket, &QTcpSocket::disconnected, this, &TcpServerSocket::slotDisconnect);

}

void TcpServerSocket::slotReadData(){
    // sender用于找到是谁触发了信号
    QTcpSocket *it = static_cast<QTcpSocket *>(sender());
    QByteArray array = it->readAll();
    QString msg = array;
    emit upDateserver(msg);

    // 给每个在线客户发送
    for(int i = 0; i < clientSocketList.size(); i++){
        clientSocketList[i]->write(msg.toUtf8().data());
    }
}

void TcpServerSocket::slotDisconnect(){
    QTcpSocket *it = static_cast<QTcpSocket *>(sender());
    for(int i = 0; i < clientSocketList.size(); i++){
        if(it->socketDescriptor() == clientSocketList[i]->socketDescriptor()){
            clientSocketList.removeAt(i);
            return ;
        }
    }
}
