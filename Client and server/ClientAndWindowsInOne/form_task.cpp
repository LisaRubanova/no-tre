#include "form_task.h"
#include "ui_form_task.h"

/**
 * @brief конструктор, создание формы задания
 * @param parent
 */
Form_task::Form_task(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_task)
{
    ui->setupUi(this);

}

/**
 * @brief деструктор, для закрытия формы задания
 */
Form_task::~Form_task()
{
    delete ui;
}

/**
 * @brief переход к проверке задания из формы задания
 */
void Form_task::on_pushButton_ok_clicked()
{
    check_task(task_num, ui->lineEdit_ans->text(), input);

    /*if (check_task(task_num, ui->lineEdit_ans->text(), input)){
        switch(task_num){
        case 1:
            emit solved_1();
            break;
        case 2:
            emit solved_2();
            break;
        case 3:
            emit solved_3();
            break;
        }


    }
    */
    hide();
}

/**
 * @brief выбор задания по номеру
 * @param n - номер задания
 */
void Form_task::set_task(int n){
    task_num = n;
    QString task = "";
    switch(task_num){
    case 1:
        input = gen_task1();
        task = gen_text_for_task1(input);
         ui->lineEdit_ans->setText("");
         ui->textBrowser_ques->setText("SDNF function. Example: \n"
                                       "(x1' & x2' & x3') V (x1 & x2' & x3')");
         //(x1' & x2' & x3') V (x1 & x2' & x3') V (x1 & x2 & x3)
        break;
    case 2:
        input = gen_task2();
        task = gen_text_for_task2(input);
         ui->lineEdit_ans->setText("");
         ui->textBrowser_ques->setText("SKNF function. Example: \n"
                                       "(x1 V x2 V x3') & (x1 V x2' V x3)");
         //(x1 V x2 V x3') & (x1 V x2' V x3) & (x1 V x2' V x3') & (x1' V x2 V x3') & (x1' V x2' V x3)
        break;
    case 3:
        input = gen_task3();
        task = gen_text_for_task3(input);
         ui->lineEdit_ans->setText("");
         ui->textBrowser_ques->setText("Zhegalkin polynomial. Example: \n"
                                       "1 + x3 + x2 + x2&x3 + x1&x2&x3");
         //1 + x3 + x2 + x2&x3 + x1&x2&x3
        break;

    }
    ui->textBrowser_task->setText(task);

}
