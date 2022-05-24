#include "myfunctions.h"
#include <QStringList>
#include <QDebug>
//#include "database.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

QString lognow;
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
    db.setDatabaseName("D:/ProgTech/DataBase/USG.db");
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
QString myfunctions::reg(QString login, QString password, QString email, QString status, QString name, QString surname){
    QSqlQuery query(db);
    QString stat = "You are not registered! ";
    //1.
    QString log_from_db, pass_from_db, email_from_db, status_from_db, name_from_db, surname_from_db;
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
             query.prepare("INSERT INTO statistic(login) "
                               "VALUES (:login)");
             query.bindValue(":login",login);
             query.exec();
         }

         query.prepare("INSERT INTO User(login, password, email, status, name, surname) "
                           "VALUES (:login, :password, :email, :status, :name, :surname)");
         query.bindValue(":password",password);
         query.bindValue(":login",login);
         query.bindValue(":email",email);
         query.bindValue(":status",status);
         query.bindValue(":name",name);
         query.bindValue(":surname",surname);
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
         const int nameIndex = rec.indexOf("name");
         const int surnameIndex = rec.indexOf("surname");

         while(query.next())
             log_from_db = query.value(loginIndex).toString(), pass_from_db = query.value(passwordIndex).toString(),
                     email_from_db = query.value(emailIndex).toString() , status_from_db = query.value(statusIndex).toString(),
                     name_from_db = query.value(nameIndex).toString(), surname_from_db = query.value(surnameIndex).toString();
             qDebug()<<log_from_db <<"\t"<<pass_from_db<<"\t" << email_from_db << status_from_db << "\n";

         if (login == log_from_db && password == pass_from_db && email == email_from_db && status == status_from_db && name == name_from_db
                 && surname == surname_from_db){
              stat = "You have been successfully registered! ";
         }
     }

    return stat;
}

QString myfunctions::updStat(QString login, QString task_num, QString status_of_task){
    QSqlQuery query(db);
    int task = task_num.toInt();
    qDebug() << login;
    switch(task){
    case 1:
        query.prepare("UPDATE statistic "
                      "SET task1 = :task1 "
                      "WHERE login == :login");
        query.bindValue(":login",login);
        query.bindValue(":task1",status_of_task);
        query.exec();
        break;
    case 2:
        query.prepare("UPDATE statistic "
                      "SET task2 = :task2 "
                      "WHERE login == :login");
        query.bindValue(":task2",status_of_task);
        query.bindValue(":login",login);
        query.exec();
        break;
    case 3:
        query.prepare("UPDATE statistic "
                      "SET task3 = :task3 "
                      "WHERE login == :login");
        query.bindValue(":login",login);
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
               "WHERE login == :login");
    query.bindValue(":login",lognow);
    query.exec();

    QSqlRecord rec = query.record();
    const int nameIndex = rec.indexOf("login");
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

//encrypting function and decrypting

QString myfunctions::encrypt(QString toEncrypt){
    quint32 key = 562;
    QByteArray arr(toEncrypt.toUtf8());
    for(int i =0; i<arr.size(); i++)
        arr[i] = arr[i] ^ key;

    return QString::fromLatin1(arr.toBase64());
}

QString myfunctions::decrypt(QString toDecrypt)
{
    quint32 key = 562;
    QByteArray arr = QByteArray::fromBase64(toDecrypt.toLatin1());
    for(int i =0; i<arr.size(); i++)
        arr[i] = arr[i] ^ key;

    return QString::fromUtf8(arr);
}

//преподаватель вводит имя и фамилию, их нужно преобразовать в логин - get_login(name, surname)
/*
 * 0      1       2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19  20     21
&resol&group_num&n1&s1&n2&s2&n3&s3&n4&s4&n5&s5&n6&s6&n7&s7&n8&s8&n9&s9&teacher_log
    else if (list[0] == "resol"){
         return add_group(list[1], get_login(list[2], list[3]), get_login(list[4], list[5]), get_login(list[6], list[7]),
            get_login(list[8], list[9]), get_login(list[10], list[11]), get_login(list[12], list[13]), get_login(list[14], list[15]),
            get_login(list[16], list[17]), get_login(list[18], list[19]), get_login(list[20], list[21]));
    }
*/

QString myfunctions::get_login(QString name, QString surname){
    QString login = " ";
    QSqlQuery query(db);
    //1.
    query.prepare("SELECT login FROM User "
               "WHERE name == :name AND surname == :surname");
    query.bindValue(":name",name);
    query.bindValue(":surname",surname);
    query.exec();

    QSqlRecord rec = query.record();
    const int loginIndex = rec.indexOf("login");

    while(query.next())
        login = query.value(loginIndex).toString();
        qDebug()<<login << "\n";
    return login;
}


//в группу добавляются логины lognow
QString myfunctions::add_group(QString group_num, QString log_p1, QString log_p2, QString log_p3,
                               QString log_p4, QString log_p5, QString log_p6, QString log_p7,
                               QString log_p8, QString log_p9, QString teacher){
    QString status = "probably has been updated";
    QSqlQuery query(db);
    query.prepare("INSERT INTO groups(group_num, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10) "
                      "VALUES (:group_num, :p1, :p2, :p3, :p4, :p5, :p6, :p7, :p8, :p9, :p10)");
    query.bindValue(":group_num", group_num);
    query.bindValue(":p1", log_p1);
    query.bindValue(":p2", log_p2);
    query.bindValue(":p3", log_p3);
    query.bindValue(":p4", log_p4);
    query.bindValue(":p5", log_p5);
    query.bindValue(":p6", log_p6);
    query.bindValue(":p7", log_p7);
    query.bindValue(":p8", log_p8);
    query.bindValue(":p9", log_p9);
    query.bindValue(":p10", teacher);
    query.exec();


    return status;
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
    //qDebug() << "data client 1:" << data_from_client;
    //if (data_from_client.endsWith("=="))
    data_from_client = decrypt(data_from_client);
    //qDebug() << "data client" << data_from_client;
    QString student_name = "";
    QString teacher_name = "";

    QStringList list = data_from_client.split("&", QString::SplitBehavior::SkipEmptyParts);
    //2.
    if (list[0] == "auth"){
        if (auth(list[1], list[2]) == "Welcome! student"){
            lognow = list[1];
        }
        else if (auth(list[1], list[2]) == "Welcome! teacher"){
            lognow = list[1];
        }
        return auth(list[1], list[2]);
    }
    else if (list[0] == "reg"){
         return reg(list[1], list[2], list[3], list[4], list[5], list[6]);
    }
    else if (list[0] == "getStat"){
         return get_stat(list[1]);
    }
    else if (list[0] == "updStat"){
        qDebug() << "updStat";
        return updStat(lognow, list[1], list[2]);
    }
    // если одинаковые имя и фамилия - спросить почту ученика
    else if (list[0] == "get_log"){
        qDebug() << "get_log" << list[1] << list[2];
        return get_login(list[1], list[2]);
    }
    else if (list[0] == "add_group"){
        qDebug() << "add_group";
        return add_group(list[1], get_login(list[2], list[3]), get_login(list[4], list[5]), get_login(list[6], list[7]),
                get_login(list[8], list[9]), get_login(list[10], list[11]), get_login(list[12], list[13]), get_login(list[14], list[15]),
                get_login(list[16], list[17]), get_login(list[18], list[19]), lognow);
    }
    return "Error ";
}


