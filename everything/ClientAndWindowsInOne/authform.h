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
    /**
     * @brief конструктор, создание формы авторизации, в котором поле для ввода email не показывается
     * @param parent
     */
    explicit AuthForm(QWidget *parent = nullptr);
    /**
     * @brief деструктор, закрытие формы авторизации
     */
    ~AuthForm();
    /**
     * @brief AuthForm::page уточнение того, какая форма будет отображатьс "регистрации"/"авторизации"
     * @param form
     */
    void page(QString form);


private slots:

    //void on_pushButton_reg_clicked();
    /**
     * @brief Функция выполнения авторизации или регистрации (зависит от видимости поля email)
     */
    void on_pushButton_ok_clicked();

    /**
     * @brief AuthForm::success_log_as_student успешный вход для студента
     */
    void success_log_as_student();
    /**
     * @brief AuthForm::success_log_as_student успешный вход для преподавателя
     */
    void success_log_as_teacher();
    /**
     * @brief AuthForm::not_success_log не успешный вход для любого пользователя
     */
    void not_success_log();
    /**
     * @brief AuthForm::success_reg успешная регистрация
     */
    void success_reg();
    /**
     * @brief AuthForm::success_reg не успешная регистрация
     */
    void not_success_reg();
    /**
     * @brief переход на вкладку регистрации
     */
    void on_pushButton_reg_clicked();

    /**
     * @brief AuthForm::on_lineEdit_1log_returnPressed фокуссировка на поле пароля
     */
    void on_lineEdit_1log_returnPressed();

    /**
     * @brief AuthForm::on_lineEdit_2pass_returnPressed вход по энтеру
     */
    void on_lineEdit_2pass_returnPressed();

    /**
     * @brief AuthForm::on_radioButton_student_clicked выбор пункта студент
     * @param checked
     * @return выбран ли пункт или нет
     */
    bool on_radioButton_student_clicked(bool checked);

    /**
     * @brief AuthForm::on_radioButton_teacher_clicked выбор пункта преподаватель
     * @param checked
     * @return выбран ли пункт или нет
     */
    bool on_radioButton_teacher_clicked(bool checked);

    /**
     * @brief AuthForm::on_toolButtonback_to_auth_clicked возрат к форме авторизации со страницы регистрации
     */
    void on_toolButtonback_to_auth_clicked();

    /**
     * @brief AuthForm::on_lineEdit_3email_returnPressed переход по энтеру на поле Имя
     */
    void on_lineEdit_3email_returnPressed();

    /**
     * @brief AuthForm::on_lineEdit_4name_returnPressed переход по энтеру на поле Фамилия
     */
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
    /**
     * @brief AuthForm::clean очищенние полей
     */
    void clean();
    /**
     * @brief AuthForm::send_signal проверка успешности регистрации/авторизации
     * @param type
     */
    void send_signal(QString type);
};

#endif // AUTHFORM_H
