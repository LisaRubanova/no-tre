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
#include <QStringList>

//#include "form_statistic_teacher.h"

class client;

class clientDestroyer
{
    private:
        client * p_instance;
    public:
        /**
         * @brief clientDestroyer::~clientDestroyer деструктор
         */
        ~clientDestroyer();
        /**
        * @brief clientDestroyer::initialize копирует ссылку на объект класса client
         * для последующей работы с ней в классе clientDestroyer
        * @param p
        */
        void initialize(client * p);
};


class client: public QObject
{
    Q_OBJECT
    private:
        static client * p_instance;
        static clientDestroyer destroyer;
        static QTcpSocket * mTcpSocket;
        //Form_statistic_teacher *f_t;

    protected:
        /**
         * @brief client::client подключение клиента
         * @param parent
         */
         client(QObject *parent = nullptr);
         /**
          * @brief client::~client отключение клиента
          */
        ~client();

        client(const client& );
        client& operator = (client &);
        friend class clientDestroyer;
        /**
         * @brief client::encrypt
         * @param toEncrypt
         * @return зашифрованные данные
         */
        QString encrypt(QString toEncrypt);
        /**
         * @brief client::decrypt
         * @param toDecrypt
         * @return расшифрованные данные
         */
        QString decrypt(QString toDecrypt);

    public:
        /**
         * @brief client::getInstance создание и сохранение ссылки в аргумент p_instance
         * @return
         */
        static client* getInstance();
        //explicit MyTcpServer(QObject *parent = nullptr);
        /**
         * @brief client::sendToServer отправка запроса на сервер
         * @param message
         */
        void sendToServer(QString message);
        //QString tell_me();
        //QString info;

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
    void not_yet_1();
    void not_yet_2();
    void not_yet_3();
    void allowed();
    void not_allow();
    void get_it(QString g);
    void group(QString group);
    void teacher (QString teacher);
    void student (QString student);
    void you_cannot();
    void student_in_group();
public slots:
    /**
     * @brief client::slotServerRead получение ответа от сервера
     */
    void slotServerRead();
};

#endif // CLIENT_H

