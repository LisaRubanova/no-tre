#include "wrong_credentials.h"
#include "ui_wrong_credentials.h"

wrong_credentials::wrong_credentials(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wrong_credentials)
{
    //auth_form = new AuthForm;
    ui->setupUi(this);
}

wrong_credentials::~wrong_credentials()
{
    delete ui;
}

void wrong_credentials::on_commandLinkButton_clicked()
{
    hide();
    emit registration();
    //auth_form->show();
    //auth_form->on_pushButton_reg_clicked();
}


void wrong_credentials::on_pushButton_clicked()
{
    hide();
}

