#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include "authform.h"
#include "form_task.h"
#include "form_statistic.h"

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
    /**
     * @brief Функция перехода к заданию 1 по клику
     */
    void on_pushButton_task1_clicked();
    /**
     * @brief Функция перехода к заданию 2 по клику
     */
    void on_pushButton_task2_clicked();
    /**
     * @brief Функция перехода к заданию 3 по клику
     */
    void on_pushButton_task3_clicked();
    /**
     * @brief Функция выхода по клику
     */
    void on_pushButton_exit_clicked();

    /**
     * @brief Функция выхода из программы из меню
     */
    void on_actionExit_2_triggered();
    /**
     * @brief Функция перехода к заданию 1 из меню
     */
    void on_actionTask1_triggered();
    /**
     * @brief Функция перехода к заданию 2 из меню
     */
    void on_actionTask2_triggered();
    /**
     * @brief Функция перехода к заданию 3 из меню
     */
    void on_actionTask3_triggered();

    void on_pushButton_stat_clicked();
    void change_color_button_1();
    void change_color_button_2();
    void change_color_button_3();

    void n_change_color_button_1();
    void n_change_color_button_2();
    void n_change_color_button_3();
    //void check_show();
    void s1();
    void s2();
    void n_s1();
    void n_s2();

    void teacher();
    void student();

private:
    /**
     * @brief Форма основного окна
     */
    Ui::MainWindow *ui;
    /**
     * @brief Форма окна автооизации
     */
    AuthForm *auth_f;
    /**
     * @brief Форма окна задания
     */
    Form_task *task_f;

    form_statistic *stat_f;
};
#endif // MAINWINDOW_H
