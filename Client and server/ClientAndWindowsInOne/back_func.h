#ifndef BACK_FUNC_H
#define BACK_FUNC_H
#include "client.h"
#include <QString>
#include <QtNetwork>
/**
 * @brief Функция авторизации по логину и паролю от пользователя
 * @param log
 * @param pass
 */
void auth(QString log, QString pass);
/**
 * @brief Функция регистрации по логину, паролю и почте от пользователя
 * @param log
 * @param pass
 * @param email
 */

void reg(QString log, QString pass, QString email, QString status, QString name, QString surname);
/**
 * @brief Функция обновления статистики после решения заданий
 * @param n - номер задания
 * @param upd
 */
void upd_stat(int n, QString upd);

void get_log(QString name, QString surname);
void get_stat(int n);
void new_group(QString group_num, QString n1, QString s1, QString n2, QString s2, QString n3, QString s3, QString n4, QString s4,
               QString n5, QString s5, QString n6, QString s6, QString n7, QString s7, QString n8, QString s8,
               QString n9, QString s9);

/**
 * @brief Функция автоматического решения задачи 1
 * @param input - вектор булевых значений - условие задачи
 * @return Правильный ответ на задание 1
 */
QVector<QString> solve_task1(QString input);
/**
 * @brief Функция автоматического решения задачи 2
 * @param input - вектор булевых значений - условие задачи
 * @return Правильный ответ на задание 2
 */
QVector<QString> solve_task2(QString input);
/**
 * @brief Функция автоматического решения задачи 3
 * @param input - вектор булевых значений - условие задачи
 * @return Правильный ответ на задание 3
 */
QVector<QString> solve_task3(QString input);

/**
 * @brief Функция генерации задания для номера 1
 * @param input
 * @return Текст задания 1
 */

QString gen_text_for_task1(QString input);
/**
 * @brief Функция генерации задания для номера 2
 * @param input
 * @return Текст задания 2
 */
QString gen_text_for_task2(QString input);
/**
 * @brief Функция генерации задания для номера 3
 * @param input
 * @return Текст задания 3
 */
QString gen_text_for_task3(QString input);

/**
 * @brief Функция рандомной генерации вектора булевых значений
 * @return Вектор булевых значений для задания 1
 */
QString gen_task1();
/**
 * @brief Функция рандомной генерации вектора булевых значений
 * @return Вектор булевых значений для задания 2
 */
QString gen_task2();
/**
 * @brief Функция рандомной генерации вектора булевых значений
 * @return Вектор булевых значений для задания 3
 */
QString gen_task3();

/**
 * @brief Функция проверки правильности решения задания
 * @param task_num
 * @param ans
 * @param input
 */
bool check_task(int task_num, QVector<QString> ans, QString input);

void check_access(QString group_num);
void get_info(QString group);


void get_student();
void get_teacher();
void get_group();

#endif // BACK_FUNC_H
