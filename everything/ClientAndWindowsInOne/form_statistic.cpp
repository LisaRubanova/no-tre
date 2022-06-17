#include "form_statistic.h"
#include "back_func.h"
#include "ui_form_statistic.h"

/**
 * @brief form_statistic::form_statistic конструктор, создание формы статистики для студента
 * @param parent
 */
form_statistic::form_statistic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_statistic)
{
    ui->setupUi(this);


    connect(client::getInstance(),&client::solved_1, this, &form_statistic::task1);
    connect(client::getInstance(),&client::solved_2, this, &form_statistic::task2);
    connect(client::getInstance(),&client::solved_3, this, &form_statistic::task3);

    connect(client::getInstance(),&client::not_solved_1, this, &form_statistic::n_task1);
    connect(client::getInstance(),&client::not_solved_2, this, &form_statistic::n_task2);
    connect(client::getInstance(),&client::not_solved_3, this, &form_statistic::n_task3);

    ui->label_task_1->setText("-");
    ui->label_task_2->setText("-");
    ui->label_task_3->setText("-");

    connect(client::getInstance(),&client::student, this, &form_statistic::put_student);
    connect(client::getInstance(),&client::teacher, this, &form_statistic::put_teacher);
    connect(client::getInstance(),&client::group, this, &form_statistic::put_group);
}
/**
 * @brief form_statistic::put_student установление имени и фамилии студента
 * @param stud
 */
void form_statistic::put_student(QString stud){

    ui->label_student->setText(stud);
    get_teacher();
}
/**
 * @brief form_statistic::put_teacher имени и фамилии учителя
 * @param teach
 */
void form_statistic::put_teacher(QString teach){
    ui->label_teacher->setText(teach);
    get_group();
}
/**
 * @brief form_statistic::put_group устанволение группы
 * @param gr
 */
void form_statistic::put_group(QString gr){
    ui->label_group->setText(gr);
    get_stat(1);
}
/**
 * @brief form_statistic::task1 запись положительного результата решения задания 1
 */
void form_statistic::task1(){
    //qDebug() << "2";
    ui->label_task_1->setText("+");
    get_stat(2);

}
/**
 * @brief form_statistic::task2 запись положительного результата решения задания 2
 */
void form_statistic::task2(){
    ui->label_task_2->setText("+");
    get_stat(3);
}
/**
 * @brief form_statistic::task3 запись положительного результата решения задания 3
 */
void form_statistic::task3(){
    ui->label_task_3->setText("+");
}
/**
 * @brief form_statistic::n_task1 запись отрицательного результата решения задания 1
 */
void form_statistic::n_task1(){
    ui->label_task_1->setText("-");
    get_stat(2);

}
/**
 * @brief form_statistic::n_task2 запись отрицательного результата решения задания 2
 */
void form_statistic::n_task2(){
    ui->label_task_2->setText("-");
    get_stat(3);

}
/**
 * @brief form_statistic::n_task3 запись отрицательного результата решения задания 3
 */
void form_statistic::n_task3(){
    ui->label_task_3->setText("-");
}
/**
 * @brief form_statistic::~form_statistic закрытие окна
 */
form_statistic::~form_statistic()
{
    delete ui;
}

/*
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
*/

