#ifndef FORM_TASK_H
#define FORM_TASK_H

#include "back_func.h"
#include <QWidget>

namespace Ui {
class Form_task;
}

class Form_task : public QWidget
{
    Q_OBJECT

public:
    explicit Form_task(QWidget *parent = nullptr);
    ~Form_task();

    void set_task(int n);

private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::Form_task *ui;
    int task_num;
    QString input;
};

#endif // FORM_TASK_H
