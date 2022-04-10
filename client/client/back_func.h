#ifndef BACK_FUNC_H
#define BACK_FUNC_H
#include <QString>

void auth(QString log, QString pass);
void reg(QString log, QString pass, QString email);
void upd_stat(int n, QString upd);

QString solve_task1(QString input);
QString solve_task2(QString input);
QString solve_task3(QString input);

QString gen_text_for_task1(QString input);
QString gen_text_for_task2(QString input);
QString gen_text_for_task3(QString input);

QString gen_task1();
QString gen_task2();
QString gen_task3();

void check_task(int task_num, QString ans, QString input);









#endif // BACK_FUNC_H
