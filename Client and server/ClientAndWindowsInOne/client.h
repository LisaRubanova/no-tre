#ifndef CLIENT_H
#define CLIENT_H
#pragma once

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QCoreApplication>
#include <QString>
#include <QObject>
#include <QTcpSocket>

//#include "clientfunctions.h"

class client;

class clientDestroyer
{
    private:
        client * p_instance;
    public:
        ~clientDestroyer();
        void initialize(client * p);
};


class client: public QObject
{
    Q_OBJECT
    private:
        static client * p_instance;
        static clientDestroyer destroyer;
        static QTcpSocket * mTcpSocket;
    protected:
         client(QObject *parent = nullptr);
        ~client();

        client(const client& );
        client& operator = (client &);
        friend class clientDestroyer;

    public:
        static client* getInstance();
        //explicit MyTcpServer(QObject *parent = nullptr);
        void sendToServer(QString message);
signals:
    void log_in_as_student();
    void log_in_as_teacher();
    void wrong_credentials();
    void registered();
    void user_exists();
    void solved_1();
    void solved_2();
    void solved_3();
    void not_solved_1();
    void not_solved_2();
    void not_solved_3();
    public slots:
        void slotServerRead();
};

#endif // CLIENT_H

