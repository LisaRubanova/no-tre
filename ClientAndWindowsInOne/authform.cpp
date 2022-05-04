#include "authform.h"
#include "ui_authform.h"

void AuthForm::clean(){
    ui->lineEdit_log->setText("");
    ui->lineEdit_pass->setText("");
}

void AuthForm::send_signal(QString type){
    if (type == "reg"){
        connect(client::getInstance(),&client::registered,this, &AuthForm::success_reg);
        connect(client::getInstance(),&client::user_exists,this, &AuthForm::not_success_reg);
    }
    else if (type == "auth"){
        connect(client::getInstance(),&client::log_in,this, &AuthForm::success_log);
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
    clean();
    ui->radioButton_teacher->setVisible(false);
    ui->radioButton_student->setVisible(false);
    ui->lineEdit_email->setVisible(false);
}

/**
 * @brief деструктор, закрытие формы авторизации
 */
AuthForm::~AuthForm()
{
    delete ui;
}

void AuthForm::success_log()
{
    hide();
    emit logged_in_success();
}

void AuthForm::not_success_log()
{
    clean();
    //emit logged_in_fail();
}

void AuthForm::success_reg()
{
    clean();
    ui->lineEdit_email->setVisible(false);
    ui->radioButton_teacher->setVisible(false);
    ui->radioButton_student->setVisible(false);
    ui->pushButton_reg->setVisible(true);
    //emit reg();
}

void AuthForm::not_success_reg()
{
    clean();
    ui->lineEdit_email->setText("");
    //emit logged_in_fail();
}
/**
 * @brief переход на вкладку регистрации
 */
void AuthForm::on_pushButton_reg_clicked()
{
    clean();
    ui->lineEdit_email->setText("");
    ui->radioButton_teacher->setVisible(true);
    ui->radioButton_student->setVisible(true);
    ui->lineEdit_email->setVisible(true);
    ui->pushButton_reg->setVisible(false);
}

/**
 * @brief выполнение авторизации или регистрации. Зависит от видимости поля email
 */
void AuthForm::on_pushButton_ok_clicked()
{
    QString log = ui->lineEdit_log->text();
    QString pass = ui->lineEdit_pass->text();

    if(ui->lineEdit_email->isVisible()){
        QString mymail = ui->lineEdit_email->text();
        if (log == "" || pass == "" || mymail == ""){
            clean();
            ui->lineEdit_email->setText("");

        }
        else{
            if (&AuthForm::on_radioButton_student_clicked){
                reg(log, pass, mymail, "student");
            }
            else if (&AuthForm::on_radioButton_teacher_clicked){
                reg(log, pass, mymail, "teacher");
            }
            else if (!&AuthForm::on_radioButton_student_clicked && !&AuthForm::on_radioButton_teacher_clicked){
                not_success_reg();
            }
            send_signal("reg");
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

void AuthForm::on_lineEdit_log_returnPressed()
{
    focusNextChild();
}


void AuthForm::on_lineEdit_pass_returnPressed()
{
    QString log = ui->lineEdit_log->text();
    QString pass = ui->lineEdit_pass->text();
    if(ui->lineEdit_email->isVisible()){
        focusNextChild();
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

bool AuthForm::on_radioButton_student_clicked(bool checked)
{
    return checked;
}


bool AuthForm::on_radioButton_teacher_clicked(bool checked)
{
    return checked;
}

