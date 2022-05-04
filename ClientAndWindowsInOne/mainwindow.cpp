#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    stat_f = new form_statistic;
    auth_f->show();
    connect(auth_f, &AuthForm::logged_in_success, this, &MainWindow::show);
    connect(task_f, &Form_task::solved_1, this, &MainWindow::change_color_button_1);
    connect(task_f, &Form_task::solved_2, this, &MainWindow::change_color_button_2);
    connect(task_f, &Form_task::solved_3, this, &MainWindow::change_color_button_3);
}

void MainWindow::change_color_button_1(){
    ui->pushButton_task1->setStyleSheet("background-color: green");
}

void MainWindow::change_color_button_2(){
    ui->pushButton_task2->setStyleSheet("background-color: green");
}

void MainWindow::change_color_button_3(){
    ui->pushButton_task3->setStyleSheet("background-color: green");
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



void MainWindow::on_pushButton_stat_clicked()
{
   stat_f->show();
}

