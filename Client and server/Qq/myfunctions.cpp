#include "myfunctions.h"
#include <QStringList>
#include <QDebug>
//#include "database.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

QString name;
/**
 * @brief деструктор для закрытия базы данных
 */
myfunctions::~myfunctions()
{
    if (db.open()){
        db.close();
        qDebug() << "closed";
    }
    else{
        qDebug() << "already closed";
    }
}

/**
 * @brief конструктор для открытия базы данных
 */
myfunctions::myfunctions()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/ProgTech/DataBase/ForUserAndStatistic.db");
    //"D:\ProgTech\DataBase\ForUser.db"
    //db.setDatabaseName("D:/ProgTech/DataBase/build-DataBase-Desktop_Qt_6_2_3_MSVC2019_64bit-Debug/ForUsers.db");
    if (!db.open()){
        qDebug() << "nope";
    }
    else{
        qDebug() << "ok";
    }
}
/**
 * @brief 1. Выполняем запрос по поиску имени пользователя в базе данных.
 * 2. Сравниваем полученное имя пользователя и пароль, введённые пользователем, со значениями в базе данных. Если совпадает, статус = "Welcome! ",
 * иначе статус = (by default) "Wrong username or password! "
 * Намеренно не добавлен статус об отсутсвии введенного имени пользователя в базе данных.
 * @param login
 * @param password
 * @return статус попытки входа в аккаунт ("Welcome! "/"Wrong username or password! ")
 */
QString myfunctions::auth(QString login, QString password){
    QString log_from_db, pass_from_db, status_from_db;

    QSqlQuery query(db);
    //1.
    query.prepare("SELECT * FROM User "
               "WHERE login == :login");
    query.bindValue(":login",login);
    query.exec();

    QSqlRecord rec = query.record();
    const int loginIndex = rec.indexOf("login");
    const int passwordIndex = rec.indexOf("password");
    const int statusIndex = rec.indexOf("status");

    while(query.next())
        log_from_db = query.value(loginIndex).toString(), pass_from_db = query.value(passwordIndex).toString(),
                status_from_db = query.value(statusIndex).toString();
        qDebug()<<log_from_db <<"\t"<<pass_from_db<<"\n";

    QString status = "Wrong username or password! ";
    //2.
    if (login == log_from_db && password == pass_from_db){
        //status = "Welcome! student";
        if (status_from_db == "student" || status_from_db == "administrator")
         status = "Welcome! student";
        else if (status_from_db == "teacher")
         status = "Welcome! teacher";
    }

    return status;
}

/**
 * @brief 1. Проверка наличия логина в базе, если есть - нельзя зарегистрироваться, статус = "This username is already used!".
 * 2. Проверяем добавление в базу данных пользователей. Если успешно, статус = "You have been successfully registered! ",
 * иначе статус = (by default) "You are not registered! ".
 * @param login
 * @param password
 * @param email
 * @return статус регистрации ("This username is already used!"/"You have been successfully registered! "/"You are not registered! ")
 */
QString myfunctions::reg(QString login, QString password, QString email, QString status){
    QSqlQuery query(db);
    QString stat = "You are not registered! ";
    //1.
    QString log_from_db, pass_from_db, email_from_db, status_from_db;
    query.prepare("SELECT * FROM User "
               "WHERE login == :login");
    query.bindValue(":login",login);
    query.exec();

    QSqlRecord rec = query.record();
    while(query.next())
        log_from_db = query.value(rec.indexOf("login")).toString();

     if (login == log_from_db){
         stat = "This username is already used!";
     }
     else{
         if (status == "student"){
             query.prepare("INSERT INTO statistic(name) "
                               "VALUES (:name)");
             query.bindValue(":name",login);
             query.exec();
         }

         query.prepare("INSERT INTO User(login, password, email, status) "
                           "VALUES (:login, :password, :email, :status)");
         query.bindValue(":password",password);
         query.bindValue(":login",login);
         query.bindValue(":email",email);
         query.bindValue(":status",status);
         query.exec();
         //2.
         query.prepare("SELECT * FROM User "
                    "WHERE login == :login");
         query.bindValue(":login",login);
         query.exec();

         QSqlRecord rec = query.record();
         const int loginIndex = rec.indexOf("login");
         const int passwordIndex = rec.indexOf("password");
         const int emailIndex = rec.indexOf("email");
         const int statusIndex = rec.indexOf("status");

         while(query.next())
             log_from_db = query.value(loginIndex).toString(), pass_from_db = query.value(passwordIndex).toString(),
                     email_from_db = query.value(emailIndex).toString(), status_from_db = query.value(statusIndex).toString();
             qDebug()<<log_from_db <<"\t"<<pass_from_db<<"\t" << email_from_db << status_from_db << "\n";

         if (login == log_from_db && password == pass_from_db && email == email_from_db && status == status_from_db){
              stat = "You have been successfully registered! ";
         }
     }

    return stat;
}

QString myfunctions::updStat(QString name, QString task_num, QString status_of_task){
    QSqlQuery query(db);
    int task = task_num.toInt();
    qDebug() << name;
    switch(task){
    case 1:
        query.prepare("UPDATE statistic "
                      "SET task1 = :task1 "
                      "WHERE name == :name");
        query.bindValue(":name",name);
        query.bindValue(":task1",status_of_task);
        query.exec();
        break;
    case 2:
        query.prepare("UPDATE statistic "
                      "SET task2 = :task2 "
                      "WHERE name == :name");
        query.bindValue(":task2",status_of_task);
        query.bindValue(":name",name);
        query.exec();
        break;
    case 3:
        query.prepare("UPDATE statistic "
                      "SET task3 = :task3 "
                      "WHERE name == :name");
        query.bindValue(":name",name);
        query.bindValue(":task3",status_of_task);
        query.exec();
        break;
    }
    return "Status probably have been updated";
}

QString myfunctions::get_stat (QString task_num){
    QSqlQuery query(db);

    QString name_from_db, task1_from_db, task2_from_db, task3_from_db, stat;

    int task = task_num.toInt();
    query.prepare("SELECT * FROM statistic "
               "WHERE name == :name");
    query.bindValue(":name",name);
    query.exec();

    QSqlRecord rec = query.record();
    const int nameIndex = rec.indexOf("name");
    const int task1Index = rec.indexOf("task1");
    const int task2Index = rec.indexOf("task2");
    const int task3Index = rec.indexOf("task3");

    while(query.next())
        name_from_db = query.value(nameIndex).toString(), task1_from_db = query.value(task1Index).toString(),
                task2_from_db = query.value(task2Index).toString(), task3_from_db = query.value(task3Index).toString();
        qDebug()<<name_from_db <<"\t"<<task1_from_db<<"\t" << task2_from_db << task3_from_db << "\n";

    switch(task){
    case 1:{
            stat = "1&" + task1_from_db;
            break;
    }
    case 2:{
            stat = "2&" + task2_from_db;
            break;
    }
    case 3:{
            stat = "3&" + task3_from_db;
            break;
    }
    }
    return stat;
}



/**
 * @brief 1. Добавляем в список параметры, полученный разбитием строки формата func&username&password&email по &
 * 2. Вызываем функцию по индексу 0 и передаем необходимые параметры по индексам:
 * [1] - username
 * [2] - password
 * [3] - email
 * [4] - status (teacher/student
 * [1] и [2] необходимы для функции auth [4]?
 * [1], [2], [3], [4] необходимы для функции reg
 * @param data_from_client
 * @return статус (полученный в результате выполнения запрашиваемой функции/"Error ")
 */
QString myfunctions::parsing(QString data_from_client){
    //1.
    QString student_name = "";
    QString teacher_name = "";

    QStringList list = data_from_client.split("&", QString::SplitBehavior::SkipEmptyParts);
    //2.
    if (list[0] == "auth"){
        if (auth(list[1], list[2]) == "Welcome! student"){
            name = list[1];
        }
        else if (auth(list[1], list[2]) == "Welcome! teacher"){
            name = list[1];
        }
        return auth(list[1], list[2]);
    }
    else if (list[0] == "reg"){
         return reg(list[1], list[2], list[3], list[4]);
    }
    else if (list[0] == "getStat"){
         return get_stat(list[1]);
    }
    else if (list[0] == "updStat"){
        qDebug() << "updStat";
        return updStat(name, list[1], list[2]);
    }
    return "Error ";
}


