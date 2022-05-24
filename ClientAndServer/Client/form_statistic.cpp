#include "form_statistic.h"
#include "back_func.h"
#include "ui_form_statistic.h"


form_statistic::form_statistic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_statistic)
{
    ui->setupUi(this);
    get_stat(1);
    connect(client::getInstance(),&client::solved_1, this, &form_statistic::task1);
    connect(client::getInstance(),&client::solved_2, this, &form_statistic::task2);
    connect(client::getInstance(),&client::solved_3, this, &form_statistic::task3);

    connect(client::getInstance(),&client::not_solved_1, this, &form_statistic::n_task1);
    connect(client::getInstance(),&client::not_solved_2, this, &form_statistic::n_task2);
    connect(client::getInstance(),&client::not_solved_3, this, &form_statistic::n_task3);
    ui->label_name->setText("Male");
    ui->label_task_1->setText("-");
    ui->label_task_2->setText("-");
    ui->label_task_3->setText("-");
}

void form_statistic::zero_step(){
    get_stat(1);
}
//up change color button
void form_statistic::task1(){
    ui->label_task_1->setText("+");
    get_stat(2);
}

void form_statistic::task2(){
    ui->label_task_2->setText("+");
    get_stat(3);
}

void form_statistic::task3(){
    ui->label_task_3->setText("+");
}

void form_statistic::n_task1(){
    ui->label_task_1->setText("-");
    get_stat(2);
}

void form_statistic::n_task2(){
    ui->label_task_2->setText("-");
    get_stat(3);
}

void form_statistic::n_task3(){
    ui->label_task_3->setText("-");
}


form_statistic::~form_statistic()
{
    delete ui;
}


void form_statistic::set_stat(QString status){
    int stat_num = 0;
    status  == "teacher" ? stat_num = 1 : stat_num = 2;
    switch(stat_num){
    case 1:

        break;
    case 2:
        ui->label_name->setVisible(false);
        ui->label->setVisible(false);
        break;
    }


}

