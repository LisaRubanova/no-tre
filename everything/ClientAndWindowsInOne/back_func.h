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
/**
 * @brief get_log вывод данных пользователя
 * @param name
 * @param surname
 */
void get_log(QString name, QString surname);
/**
 * @brief get_stat вывод статуса в кабинете пользователя
 * @param n - количество набранных баллов
 */
void get_stat(int n);
/**
 * @brief new_group добавление группы
 * @param group_num
 * @param n1 - Имя
 * @param s1 - Фамилия
 * @param n2
 * @param s2
 * @param n3
 * @param s3
 * @param n4
 * @param s4
 * @param n5
 * @param s5
 * @param n6
 * @param s6
 * @param n7
 * @param s7
 * @param n8
 * @param s8
 * @param n9
 * @param s9
 */
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

/**
 * @brief check_access проверка доступа преподавателя к группе
 * @param group_num
 */
void check_access(QString group_num);
/**
 * @brief get_info получение информации по группе
 * @param group
 */
void get_info(QString group);

/**
 * @brief get_student получение инфрмации о студенте
 */
void get_student();
/**
 * @brief get_teacher получение информации о преподавателе
 */
void get_teacher();
/**
 * @brief get_teacher получение номера группы
 */
void get_group();

#endif // BACK_FUNC_H
