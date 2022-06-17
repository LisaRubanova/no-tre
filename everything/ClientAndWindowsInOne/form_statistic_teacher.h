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
    /**
     * @brief Form_statistic_teacher конструктор, создание формы статистики для преподавателя
     * @param parent
     */
    explicit Form_statistic_teacher(QWidget *parent = nullptr);
    /**
     * @brief деструктор, закрытие формы
     */
    ~Form_statistic_teacher();
    /**
     * @brief pars вывод информации о группе в таблицу
     * @param data
     */
    void pars(QString data);

private slots:
    /**
     * @brief on_pushButton_clicked контроль ввода номера группы
     */
    void on_pushButton_clicked();
    /**
     * @brief no_access форма предупреждения, что доступа к группе нет
     */
    void no_access();
    /**
     * @brief show_statistic получение статистики по группе
     */
    void show_statistic();

private:
    Ui::Form_statistic_teacher *ui;
    not_allowed *not_all;
    QString group_num;

};

#endif // FORM_STATISTIC_TEACHER_H
