#include "mainwindow.h"
#include "back_func.h"
#include "ui_mainwindow.h"

QString status = "";
/**
 * @brief конструктор, для создания основного окна (tasks, statistics, exit)
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auth_f = new AuthForm;
    task_f = new Form_task;
    stat_t = new Form_statistic_teacher;
    stat_f = new form_statistic;//student
    n_group = new add_group;
    auth_f->show();
    connect(auth_f, &AuthForm::logged_in_success_as_teacher, this, &MainWindow::teacher);
    connect(auth_f, &AuthForm::logged_in_success_as_student, this, &MainWindow::student);

    connect(task_f, &Form_task::solved_now_1, this, &MainWindow::change_color_button_1);
    connect(task_f, &Form_task::solved_now_2, this, &MainWindow::change_color_button_2);
    connect(task_f, &Form_task::solved_now_3, this, &MainWindow::change_color_button_3);

    connect(task_f, &Form_task::not_solved_now_1, this, &MainWindow::n_change_color_button_1);
    connect(task_f, &Form_task::not_solved_now_2, this, &MainWindow::n_change_color_button_2);
    connect(task_f, &Form_task::not_solved_now_3, this, &MainWindow::n_change_color_button_3);

    connect(client::getInstance(),&client::solved_1, this, &MainWindow::s1/*change_color_button_1*/);
    connect(client::getInstance(),&client::solved_2, this, &MainWindow::s2);
    connect(client::getInstance(),&client::solved_3, this, &MainWindow::change_color_button_3);

    connect(client::getInstance(),&client::not_solved_1, this, &MainWindow::n_s1/*change_color_button_1*/);
    connect(client::getInstance(),&client::not_solved_2, this, &MainWindow::n_s2);
    connect(client::getInstance(),&client::not_solved_3, this, &MainWindow::n_change_color_button_3);

    connect(client::getInstance(),&client::not_yet_1, this, &MainWindow::ny1);
    connect(client::getInstance(),&client::not_yet_2, this, &MainWindow::ny2);
}

/**
 * @brief MainWindow::teacher формирует основное окно для учителя
 */
void MainWindow::teacher(){
    MainWindow::show();
    ui->pushButton_new_group->setVisible(true);
    qDebug() << "teacher";
    //get_stat(1);
    status = "teacher";
    //stat_t->show();
}
/**
 * @brief MainWindow::student формирует основное окно для студента
 */
void MainWindow::student(){
    MainWindow::show();
    ui->pushButton_new_group->setVisible(false);
    qDebug() << "student";
    get_stat(1);
    status = "student";
    //stat_f->set_stat("student");
}


/*void MainWindow::check_show(){
    MainWindow::show();
    get_stat(1);
}
*/
//up change color button
/**
 * @brief MainWindow::s1 постепенное формирование полной статистики
 */
void MainWindow::s1(){
    MainWindow::change_color_button_1();
    get_stat(2);
}
/**
 * @brief MainWindow::s2 постепенное формирование полной статистики
 */
void MainWindow::s2(){
    MainWindow::change_color_button_2();
    get_stat(3);
}
/**
 * @brief MainWindow::ny1 постепенное формирование полной статистики
 */
void MainWindow::ny1(){
    get_stat(2);
}
/**
 * @brief MainWindow::ny2 постепенное формирование полной статистики
 */
void MainWindow::ny2(){
    get_stat(3);
}
/**
 * @brief MainWindow::change_color_button_1 изменение цвета кнопки на зеленый для задания 1
 */
void MainWindow::change_color_button_1(){
    ui->pushButton_task1->setStyleSheet("background-color: green");
}
/**
 * @brief MainWindow::change_color_button_2 изменение цвета кнопки на зеленый для задания 2
 */
void MainWindow::change_color_button_2(){
    ui->pushButton_task2->setStyleSheet("background-color: green");
}
/**
 * @brief MainWindow::change_color_button_3 изменение цвета кнопки на зеленый для задания 3
 */
void MainWindow::change_color_button_3(){
    ui->pushButton_task3->setStyleSheet("background-color: green");
}
/**
 * @brief MainWindow::n_s1 постепенное формирование полной статистики
 */
void MainWindow::n_s1(){
    MainWindow::n_change_color_button_1();
    get_stat(2);
}/**
 * @brief MainWindow::n_s2 постепенное формирование полной статистики
 */
void MainWindow::n_s2(){
    MainWindow::n_change_color_button_2();
    get_stat(3);
}
/**
 * @brief MainWindow::n_change_color_button_1 изменение цвета кнопки на красный для задания 1
 */
void MainWindow::n_change_color_button_1(){
    ui->pushButton_task1->setStyleSheet("background-color: red");
}
/**
 * @brief MainWindow::n_change_color_button_2 изменение цвета кнопки на красный для задания 2
 */
void MainWindow::n_change_color_button_2(){
    ui->pushButton_task2->setStyleSheet("background-color: red");
}
/**
 * @brief MainWindow::n_change_color_button_3 изменение цвета кнопки на красный для задания 3
 */
void MainWindow::n_change_color_button_3(){
    ui->pushButton_task3->setStyleSheet("background-color: red");
}

/**
 * @brief деструктор, для закрытия основного окна
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief открытие по клику окна с заданием номер 1
 */
void MainWindow::on_pushButton_task1_clicked()
{
    task_f->set_task(1);
    task_f->show();
}

/**
 * @brief открытие по клику окна с заданием номер 2
 */
void MainWindow::on_pushButton_task2_clicked()
{
    task_f->set_task(2);
    task_f->show();
}

/**
 * @brief открытие по клику окна с заданием номер 3
 */
void MainWindow::on_pushButton_task3_clicked()
{
    task_f->set_task(3);
    task_f->show();
}

/**
 * @brief выход по клику из программы
 */
void MainWindow::on_pushButton_exit_clicked()
{
    close();
}

/**
 * @brief переход к заданию 1 из меню
 */
void MainWindow::on_actionTask1_triggered()
{
    on_pushButton_task1_clicked();
}

/**
 * @brief переход к заданию 2 из меню
 */
void MainWindow::on_actionTask2_triggered()
{
    on_pushButton_task2_clicked();
}

/**
 * @brief переход к заданию 3 из меню
 */
void MainWindow::on_actionTask3_triggered()
{
    on_pushButton_task3_clicked();
}

/**
 * @brief выход из программы через меню
 */
void MainWindow::on_actionExit_2_triggered()
{
    on_pushButton_exit_clicked();
}
/**
 * @brief MainWindow::on_pushButton_stat_clicked переход к статистике
 */
void MainWindow::on_pushButton_stat_clicked()
{
   if (status == "teacher"){
       //qDebug() << "teacher";
       stat_t->show();
   }
   else if (status == "student"){
       //qDebug() << "student";
       get_student();
       stat_f->show();
   }
}
/**
 * @brief MainWindow::on_pushButton_new_group_clicked переход к форме добаления группы
 */
void MainWindow::on_pushButton_new_group_clicked()
{
    n_group->show();
}

