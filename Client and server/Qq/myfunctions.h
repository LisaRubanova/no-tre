#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QCryptographicHash>
#include "singleton_db.h"


class myfunctions
{
private:
    QSqlDatabase *db;
public:
    myfunctions();
    ~myfunctions();
    //katya
    /**
     * @brief Функция parsing считывает строку формата func&username&password&email&status,
     * затем вызывает функцию и передает параметры, указанные в строке
     * @param data_from_client, строка формата func&username&password&email
     * @return статус вызванной функции
     */
    QString parsing(QString data_from_client);
    /**
     * @brief Функция reg отвечает за регистрацию нового пользователя
     * @param login
     * @param password
     * @param email
     * @return статус регистрации
     */
    //lisa
    QString reg(QString login, QString password, QString email, QString status, QString name, QString surname);
    /**
     * @brief Функция auth отвечает за вход в аккаунт пользователя
     * @param login
     * @param password
     * @return статус входа
     */
    //arceniy
    QString auth(QString login, QString password);
    /**
     * @brief Функция updStat отвечает за обновление статуса решения задачи
     * @param name
     * @param task_num
     * @param status_of_task
     * @return
     */
    QString updStat(QString name, QString task_num, QString status_of_task);
    QString get_stat (QString task_num);
    QString encrypt(QString toEncrypt, quint32 key);
    QString decrypt(QString toDecrypt, quint32 key);
    QString add_group(QString group_num, QString log_p1, QString log_p2, QString log_p3,
                      QString log_p4, QString log_p5, QString log_p6, QString log_p7,
                      QString log_p8, QString log_p9, QString teacher);
    QString get_login(QString name, QString surname);
    QString check_access(QString group_num);
    QString get_info(QString group);
    QString get_teacher();
    QString get_student();
    QString get_group();
    QString check_student(QString login);
};

#endif // MYFUNCTIONS_H
