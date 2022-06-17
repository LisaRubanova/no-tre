#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include "authform.h"
#include "add_group.h"
#include "form_task.h"
#include "form_statistic.h"
#include "form_statistic_teacher.h"
#include "wrong_credentials.h"
#include "cannot_change.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow конструктор, открытие формы
     * @param parent
     */
    MainWindow(QWidget *parent = nullptr);
    /**
     * @brief закрытие формы
     */
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

    /**
     * @brief on_pushButton_stat_clicked переход к статистике
    */
    void on_pushButton_stat_clicked();
    /**
     * @brief change_color_button_1 изменение цвета кнопки на зеленый для задания 1
     */
    void change_color_button_1();
    /**
     * @brief change_color_button_2 изменение цвета кнопки на зеленый для задания 2
     */
    void change_color_button_2();
    /**
     * @brief change_color_button_3 изменение цвета кнопки на зеленый для задания 3
     */
    void change_color_button_3();

    /**
     * @brief n_change_color_button_1 изменение цвета кнопки на красный для задания 1
     */
    void n_change_color_button_1();
    /**
     * @brief n_change_color_button_2 изменение цвета кнопки на красный для задания 2
     */
    void n_change_color_button_2();
    /**
     * @brief n_change_color_button_3 изменение цвета кнопки на красный для задания 3
     */
    void n_change_color_button_3();
    //void check_show();
    /**
     * @brief s1 постепенное формирование полной статистики
     */
    void s1();
    /**
     * @brief s2 постепенное формирование полной статистики
     */
    void s2();
    /**
     * @brief ny1 постепенное формирование полной статистики
     */
    void ny1();
    /**
     * @brief ny2 постепенное формирование полной статистики
     */
    void ny2();
    /**
     * @brief n_s1 постепенное формирование полной статистики
     */
    void n_s1();
    /**
     * @brief n_s2 постепенное формирование полной статистики
     */
    void n_s2();

    /**
     * @brief teacher формирует основное окно для преподавателя
     */
    void teacher();
    /**
     * @brief student формирует основное окно для студента
     */
    void student();

    void on_pushButton_new_group_clicked();

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

    Form_statistic_teacher * stat_t;
    add_group *n_group;
};
#endif // MAINWINDOW_H
