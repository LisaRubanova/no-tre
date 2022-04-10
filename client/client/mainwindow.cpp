#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auth_f = new AuthForm;
    task_f = new Form_task;
    auth_f->show();
    connect(auth_f, &AuthForm::logged_in, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_task1_clicked()
{
    task_f->set_task(1);
    task_f->show();
}

void MainWindow::on_pushButton_task2_clicked()
{
    task_f->set_task(2);
    task_f->show();
}

void MainWindow::on_pushButton_task3_clicked()
{
    task_f->set_task(3);
    task_f->show();
}

void MainWindow::on_pushButton_exit_clicked()
{
    close();
}

void MainWindow::on_actionTask1_triggered()
{
    on_pushButton_task1_clicked();
}


void MainWindow::on_actionTask2_triggered()
{
    on_pushButton_task2_clicked();
}

void MainWindow::on_actionTask3_triggered()
{
    on_pushButton_task3_clicked();
}

void MainWindow::on_actionExit_2_triggered()
{
    on_pushButton_exit_clicked();
}


