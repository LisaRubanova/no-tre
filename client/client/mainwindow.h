#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "authform.h"
#include "form_task.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_task1_clicked();
    void on_pushButton_task2_clicked();
    void on_pushButton_task3_clicked();
    void on_pushButton_exit_clicked();


    void on_actionExit_2_triggered();

    void on_actionTask1_triggered();

    void on_actionTask2_triggered();

    void on_actionTask3_triggered();

private:
    Ui::MainWindow *ui;
    AuthForm *auth_f;
    Form_task *task_f;
};
#endif // MAINWINDOW_H
