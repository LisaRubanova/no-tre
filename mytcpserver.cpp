#include "mytcpserver.h"
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QCoreApplication>

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    //server_status=0;
}
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        //server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
 //   if(server_status==1){
        mTcpSocket = mTcpServer->nextPendingConnection();
        mTcpSocket->write("Hello, World!!! I am echo server!\r\n");
        connect(mTcpSocket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
        connect(mTcpSocket,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);
   // }
}

void MyTcpServer::slotServerRead(){
    QString res = "";
    while(mTcpSocket->bytesAvailable()>0)
    {
        QByteArray array =mTcpSocket->readAll();
        res.append(array);
    }
    QStringList list = res.split("&", Qt::SkipEmptyParts);
    int r = list.size();
    mTcpSocket->write(" ");
    if (r >= 2) {
        QString login = list.at(0);
        QString password = list.at(1);
        mTcpSocket->write(login.toUtf8());
        mTcpSocket->write(" ");
        mTcpSocket->write(password.toUtf8());
    }
    else {
        mTcpSocket->write(res.toUtf8());
    }
}

void MyTcpServer::slotClientDisconnected(){
    mTcpSocket->close();
}
