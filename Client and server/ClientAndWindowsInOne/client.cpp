#include "client.h"
#include <QDebug>
#include <QCoreApplication>

clientDestroyer::~clientDestroyer(){
    delete p_instance;
}

void clientDestroyer::initialize(client * p){
    p_instance = p;
}

client::client(QObject *parent){
    mTcpSocket = new QTcpSocket(this);
    mTcpSocket->connectToHost("127.0.0.1", 33333);
    connect(mTcpSocket, &QTcpSocket::readyRead, this, &client::slotServerRead);
}

client::~client(){
    mTcpSocket->close();
}

client* client::getInstance(){
    if (!p_instance)
    {
        p_instance = new client();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}

void client::sendToServer(QString message){
    mTcpSocket->write(message.toUtf8());
}

void client::slotServerRead(){
    while(mTcpSocket->bytesAvailable()>0)
    {
        QByteArray array = mTcpSocket->readAll();
    // mTcpSocket->write(array);
        qDebug()<< array;
        if (array == "Welcome! student"){
            emit log_in_as_student();
        }
        else if (array == "Welcome! teacher"){
            emit log_in_as_teacher();
        }
        else if (array == "Wrong username or password! "){
            emit wrong_credentials();
        }
        else if (array == "You have been successfully registered! "){
            emit registered();
        }
        else if (array == "This username is already used!"){
            emit user_exists();
        }
        else if (array == "1&+"){
            emit solved_1();
        }
        else if (array == "2&+"){
            emit solved_2();
        }
        else if (array == "3&+"){
            emit solved_3();
        }
        else if (array == "1&-"){
            emit not_solved_1();
        }
        else if (array == "2&-"){
            emit not_solved_2();
        }
        else if (array == "3&-"){
            emit not_solved_3();
        }
    }
}
