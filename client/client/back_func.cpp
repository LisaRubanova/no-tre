#include "back_func.h"
#include <QDebug>

void auth(QString log, QString pass) {
    QString res = "auth&" + log + "&" + pass;
    qDebug() << res;
}

void reg(QString log, QString pass, QString email){
    QString res = "reg&" + log + "&" + pass + "&" + email;
    qDebug() << res;
}

void upd_stat(int n, QString upd){
    QString res = "updStat&" + QString::number(n) + "&" + upd;
    qDebug() << res;
}



QString solve_task1(QString input){
    return "ans1";
}

QString solve_task2(QString input){
    return "ans2";
}

QString solve_task3(QString input){
    return "ans3";
}



QString gen_text_for_task1(QString input){
    return "task1 " + input;
}

QString gen_text_for_task2(QString input){
    return "task2 " + input;
}

QString gen_text_for_task3(QString input){
    return "task3 " + input;
}



QString gen_task1(){
    return "01010";
}

QString gen_task2(){
    return "02020";
}

QString gen_task3(){
    return "03030";
}



void check_task(int task_num, QString ans, QString input){
    QString solution = "";
    switch(task_num) {
    case 1:
        solution = solve_task1(input);
        break;
    case 2:
        solution = solve_task2(input);
        break;
    case 3:
        solution = solve_task3(input);
        break;
    }

     if(ans == solution)
         upd_stat(task_num, "+");
    else
         upd_stat(task_num, "-");

}



