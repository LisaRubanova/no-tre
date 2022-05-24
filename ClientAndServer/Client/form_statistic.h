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
    explicit form_statistic(QWidget *parent = nullptr);
    ~form_statistic();
    void set_stat(QString status);
    void zero_step();
    void task1();
    void task2();
    void task3();
    void n_task1();
    void n_task2();
    void n_task3();

private:
    Ui::form_statistic *ui;
};

#endif // FORM_STATISTIC_H
