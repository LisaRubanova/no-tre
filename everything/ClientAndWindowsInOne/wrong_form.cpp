#include "wrong_form.h"
#include "ui_wrong_form.h"
/**
 * @brief wrong_form::wrong_form конструктор, создание формы
 * @param parent
 */
wrong_form::wrong_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wrong_form)
{
    ui->setupUi(this);
}
/**
 * @brief wrong_form::~wrong_form деструктор, закрытие формы
 */
wrong_form::~wrong_form()
{
    delete ui;
}
/**
 * @brief wrong_form::on_pushButton_clicked скрытие формы
 */
void wrong_form::on_pushButton_clicked()
{
    hide();
}
/**
 * @brief wrong_form::on_pushButton_2_clicked переход к регистрации
 */
void wrong_form::on_pushButton_2_clicked()
{
    hide();
    emit registration();
}

