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
void Form_task::clear_all(){
    ui->checkBox_000->setChecked(false);
    ui->checkBox_001->setChecked(false);
    ui->checkBox_010->setChecked(false);
    ui->checkBox_011->setChecked(false);
    ui->checkBox_100->setChecked(false);
    ui->checkBox_101->setChecked(false);
    ui->checkBox_110->setChecked(false);
    ui->checkBox_111->setChecked(false);
}
/**
 * @brief Form_task::on_pushButton_ok_clicked заполнение вектора ответами пользователя и последующая проверка
 */
void Form_task::on_pushButton_ok_clicked()
{
    QVector<QString> answer;
    if (ui->checkBox_000->isChecked())  answer.append(ui->checkBox_000->text());
    if (ui->checkBox_001->isChecked())  answer.append(ui->checkBox_001->text());
    if (ui->checkBox_010->isChecked())  answer.append(ui->checkBox_010->text());
    if (ui->checkBox_011->isChecked())  answer.append(ui->checkBox_011->text());
    if (ui->checkBox_100->isChecked())  answer.append(ui->checkBox_100->text());
    if (ui->checkBox_101->isChecked())  answer.append(ui->checkBox_101->text());
    if (ui->checkBox_110->isChecked())  answer.append(ui->checkBox_110->text());
    if (ui->checkBox_111->isChecked())  answer.append(ui->checkBox_111->text());
    //qDebug() << "answer: " << answer;

    //check_task(task_num, ui->lineEdit_ans->text(), input);

    bool solv = check_task(task_num, answer, input);
    //qDebug() << "sol" << task_num;
    if (solv){
        switch(task_num){
        case 1:
            emit solved_now_1();
            break;
        case 2:
            emit solved_now_2();
            break;
        case 3:
            emit solved_now_3();
            break;
        }
    }
    else if (!solv){
        switch(task_num){
        case 1:
            emit not_solved_now_1();
            break;
        case 2:
            emit not_solved_now_2();
            break;
        case 3:
            emit not_solved_now_3();
            break;
        }
    }

    clear_all();
    hide();
}
/**
 * @brief Form_task::set_variants банк вариантов ответов
 * @param n - номер задания
 */
void Form_task::set_variants(int n){
    switch(n){
    case 1:
        ui->checkBox_000->setText("x1'x2'x3'");
        ui->checkBox_001->setText("x1'x2'x3");
        ui->checkBox_010->setText("x1'x2x3'");
        ui->checkBox_011->setText("x1'x2x3");
        ui->checkBox_100->setText("x1x2'x3'");
        ui->checkBox_101->setText("x1x2'x3");
        ui->checkBox_110->setText("x1x2x3'");
        ui->checkBox_111->setText("x1x2x3");
        break;
    case 2:
        ui->checkBox_000->setText("x1'Vx2'Vx3'");
        ui->checkBox_001->setText("x1'Vx2'Vx3");
        ui->checkBox_010->setText("x1'Vx2Vx3'");
        ui->checkBox_011->setText("x1'Vx2Vx3");
        ui->checkBox_100->setText("x1Vx2'Vx3'");
        ui->checkBox_101->setText("x1Vx2'Vx3");
        ui->checkBox_110->setText("x1Vx2Vx3'");
        ui->checkBox_111->setText("x1Vx2Vx3");
        break;
    case 3:
        ui->checkBox_000->setText("1");
        ui->checkBox_001->setText("x3");
        ui->checkBox_010->setText("x2");
        ui->checkBox_011->setText("x2x3");
        ui->checkBox_100->setText("x1");
        ui->checkBox_101->setText("x1x3");
        ui->checkBox_110->setText("x1x2");
        ui->checkBox_111->setText("x1x2x3");
        break;
        break;
    }
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
        task = "SDNF function. Boolean function:" + gen_text_for_task1(input);
        set_variants(1);
         //ui->lineEdit_ans->setText("");
         //ui->textBrowser_ques->setText("SDNF function. Example: \n"
                                       //"(x1' & x2' & x3') V (x1 & x2' & x3')");
         //(x1' & x2' & x3') V (x1 & x2' & x3') V (x1 & x2 & x3)
        break;
    case 2:
        input = gen_task2();
        task = "SKNF function. Boolean function:" + gen_text_for_task2(input);
        set_variants(2);
         //ui->lineEdit_ans->setText("");
         //ui->textBrowser_ques->setText("SKNF function. Example: \n"
                                       //"(x1 V x2 V x3') & (x1 V x2' V x3)");
         //(x1 V x2 V x3') & (x1 V x2' V x3) & (x1 V x2' V x3') & (x1' V x2 V x3') & (x1' V x2' V x3)
        break;
    case 3:
        input = gen_task3();
        task = "Zhegalkin polynomial. Boolean function:" + gen_text_for_task3(input);
        set_variants(3);
         //ui->lineEdit_ans->setText("");
         //ui->textBrowser_ques->setText("Zhegalkin polynomial. Example: \n"
                                       //"1 + x3 + x2 + x2&x3 + x1&x2&x3");
         //1 + x3 + x2 + x2&x3 + x1&x2&x3
        break;

    }
    ui->textBrowser_task->setText(task);

}
