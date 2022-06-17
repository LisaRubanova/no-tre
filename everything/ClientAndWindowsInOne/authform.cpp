#include "authform.h"
#include "ui_authform.h"
/**
 * @brief AuthForm::clean очищенние полей
 */
void AuthForm::clean(){
    ui->lineEdit_1log->setText("");
    ui->lineEdit_2pass->setText("");
    ui->lineEdit_3email->setText("");
    ui->lineEdit_4name->setText("");
    ui->lineEdit_5surname->setText("");
}
/**
 * @brief AuthForm::page уточнение того, какая форма будет отображатьс "регистрации"/"авторизации"
 * @param form
 */
void AuthForm::page(QString form){
    ui->lineEdit_1log->setFocus(Qt::TabFocusReason);
    if (form == "reg"){
        ui->lineEdit_1log->setVisible(true);
        ui->lineEdit_2pass->setVisible(true);
        ui->lineEdit_3email->setVisible(true);
        ui->lineEdit_4name->setVisible(true);
        ui->lineEdit_5surname->setVisible(true);

        ui->radioButton_teacher->setVisible(true);
        ui->radioButton_student->setVisible(true);
        ui->label_note->setVisible(true);
        ui->toolButtonback_to_auth->setVisible(true);
        ui->pushButton_reg->setVisible(false);
        ui->pushButton_ok->setVisible(true);
    }
    else if (form == "auth"){
        ui->lineEdit_1log->setVisible(true);
        ui->lineEdit_2pass->setVisible(true);
        ui->lineEdit_3email->setVisible(false);
        ui->lineEdit_4name->setVisible(false);
        ui->lineEdit_5surname->setVisible(false);

        ui->radioButton_teacher->setVisible(false);
        ui->radioButton_student->setVisible(false);
        ui->label_note->setVisible(false);

        ui->toolButtonback_to_auth->setVisible(false);
        ui->pushButton_reg->setVisible(true);
        ui->pushButton_ok->setVisible(true);
    }
}
/**
 * @brief AuthForm::send_signal проверка успешности регистрации/авторизации
 * @param type
 */
void AuthForm::send_signal(QString type){
    if (type == "reg"){
        connect(client::getInstance(),&client::registered,this, &AuthForm::success_reg);
        connect(client::getInstance(),&client::user_exists,this, &AuthForm::not_success_reg);
    }
    else if (type == "auth"){
        connect(client::getInstance(),&client::log_in_as_student,this, &AuthForm::success_log_as_student);
        connect(client::getInstance(),&client::log_in_as_teacher,this, &AuthForm::success_log_as_teacher);
        //connect(client::getInstance(),&client::log_in,this, &AuthForm::success_log);
        connect(client::getInstance(),&client::wrong_credentials,this, &AuthForm::not_success_log);
    }
}
/**
 * @brief конструктор, создание формы авторизации, в котором поле для ввода email не показывается
 * @param parent
 */
AuthForm::AuthForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthForm)
{
    ui->setupUi(this);
    wrong_cred = new wrong_form;
    exists_f = new exists_form;
    clean();
    page("auth");
}

/**
 * @brief деструктор, закрытие формы авторизации
 */
AuthForm::~AuthForm()
{
    delete ui;
}

/**
 * @brief AuthForm::success_log_as_student успешный вход для студента
 */
void AuthForm::success_log_as_student()
{
    hide();
    //get_student();
    emit logged_in_success_as_student();
}
/**
 * @brief AuthForm::success_log_as_teacher успешный вход для преподавателя
 */
void AuthForm::success_log_as_teacher()
{
    hide();
    emit logged_in_success_as_teacher();
}

/**
 * @brief AuthForm::not_success_log не успешный вход для любого пользователя
 */
void AuthForm::not_success_log()
{
    clean();
    wrong_cred->show();
    connect(wrong_cred, &wrong_form::registration, this, &AuthForm::on_pushButton_reg_clicked);
    //emit logged_in_fail();
}
/**
 * @brief AuthForm::success_reg успешная регистрация
 */
void AuthForm::success_reg()
{
    clean();
    page("auth");
    //emit reg();
}
/**
 * @brief AuthForm::not_success_reg не успешная регистарция
 */
void AuthForm::not_success_reg()
{
    clean();
    exists_f->show();
    //emit logged_in_fail();
}
/**
 * @brief переход на вкладку регистрации
 */
void AuthForm::on_pushButton_reg_clicked()
{
    clean();
    page("reg");
}

/**
 * @brief выполнение авторизации или регистрации. Зависит от видимости поля email
 */
void AuthForm::on_pushButton_ok_clicked()
{
    QString log = ui->lineEdit_1log->text();
    QString pass = ui->lineEdit_2pass->text();
    if(ui->lineEdit_3email->isVisible()){

        QString mymail = ui->lineEdit_3email->text();
        QRegularExpression re("@"".");
        QRegularExpressionMatch match = re.match(mymail);
        if(match.hasMatch()){
            QString name = ui->lineEdit_4name->text();
            QString surname = ui->lineEdit_5surname->text();
            if (log == "" || pass == "" || mymail == "" || name == "" || surname == ""
                    ||log.length() > 100 || pass.length() > 100 || mymail.length() > 100 || name.length() > 100 || surname.length() > 100){
                clean();
            }
            else{
                //connect (this, reg_student(), this, reg);
                if (ui->radioButton_teacher->isChecked()){
                    reg(log, pass, mymail, "teacher", name, surname);
                }
                else if (ui->radioButton_student->isChecked()){
                    reg(log, pass, mymail, "student", name, surname);
                }
                else if (!&AuthForm::on_radioButton_student_clicked && !&AuthForm::on_radioButton_teacher_clicked){
                    not_success_reg();
                }
                send_signal("reg");
            }
        }
        else{
            clean();
        }

    }else{
        if (log == "" || pass == ""){
            clean();
        }
        else{
            auth(log, pass);
            send_signal("auth");
        }
    }
}
/**
 * @brief AuthForm::on_lineEdit_1log_returnPressed фокуссировка на поле пароля
 */
void AuthForm::on_lineEdit_1log_returnPressed()
{
    ui->lineEdit_2pass->setFocus(Qt::TabFocusReason);
}

/**
 * @brief AuthForm::on_lineEdit_2pass_returnPressed вход по энтеру
 */
void AuthForm::on_lineEdit_2pass_returnPressed()
{

    QString log = ui->lineEdit_1log->text();
    QString pass = ui->lineEdit_2pass->text();
    if(ui->lineEdit_3email->isVisible()){
        ui->lineEdit_3email->setFocus(Qt::TabFocusReason);
    }else{
        if (log == "" || pass == ""){
            clean();
        }
        else{
            auth(log, pass);
            send_signal("auth");
        }
    }
}
/**
 * @brief AuthForm::on_radioButton_student_clicked выбор пункта студент
 * @param checked
 * @return выбран ли пункт или нет
 */
bool AuthForm::on_radioButton_student_clicked(bool checked)
{
    return checked;
}

/**
 * @brief AuthForm::on_radioButton_teacher_clicked выбор пункта преподаватель
 * @param checked
 * @return выбран ли пункт или нет
 */
bool AuthForm::on_radioButton_teacher_clicked(bool checked)
{
    return checked;
}

/**
 * @brief AuthForm::on_toolButtonback_to_auth_clicked возрат к форме авторизации со страницы регистрации
 */
void AuthForm::on_toolButtonback_to_auth_clicked()
{
    clean();
    page("auth");
}

/**
 * @brief AuthForm::on_lineEdit_3email_returnPressed переход по энтеру на поле Имя
 */
void AuthForm::on_lineEdit_3email_returnPressed()
{
    ui->lineEdit_4name->setFocus(Qt::TabFocusReason);
}

/**
 * @brief AuthForm::on_lineEdit_4name_returnPressed переход по энтеру на поле Фамилия
 */
void AuthForm::on_lineEdit_4name_returnPressed()
{
    ui->lineEdit_5surname->setFocus(Qt::TabFocusReason);
}

