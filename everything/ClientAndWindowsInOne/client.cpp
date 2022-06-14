#include "client.h"
#include <QDebug>
#include <QCoreApplication>

clientDestroyer::~clientDestroyer(){
    delete p_instance;
}

void clientDestroyer::initialize(client * p){
    p_instance = p;
}

QString client::encrypt(QString toEncrypt){
    quint32 key = 562;
    QByteArray arr(toEncrypt.toUtf8());
    for(int i =0; i<arr.size(); i++)
        arr[i] = arr[i] ^ key;

    return QString::fromLatin1(arr.toBase64());
}

QString client::decrypt(QString toDecrypt)
{
    quint32 key = 562;
    QByteArray arr = QByteArray::fromBase64(toDecrypt.toLatin1());
    for(int i =0; i<arr.size(); i++)
        arr[i] = arr[i] ^ key;

    return QString::fromUtf8(arr);
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

//encrypting and decrypting example with Ceasar/ to show how the encrypting should work

void client::sendToServer(QString message){
    //qDebug() << "encrypted" << encrypt(message).toUtf8();
    mTcpSocket->write(encrypt(message).toUtf8());
    //mTcpSocket->write(message.toUtf8());
}




void client::slotServerRead(){
    QString array = "";
    while(mTcpSocket->bytesAvailable()>0)
    {

        QByteArray res = mTcpSocket->readAll();

        array.append(res);
        array = decrypt(array);
        //mTcpSocket->write(array);
        //qDebug()<< array;
        QStringList list = array.split("&", QString::SplitBehavior::SkipEmptyParts);

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
        else if (array == "1&not solved yet"){
            emit not_yet_1();
        }
        else if (array == "2&not solved yet"){
            emit not_yet_2();
        }
        else if (array == "3&not solved yet"){
            emit not_yet_3();
        }
        else if (array == "allowed"){
            emit allowed();
        }
        else if (array == "not allowed"){
            emit not_allow();
        }
        else if (list.size() > 5){
            emit get_it(array);
        }
        else if (list[0] == "i_student"){
            emit student(list[1]);
        }
        else if (list[0] == "i_teacher"){
            emit teacher(list[1]);
        }
        else if (list[0] == "i_group"){
            emit group(list[1]);
        }
        else if (array == "you cannot change group!"){
            qDebug() << "iuio";
            emit you_cannot();
        }
        else if (array == "one of student exists"){
            emit student_in_group();
        }

    }

}
