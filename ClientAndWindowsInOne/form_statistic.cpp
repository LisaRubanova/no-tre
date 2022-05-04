#include "form_statistic.h"
#include "ui_form_statistic.h"


form_statistic::form_statistic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_statistic)
{
    ui->setupUi(this);
    ui->label_name->setText("Mark");
    ui->label_task_1->setText("20");
    ui->label_task_2->setText("90");
    ui->label_task_3->setText("45");
}

form_statistic::~form_statistic()
{
    delete ui;
}
