#include "mytcpsocket.h"

MyTcpSocket::MyTcpSocket(QObject *parent) :
    QObject(parent)
{
}

void MyTcpSocket::doConnect()
{
    socket = new QTcpSocket(this);

    socket->connectToHost("148.251.87.245", 2000);

}

void MyTcpSocket::send(QByteArray string)
{
    socket->write(string);
}

QByteArray MyTcpSocket::get(){
    socket->waitForBytesWritten(1000);
    socket->waitForReadyRead(3000);

    return socket->readAll();
}

void MyTcpSocket::close(){
    socket->close();
}
