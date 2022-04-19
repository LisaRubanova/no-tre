#include "mytcpserver.h"
#include "myfunctions.h"
#include "myfunctions.cpp"
//#include "database.h"
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QList>
#include <QCoreApplication>

//#include <QSqlDatabase>
//#include <QSqlQuery>
//#include <QSqlError>
//#include <QSqlRecord>


/**
 * @brief деструктор для закрытия соединения
 */
MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    //QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("D:/ProgTech/DataBase/build-DataBase-Desktop_Qt_6_2_3_MSVC2019_64bit-Debug/Test1.db");
    //if (db.open()){
    //    db.close();
    //    qDebug() << "closed";
    //}
    //else{
    //    qDebug() << "already closed";
    //}
    //server_status=0;
}

/**
 * @brief конструктор для запуска сервера
 * @param parent
 */
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

    //QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("D:/ProgTech/DataBase/build-DataBase-Desktop_Qt_6_2_3_MSVC2019_64bit-Debug/Test1.db");
    //if (!db.open()){
    //    qDebug() << "nope";
    //}
    //else{
    //    qDebug() << "ok";
    //}
}


/**
 * @brief создание слота для нового подключения
 */
void MyTcpServer::slotNewConnection(){
 //   if(server_status==1){
        QTcpSocket* mTcpSocket = mTcpServer->nextPendingConnection();
        list.push_back(mTcpSocket);

        mTcpSocket->write("Hello, World!!! I am echo server!\r\n");
        connect(mTcpSocket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
        connect(mTcpSocket,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);
   // }
}

/**
 * @brief чтение строки от пользователя
 */
void MyTcpServer::slotServerRead(){
    myfunctions f;
    QTcpSocket* mTcpSocket = (QTcpSocket*)sender();
    QString res = "";
    while(mTcpSocket->bytesAvailable()>0)
    {
        QByteArray array =mTcpSocket->readAll();
        res.append(array);
    }
    mTcpSocket->write(f.parsing(res).toUtf8());

}

/**
 * @brief возможность подключения нескольких клиентов
 */
void MyTcpServer::slotClientDisconnected(){
    mTcpSocket->close();
    qDebug() << list.size();
    mTcpSocket->close();
    QTcpSocket* mTcpSocket = (QTcpSocket*)sender();
    list.removeAt(list.indexOf(mTcpSocket));
}
