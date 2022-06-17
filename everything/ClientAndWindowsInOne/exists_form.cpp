#include "exists_form.h"
#include "ui_exists_form.h"
/**
 * @brief exists_form::exists_form конструктор, создание формы предупреждения
 * @param parent
 */
exists_form::exists_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::exists_form)
{
    ui->setupUi(this);
}
/**
 * @brief exists_form::~exists_form дескруктор, закрытие формы
 */
exists_form::~exists_form()
{
    delete ui;
}
/**
 * @brief exists_form::on_pushButton_clicked скрыытие формы
 */
void exists_form::on_pushButton_clicked()
{
    hide();
}

