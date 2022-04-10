#include "form_task.h"
#include "ui_form_task.h"

Form_task::Form_task(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_task)
{
    ui->setupUi(this);

}

Form_task::~Form_task()
{
    delete ui;
}

void Form_task::on_pushButton_ok_clicked()
{
    check_task(task_num, ui->lineEdit_ans->text(), input);
    hide();
}

void Form_task::set_task(int n){
    task_num = n;
    QString task = "";
    switch(task_num){
    case 1:
        input = gen_task1();
        task = gen_text_for_task1(input);
         ui->lineEdit_ans->setText("");
        break;
    case 2:
        input = gen_task2();
        task = gen_text_for_task2(input);
         ui->lineEdit_ans->setText("");
        break;
    case 3:
        input = gen_task3();
        task = gen_text_for_task3(input);
         ui->lineEdit_ans->setText("");
        break;

    }
    ui->textBrowser_task->setText(task);

}
