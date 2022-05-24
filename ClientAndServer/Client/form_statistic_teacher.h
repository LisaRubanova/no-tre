#ifndef FORM_STATISTIC_TEACHER_H
#define FORM_STATISTIC_TEACHER_H

#include <QWidget>

namespace Ui {
class Form_statistic_teacher;
}

class Form_statistic_teacher : public QWidget
{
    Q_OBJECT

public:
    explicit Form_statistic_teacher(QWidget *parent = nullptr);
    ~Form_statistic_teacher();

private:
    Ui::Form_statistic_teacher *ui;
};

#endif // FORM_STATISTIC_TEACHER_H
