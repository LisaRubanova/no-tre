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
    /**
     * @brief get_stat
     * @param task_num
     * @return
     */
    QString get_stat (QString task_num);
    /**
     * @brief encrypt
     * @param toEncrypt
     * @param key
     * @return зашифрованные данные
     */
    QString encrypt(QString toEncrypt, quint32 key);
    /**
     * @brief decrypt
     * @param toDecrypt
     * @param key
     * @return расшифрованные данные
     */
    QString decrypt(QString toDecrypt, quint32 key);
    /**
     * @brief add_group
     * @param group_num
     * @param log_p1
     * @param log_p2
     * @param log_p3
     * @param log_p4
     * @param log_p5
     * @param log_p6
     * @param log_p7
     * @param log_p8
     * @param log_p9
     * @param teacher
     * @return создание группы и добавление в группу логины
     */
    QString add_group(QString group_num, QString log_p1, QString log_p2, QString log_p3,
                      QString log_p4, QString log_p5, QString log_p6, QString log_p7,
                      QString log_p8, QString log_p9, QString teacher);
    /**
     * @brief get_login
     * @param name
     * @param surname
     * @return
     */
    QString get_login(QString name, QString surname);
    /**
     * @brief check_access
     * @param group_num
     * @return ответ о том, есть ли такая группа уже или нет
     */
    QString check_access(QString group_num);
    /**
     * @brief get_info
     * @param group
     * @return возвращает имя, фамилия и заадания
     */
    QString get_info(QString group);
    /**
     * @brief get_teacher
     * @return
     */
    QString get_teacher();
    /**
     * @brief get_student
     * @return
     */
    QString get_student();
    /**
     * @brief get_group
     * @return
     */
    QString get_group();
    /**
     * @brief check_student
     * @param login
     * @return отвечает есть ли такой стулент уже или нет
     */
    QString check_student(QString login);
};

#endif // MYFUNCTIONS_H
