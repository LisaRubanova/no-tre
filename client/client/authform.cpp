#include "authform.h"
#include "ui_authform.h"

AuthForm::AuthForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthForm)
{
    ui->setupUi(this);
    ui->lineEdit_email->setVisible(false);
}

AuthForm::~AuthForm()
{
    delete ui;
}

void AuthForm::on_pushButton_reg_clicked()
{
    ui->lineEdit_log->setText("");
    ui->lineEdit_pass->setText("");
    ui->lineEdit_email->setText("");

    ui->lineEdit_email->setVisible(true);
    ui->pushButton_reg->setVisible(false);
}


void AuthForm::on_pushButton_ok_clicked()
{
    QString log = ui->lineEdit_log->text();
    QString pass = ui->lineEdit_pass->text();
    //check if empty
    //email form

    if(ui->lineEdit_email->isVisible()){
        QString mymail = ui->lineEdit_email->text();
        reg(log, pass, mymail);
        ui->lineEdit_email->setVisible(false);
        ui->pushButton_reg->setVisible(true);
    }else{
        auth(log, pass);
        emit logged_in();
        hide();
    }
}

