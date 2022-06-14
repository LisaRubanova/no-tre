#include "wrong_form.h"
#include "ui_wrong_form.h"

wrong_form::wrong_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wrong_form)
{
    ui->setupUi(this);
}

wrong_form::~wrong_form()
{
    delete ui;
}



void wrong_form::on_pushButton_clicked()
{
    hide();
}


void wrong_form::on_pushButton_2_clicked()
{
    hide();
    emit registration();
}

