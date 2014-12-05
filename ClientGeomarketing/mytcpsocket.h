#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class MyTcpSocket : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpSocket(QObject *parent = 0);

    void doConnect();
    void send(QByteArray string);
    void close();
    QByteArray get();

signals:

public slots:

private:
    QTcpSocket *socket;

};

#endif // MYTCPSOCKET_H
