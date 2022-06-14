#ifndef FORM_STATISTIC_TEACHER_H
#define FORM_STATISTIC_TEACHER_H
#include "not_allowed.h"
#include <QWidget>
#include <QStringList>
#include <QString>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

namespace Ui {
class Form_statistic_teacher;
}

class Form_statistic_teacher : public QWidget
{
    Q_OBJECT

public:
    explicit Form_statistic_teacher(QWidget *parent = nullptr);
    ~Form_statistic_teacher();
    void pars(QString data);

private slots:
    void on_pushButton_clicked();
    void no_access();
    void show_statistic();

private:
    Ui::Form_statistic_teacher *ui;
    not_allowed *not_all;
    QString group_num;

};

#endif // FORM_STATISTIC_TEACHER_H
