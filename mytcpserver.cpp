#include "mytcpserver.h"
#include "myfunctions.h"
#include "myfunctions.cpp"
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QCoreApplication>

#include <QList>

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

        QTcpSocket* mTcpSocket = mTcpServer->nextPendingConnection();
        list.push_back(mTcpSocket);

        mTcpSocket->write("Hello, World!!! I am echo server!\r\n");
        connect(mTcpSocket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
        connect(mTcpSocket,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);
   // }
}

void MyTcpServer::slotServerRead(){
    QTcpSocket* mTcpSocket = (QTcpSocket*)sender();

    QString res = "";
    while(mTcpSocket->bytesAvailable()>0)
    {
        QByteArray array =mTcpSocket->readAll();
        res.append(array);
    }
    mTcpSocket->write(parsing(res).toUtf8());
}

void MyTcpServer::slotClientDisconnected(){
   // mTcpSocket->close();
    QTcpSocket* mTcpSocket = (QTcpSocket*)sender();
    list.removeAt(list.indexOf(mTcpSocket));
}
