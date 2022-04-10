#ifndef AUTHFORM_H
#define AUTHFORM_H

#include <QWidget>
#include "back_func.h"

namespace Ui {
class AuthForm;
}

class AuthForm : public QWidget
{
    Q_OBJECT

public:
    explicit AuthForm(QWidget *parent = nullptr);
    ~AuthForm();

private slots:
    void on_pushButton_reg_clicked();

    void on_pushButton_ok_clicked();
signals:
    void logged_in();

private:
    Ui::AuthForm *ui;
};

#endif // AUTHFORM_H
