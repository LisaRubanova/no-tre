#ifndef AUTHFORM_H
#define AUTHFORM_H
#include "client.h"
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
    /**
     * @brief Функция перехода к регистрации
     */
    void on_pushButton_reg_clicked();
    /**
     * @brief Функция выполнения авторизации или регистрации (зависит от видимости поля email)
     */
    void on_pushButton_ok_clicked();

    void success_log_as_student();
    void success_log_as_teacher();
    void not_success_log();
    void success_reg();
    void not_success_reg();


    void on_lineEdit_log_returnPressed();

    void on_lineEdit_pass_returnPressed();

    bool on_radioButton_student_clicked(bool checked);

    bool on_radioButton_teacher_clicked(bool checked);

signals:
    //void logged_in();
    void logged_in_success_as_teacher();
    void logged_in_success_as_student();
    //void logged_in_fail();//не очень нужен, но вдруг

private:
    /**
     * @brief Форма авторизации
     */
    Ui::AuthForm *ui;
    void clean();
    void send_signal(QString type);
};

#endif // AUTHFORM_H
