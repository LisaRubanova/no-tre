#include "back_func.h"
#include <QDebug>
#include <bitset>
#include <vector>

/**
 * @brief авторизация по введенными пользователем паролю и логину
 * @param log
 * @param pass
 */
void auth(QString log, QString pass){
    QString res = "auth&" + log + "&" + pass + "&";
    qDebug() << res;
    client::getInstance()->sendToServer(res);
    //qDebug() << client::getInstance()->slotServerRead();
    //return client::getInstance()->slotServerRead();
}

/**
 * @brief регистрация по введеным пользователем паролю, логину и почте
 * @param log
 * @param pass
 * @param email
 */
void reg(QString log, QString pass, QString email, QString status, QString name, QString surname){
    QString res = "reg&" + log + "&" + pass + "&" + email + "&" + status + "&" + name + "&" + surname + "&";
    qDebug() << res;
    client::getInstance()->sendToServer(res);

}

/**
 * @brief обновление статуса в кабинете пользователя
 * @param n - количество набранных баллов
 * @param upd
 */
void upd_stat(int n, QString upd){
    QString res = "updStat&" + QString::number(n) + "&" + upd + "&";
    qDebug() << res;
    client::getInstance()->sendToServer(res);
}

void get_stat(int n){
    QString res = "getStat&" + QString::number(n) + "&";
    qDebug() << res;
    client::getInstance()->sendToServer(res);
}

void get_log(QString name, QString surname){
    QString res = "get_log&" + name + "&" + surname + "&";
    qDebug() << res;
    client::getInstance()->sendToServer(res);
}

//&resol&group_num&n1&s1&n2&s2&n3&s3&n4&s4&n5&s5&n6&s6&n7&s7&n8&s8&n9&s9&t_name&t_surname&
void new_group(QString group_num, QString n1, QString s1, QString n2, QString s2, QString n3, QString s3, QString n4, QString s4,
               QString n5, QString s5, QString n6, QString s6, QString n7, QString s7, QString n8, QString s8,
               QString n9, QString s9){
    QString res = "add_group&" + group_num + "&" + n1 + "&" + s1 + "&" + n2 + "&" + s2 + "&" + n3 + "&" + s3 + "&" + n4 + "&" + s4
            + "&" + n5 + "&" + s5 + "&" + n6 + "&" + s6 + "&" + n7 + "&" + s7 + "&" + n8 + "&" + s8 + "&" + n9 + "&" + s9
            + "&";
    qDebug() << res;
    client::getInstance()->sendToServer(res);
}

/**
 * @brief автоматическое решение задания 1
 * @param input
 * @return правильный ответ на задание 1
 */
QString solve_task1(QString input){
    QString answer = "";
    for (int a = 0; a < input.length(); ++a){
        if(input[a] == '1'){
            QString s1 = "(";
            std::bitset<3> b(a);
            int n = 1;
            for (int j = b.size() - 1; j >= 0; j--) {
                b[j] == 0 ? s1 += "x" + QString::number(n) + "' & " : s1 += "x" + QString::number(n) + " & ";
                n++;
            }
            s1 += ")";
            s1.replace(s1.length() - 2, 2, ")");
            for (int i = 0; i < s1.length(); ++i)   if (s1[i] == ')')   s1.replace(i-2, 3, ")");
            answer += s1 + " V ";
        }
    }
    answer.replace(answer.length() - 3, 3, "");
    //qDebug() << answer;
    return answer;
}

/**
 * @brief автоматическое решение задания 2
 * @param input
 * @return правильный ответ на задание 2
 */
QString solve_task2(QString input){
    QString answer = "";
    QVector<QString> con;
    for (int a = 0; a < input.length(); a++) {
        if (input[a] == '0') {
            QString s1 = "(";
            QString s1prot = "";
            std::bitset<3> b(a);
            int n = 1;
            for (int j = b.size()-1; j >= 0; j--) {
                b[j] == 1 ? s1 += "x" + QString::number(n) + "' V " : s1 += "x" + QString::number(n) + " V ";
                b[j] == 1 ? s1prot += "x" + QString::number(n) + "'V" : s1prot += "x" + QString::number(n) + "V";
                n++;
            }
            s1 += ")";
            con.append(s1prot);
            //qDebug() << s1prot;
            s1.replace(s1.length() - 2, 2, ")");
            for (int i = 0; i < s1.length(); ++i) {
                if (s1[i] == ')') {
                    s1.replace(i - 2, 3, ")");
                }
            }
            answer += s1 + " & ";
        }
    }
    answer.replace(answer.length() - 3, 3, "");
    qDebug() << con;
    return answer;
}

/**
 * @brief автоматическое решение задания 3
 * @param input
 * @return правильный ответ на задание 3
 */
QString solve_task3(QString input){
    QString answer;
    std::vector<bool> f;
    for (int i = 0; i < input.length(); ++i){
        input[i] == '1' ? f.push_back(true) : f.push_back(false);
    }

    int s = input.length();

    std::vector<bool> in_use, next, container;
    container.push_back(f.back());
    in_use.swap(f);

    for (int i = 0; i < s; ++i) {

        int s_of_in_use = in_use.size();
        for (int j = s_of_in_use-1; j > 0; --j) {
            bool into = in_use[j] ^ in_use[j - 1];
            next.insert(next.begin(), into);

            if (j == 1) container.push_back(into);
        }
        in_use.swap(next);
        next.clear();
    }

    for (int a = 0; a < container.size(); a++) {

        if (container[a] == true) {

            std::bitset<3> b(a);
            qDebug() << b[1];
            if (b[0] == false && b[1] == false && b[2] == false)   {
                answer += "1";
                qDebug() << "here";
            }
            QString s1 = "";
            int n = 1;
            for (int j = b.size() - 1; j >= 0; j--) {
                if (b[j] == 1)  s1 += "x" + QString::number(n) + "&";
                n++;
            }
            answer += s1 + " + ";
        }
    }
    for (int i = 0; i < answer.length(); ++i) {
        if ((answer[i] == ' ') && (answer[i - 1] == '&'))     answer.replace(i - 1, 2, " ");
    }
    answer.replace(answer.length() - 3, 3, "");
    qDebug() << answer;
    return answer;
}


/**
 * @brief генерация текстовой части задания
 * @param input - сгенерированный вектор булевых значений (задание)
 * @return текст задания
 */
QString gen_text_for_task1(QString input){
    return "Boolean function: " + input;
}

/**
 * @brief генерация текстовой части задания
 * @param input - сгенерированный вектор булевых значений (задание)
 * @return текст задания
 */
QString gen_text_for_task2(QString input){
    return "Boolean function: " + input;
}

/**
 * @brief генерация текстовой части задания
 * @param input - сгенерированный вектор булевых значений (задание)
 * @return текст задания
 */
QString gen_text_for_task3(QString input){
    return "Boolean function: " + input;
}


/**
 * @brief автоматическая генерация вектора булевых значений
 * @return вектор булевых значений
 */

QString gen_task1(){
    QString randomString = "00110101";
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(randomString.begin(), randomString.end(), g);
    for (auto a : randomString){
        qDebug() << a;
    }
    return randomString;
}

/**
 * @brief автоматическая генерация вектора булевых значений
 * @return вектор булевых значений
 */
QString gen_task2(){
    QString randomString = "10110101";
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(randomString.begin(), randomString.end(), g);
    for (auto a : randomString){
        qDebug() << a;
    }
    return randomString;
}

/**
 * @brief автоматическая генерация вектора булевых значений
 * @return вектор булевых значений
 */
QString gen_task3(){
    QString randomString = "10010101";
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(randomString.begin(), randomString.end(), g);
    for (auto a : randomString){
        qDebug() << a;
    }
    return randomString;
}


/**
 * @brief проверка заданий
 * @param task_num
 * @param ans
 * @param input
 */
bool check_task(int task_num, QString ans, QString input){
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

     if(ans == solution){
         upd_stat(task_num, "+");
         return true;
     }
     else{
         upd_stat(task_num, "-");
         return false;
     }


}



