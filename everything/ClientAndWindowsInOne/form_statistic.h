#ifndef FORM_STATISTIC_H
#define FORM_STATISTIC_H

#include "qobjectdefs.h"
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QWidget>

namespace Ui {
class form_statistic;
}

class form_statistic : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief form_statistic конструктор, открытие формы
     * @param parent
     */
    explicit form_statistic(QWidget *parent = nullptr);
    /**
     * @brief form_statistic::~form_statistic закрытие окна
     */
    ~form_statistic();

    void set_stat(QString status);
    /**
     * @brief task1 запись положительного результата решения задания 1
     */
    void task1();
    /**
     * @brief task2 запись положительного результата решения задания 2
     */
    void task2();
    /**
     * @brief task3 запись положительного результата решения задания 3
     */
    void task3();
    /**
     * @brief n_task1 запись отрицательного результата решения задания 1
     */
    void n_task1();
    /**
     * @brief n_task2 запись отрицательного результата решения задания 2
     */
    void n_task2();
    /**
     * @brief n_task3 запись отрицательного результата решения задания 3
     */
    void n_task3();
    /**
     * @brief put_student установление имени и фамилии студента
     * @param stud
     */
    void put_student(QString stud);
    /**
     * @brief put_teacher установление имени и фамилии преподавателя
     * @param teach
     */
    void put_teacher(QString teach);
    /**
     * @brief put_group установление номера группы
     * @param gr
     */
    void put_group(QString gr);

private:
    Ui::form_statistic *ui;
};

#endif // FORM_STATISTIC_H
