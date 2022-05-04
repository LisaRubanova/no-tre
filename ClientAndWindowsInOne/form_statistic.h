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

private:
    Ui::form_statistic *ui;
};

#endif // FORM_STATISTIC_H
