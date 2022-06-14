#ifndef AUTHFORM_H
#define AUTHFORM_H
#include "client.h"
#include <QWidget>
#include "back_func.h"
#include "wrong_form.h"
#include "exists_form.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>
namespace Ui {
class AuthForm;
}

class AuthForm : public QWidget
{
    Q_OBJECT

public:
    explicit AuthForm(QWidget *parent = nullptr);
    ~AuthForm();
    void page(QString form);


private slots:
    /**
     * @brief Функция перехода к регистрации
     */
    //void on_pushButton_reg_clicked();
    /**
     * @brief Функция выполнения авторизации или регистрации (зависит от видимости поля email)
     */
    void on_pushButton_ok_clicked();

    void success_log_as_student();
    void success_log_as_teacher();
    void not_success_log();
    void success_reg();
    void not_success_reg();
    void on_pushButton_reg_clicked();

    void on_lineEdit_1log_returnPressed();

    void on_lineEdit_2pass_returnPressed();

    bool on_radioButton_student_clicked(bool checked);

    bool on_radioButton_teacher_clicked(bool checked);

    void on_toolButtonback_to_auth_clicked();

    void on_lineEdit_3email_returnPressed();

    void on_lineEdit_4name_returnPressed();

    //void on_pushButton_reg_pressed();

    //void on_radioButton_student_clicked();

signals:
    //void logged_in();
    void logged_in_success_as_teacher();
    void logged_in_success_as_student();
    //void reg_student();
    //void reg_teacher();
    //void logged_in_fail();//не очень нужен, но вдруг

private:
    /**
     * @brief Форма авторизации
     */
    Ui::AuthForm *ui;
    wrong_form *wrong_cred;
    exists_form *exists_f;
    void clean();
    void send_signal(QString type);
};

#endif // AUTHFORM_H
