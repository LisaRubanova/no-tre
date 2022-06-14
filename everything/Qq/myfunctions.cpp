#include "myfunctions.h"
#include <QStringList>
#include <QDebug>
//#include "database.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QMap>

QString lognow;
/**
 * @brief деструктор для закрытия базы данных
 */
myfunctions::~myfunctions()
{
    /*
    if (db->open()){
        db->close();
        qDebug() << "closed";
    }
    else{
        qDebug() << "already closed";
    }
    */
}



/**
 * @brief конструктор для открытия базы данных
 */
myfunctions::myfunctions()
{
    singleton_db *db = singleton_db::getInstance();

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
    //singleton_db *db = singleton_db::getInstance();
    QString log_from_db, pass_from_db, status_from_db;
    qDebug() << "authentication";
    QSqlQuery query;
    //1.
    query.prepare("SELECT * FROM User "
               "WHERE login == :login");
    query.bindValue(":login",encrypt(login, 1017));
    query.exec();
    QByteArray pas = password.toUtf8();
    QString p = QCryptographicHash::hash(pas, QCryptographicHash::Md5).toHex();
    QString status_teach = "teacher";
    QByteArray st_teach = status_teach.toUtf8();
    QString st = QCryptographicHash::hash(st_teach, QCryptographicHash::Sha224).toHex();
    QString status_st = "student";
    QByteArray st_st = status_st.toUtf8();
    QString ss = QCryptographicHash::hash(st_st, QCryptographicHash::Sha224).toHex();
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
    if (login == decrypt(log_from_db,1017) && p == pass_from_db){
        //status = "Welcome! student";
        if (status_from_db == ss)//"student") || status_from_db == "administrator")
         status = "Welcome! student";
        else if (status_from_db == st)//"teacher")
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
    //singleton_db *db = singleton_db::getInstance();
    QSqlQuery query;
    QString stat = "You are not registered! ";
    //1.
    QString log_from_db, pass_from_db, email_from_db, status_from_db, name_from_db, surname_from_db;
    query.prepare("SELECT * FROM User "
               "WHERE login == :login");
    query.bindValue(":login", encrypt(login, 1017));
    query.exec();

    QSqlRecord rec = query.record();
    while(query.next())
        log_from_db = query.value(rec.indexOf("login")).toString();

     if (login == decrypt(log_from_db, 1017)){
         stat = "This username is already used!";
     }
     else{
         QByteArray log = login.toUtf8();
         QString l = QCryptographicHash::hash(log, QCryptographicHash::Md4).toHex();
         if (status == "student"){
             query.prepare("INSERT INTO statistic(login) "
                               "VALUES (:login)");
             query.bindValue(":login",l);
             query.exec();
         }
         QByteArray pas = password.toUtf8();
         QString p = QCryptographicHash::hash(pas, QCryptographicHash::Md5).toHex();
         QByteArray em = email.toUtf8();
         QString e = QCryptographicHash::hash(em, QCryptographicHash::Md5).toHex();
         QByteArray st = status.toUtf8();
         QString s = QCryptographicHash::hash(st, QCryptographicHash::Sha224).toHex();
         query.prepare("INSERT INTO User(login, password, email, status, name, surname) "
                           "VALUES (:login, :password, :email, :status, :name, :surname)");
         query.bindValue(":password",p);
         query.bindValue(":login",encrypt(login, 1017));
         query.bindValue(":email",e);
         query.bindValue(":status",s);
         query.bindValue(":name",encrypt(name, 785));
         query.bindValue(":surname", encrypt(surname, 996));
         query.exec();
         //2.
         query.prepare("SELECT * FROM User "
                    "WHERE login == :login");
         query.bindValue(":login",encrypt(login, 1017));
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

         if (login == decrypt(log_from_db, 1017) && p == pass_from_db && e == email_from_db && s == status_from_db && name == decrypt(name_from_db, 785)
                 && surname == decrypt(surname_from_db, 996)){
              stat = "You have been successfully registered! ";
         }
     }

    return stat;
}

QString myfunctions::updStat(QString login, QString task_num, QString status_of_task){
    singleton_db *db = singleton_db::getInstance();
    QSqlQuery query;
    int task = task_num.toInt();
    qDebug() << login;
    QByteArray log = login.toUtf8();
    QString l = QCryptographicHash::hash(log, QCryptographicHash::Md4).toHex();

    switch(task){
    case 1:
        query.prepare("UPDATE statistic "
                      "SET task1 = :task1 "
                      "WHERE login == :login");
        query.bindValue(":login",l);
        query.bindValue(":task1",status_of_task);
        query.exec();
        break;
    case 2:
        query.prepare("UPDATE statistic "
                      "SET task2 = :task2 "
                      "WHERE login == :login");
        query.bindValue(":task2",status_of_task);
        query.bindValue(":login",l);
        query.exec();
        break;
    case 3:
        query.prepare("UPDATE statistic "
                      "SET task3 = :task3 "
                      "WHERE login == :login");
        query.bindValue(":login",l);
        query.bindValue(":task3",status_of_task);
        query.exec();
        break;
    }
    return "Status probably has been updated";
}

QString myfunctions::get_stat (QString task_num){
    singleton_db *db = singleton_db::getInstance();
    QSqlQuery query;
    QByteArray log = lognow.toUtf8();
    QString l = QCryptographicHash::hash(log, QCryptographicHash::Md4).toHex();
    QString name_from_db, task1_from_db, task2_from_db, task3_from_db, stat;

    int task = task_num.toInt();
    query.prepare("SELECT * FROM statistic "
               "WHERE login == :login");
    query.bindValue(":login",l);
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

QString myfunctions::encrypt(QString toEncrypt, quint32 key){
    //quint32 key = 562;
    QByteArray arr(toEncrypt.toUtf8());
    for(int i =0; i<arr.size(); i++)
        arr[i] = arr[i] ^ key;

    return QString::fromLatin1(arr.toBase64());
}

QString myfunctions::decrypt(QString toDecrypt, quint32 key)
{
    //quint32 key = 562;
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
    //singleton_db *db = singleton_db::getInstance();
    QString login;
    QSqlQuery query;
    qDebug() << "name=surname" << name << surname;
    //1.
    query.prepare("SELECT login FROM User "
               "WHERE name == :name AND surname == :surname");
    query.bindValue(":name",encrypt(name, 785));
    query.bindValue(":surname",encrypt(surname, 996));
    query.exec();

    QSqlRecord rec = query.record();
    const int loginIndex = rec.indexOf("login");

    while(query.next())
        login = query.value(loginIndex).toString();
        qDebug()<< "login!!!! = " << login  << decrypt(login,1017)<< "\n";
    return decrypt(login,1017);
}

QString myfunctions::get_info(QString group){
    singleton_db *db = singleton_db::getInstance();
    QString px, p1, p2, p3, p4, p5, p6, p7, p8, p9, status, name, surname, t1, t2, t3;

    status = "";
    QSqlQuery query;
    query.prepare("SELECT * FROM groups "
               "WHERE group_num == :group_num");
    query.bindValue(":group_num",encrypt(group, 318));
    query.exec();
    QSqlRecord rec = query.record();
    const int p1Index = rec.indexOf("p1");
    const int p2Index = rec.indexOf("p2");
    const int p3Index = rec.indexOf("p3");
    const int p4Index = rec.indexOf("p4");
    const int p5Index = rec.indexOf("p5");
    const int p6Index = rec.indexOf("p6");
    const int p7Index = rec.indexOf("p7");
    const int p8Index = rec.indexOf("p8");
    const int p9Index = rec.indexOf("p9");

    while(query.next())
        p1 = query.value(p1Index).toString(), //-logins
                p2 = query.value(p2Index).toString(),
                p3 = query.value(p3Index).toString(),
                p4 = query.value(p4Index).toString(),
                p5 = query.value(p5Index).toString(),
                p6 = query.value(p6Index).toString(),
                p7 = query.value(p7Index).toString(),
                p8 = query.value(p8Index).toString(),
                p9 = query.value(p9Index).toString();

    QMap<int,QString> ind {{1,decrypt(p1,318)}, {2,decrypt(p2,318)}, {3,decrypt(p3,318)}, {4,decrypt(p4,318)}, {5,decrypt(p5,318)}, {6,decrypt(p6,318)},
                           {7,decrypt(p7,318)}, {8,decrypt(p8,318)}, {9,decrypt(p9,318)}};
    //qDebug() << ind.value(4);
    for (int i = 1; i < 10; ++i){

        qDebug() << ind.value(i);
        if(ind.value(i) != ""){
            query.prepare("SELECT * FROM User "
                       "WHERE login == :login");
            query.bindValue(":login",encrypt(ind.value(i), 1017));
            query.exec();
            QSqlRecord mec = query.record();
            const int nameIndex = mec.indexOf("name");
            const int surnameIndex = mec.indexOf("surname");
            while(query.next())
                name = query.value(nameIndex).toString(),
                        surname = query.value(surnameIndex).toString();
            qDebug() << decrypt(name, 785) << decrypt(surname, 996);

            QByteArray log = ind.value(i).toUtf8();
            QString l = QCryptographicHash::hash(log, QCryptographicHash::Md4).toHex();
            query.prepare("SELECT * FROM statistic "
                       "WHERE login == :login");
            query.bindValue(":login",l);
            query.exec();

            QSqlRecord cec = query.record();
            const int task1Index = cec.indexOf("task1");
            const int task2Index = cec.indexOf("task2");
            const int task3Index = cec.indexOf("task3");

            while(query.next())
                t1 = query.value(task1Index).toString(),
                        t2 = query.value(task2Index).toString(),
                        t3 = query.value(task3Index).toString();
                qDebug() <<t1<<"\t" << t2 << t3 << "\n";
        }
        else{
            name = " ";
            surname = " ";
            t1 = " ";
            t2 = " ";
            t3 = " ";
        }

        status += "&" + decrypt(name, 785) + "&" + decrypt(surname, 996) + "&" + t1 + "&" + t2 + "&" + t3 + "&" + "Q";
    }

    qDebug() << status;

    return status;
}

QString myfunctions::check_student(QString login){
    QString gr, st;
    QString status = "ok";
    singleton_db *db = singleton_db::getInstance();
    QSqlQuery query;
    query.prepare("SELECT group_num FROM groups "
                  "WHERE p1 == :login OR p2 == :login OR p3 == :login OR p4 == :login OR p5 == :login OR p6 == :login OR p7 == :login OR p8 == :login OR p9 == :login");
    query.bindValue(":login", encrypt(login, 318));
    query.exec();
    QSqlRecord rec = query.record();
    qDebug() << rec;
    const int groupIndex = rec.indexOf("group_num");

    while(query.next())
        gr = query.value(groupIndex).toString();
    qDebug() << "gr" << decrypt(gr, 318);
    if (decrypt(gr, 318) != ""){
        status = "no";
    }

    QString status_st = "student";
    QByteArray st_st = status_st.toUtf8();
    QString ss = QCryptographicHash::hash(st_st, QCryptographicHash::Sha224).toHex();
    qDebug() << "log in " << login;
    query.prepare("SELECT * FROM User "
               "WHERE login == :login");
    query.bindValue(":login",encrypt(login, 1017));
    query.exec();
    QSqlRecord rec1 = query.record();
    const int statusIndex = rec1.indexOf("status");
    while(query.next())
        st = query.value(statusIndex).toString();
    qDebug() << "st" << st;
    qDebug() << "ss" << ss;

    if(st != ss){
        status = "no";
    }
    return status;
}

//в группу добавляются логины
QString myfunctions::add_group(QString group_num, QString log_p1, QString log_p2, QString log_p3,
                               QString log_p4, QString log_p5, QString log_p6, QString log_p7,
                               QString log_p8, QString log_p9, QString teacher){
    singleton_db *db = singleton_db::getInstance();
    QString status = "probably has been updated";
    QString group_from_db;
    QMap<int,QString> ind {{1,log_p1}, {2,log_p2}, {3,log_p3}, {4,log_p4}, {5,log_p5}, {6,log_p6}, {7,log_p7}, {8,log_p8}, {9,log_p9}};
    QSqlQuery query;
    query.prepare("SELECT * FROM groups "
                  "WHERE group_num == :group_num");
    query.bindValue(":group_num", encrypt(group_num, 318));
    query.exec();
    QSqlRecord rec = query.record();
    const int groupIndex = rec.indexOf("group_num");

    while(query.next())
        group_from_db = query.value(groupIndex).toString();
    if (decrypt(group_from_db, 318) == group_num){
        if (check_access(group_num) == "allowed"){
            query.prepare("DELETE FROM groups "
                          "WHERE group_num == :group_num");
            query.bindValue(":group_num", encrypt(group_num, 318));
            query.exec();
        }
        else if (check_access(group_num) == "not allowed"){
            return "you cannot change group!";
        }
    }

    for (int i = 1; i < 10; ++i){
       if(ind.value(i) != ""){
           qDebug() << "value" << ind.value(i);
           if(check_student(ind.value(i)) == "no"){
               qDebug() << "no" << check_student(ind.value(i));
               return "one of student exists";
           }
       }
    }

    query.prepare("INSERT INTO groups(group_num, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10) "
                      "VALUES (:group_num, :p1, :p2, :p3, :p4, :p5, :p6, :p7, :p8, :p9, :p10)");
    query.bindValue(":group_num", encrypt(group_num, 318));
    query.bindValue(":p1", encrypt(log_p1, 318));
    query.bindValue(":p2", encrypt(log_p2, 318));
    query.bindValue(":p3", encrypt(log_p3, 318));
    query.bindValue(":p4", encrypt(log_p4, 318));
    query.bindValue(":p5", encrypt(log_p5, 318));
    query.bindValue(":p6", encrypt(log_p6, 318));
    query.bindValue(":p7", encrypt(log_p7, 318));
    query.bindValue(":p8", encrypt(log_p8, 318));
    query.bindValue(":p9", encrypt(log_p9, 318));
    query.bindValue(":p10", encrypt(teacher, 318));
    query.exec();


    return status;
}

QString myfunctions::check_access(QString group_num){
    singleton_db *db = singleton_db::getInstance();
    //qDebug() << teacher << group_num;
    QString group_from_db;
    QString status = "not allowed";
    QSqlQuery query;

    query.prepare("SELECT group_num FROM groups "
                  "WHERE p10 == :p10");
    query.bindValue(":p10", encrypt(lognow, 318));
    query.exec();
    QSqlRecord rec = query.record();
    qDebug() << rec;
    const int groupIndex = rec.indexOf("group_num");
    while(query.next())
        group_from_db = query.value(groupIndex).toString();
    qDebug()<<group_from_db << "\n";
    if (group_num == decrypt(group_from_db, 318)){
        status = "allowed";
    }
    return status;
}

QString myfunctions::get_student(){
    singleton_db *db = singleton_db::getInstance();
    QString name_from_db, surname_from_db;
    QString status = "&i_student&";
    QSqlQuery query;
    query.prepare("SELECT * FROM User "
                  "WHERE login == :login");
    query.bindValue(":login",  encrypt(lognow, 1017));
    query.exec();
    QSqlRecord rec = query.record();

    const int nameIndex = rec.indexOf("name");
    const int surnameIndex = rec.indexOf("surname");
    while(query.next())
        name_from_db = query.value(nameIndex).toString(), surname_from_db = query.value(surnameIndex).toString();
    status += decrypt(name_from_db, 785) + " " + decrypt(surname_from_db, 996) + "&";
    qDebug() << "get_student" << status;
    return status;
}

QString myfunctions::get_teacher(){
    singleton_db *db = singleton_db::getInstance();
    QString log_teacher_from_db, teacherName_from_db, teacherSurname_from_db;
    QString status = "&i_teacher&";
    QSqlQuery query;
    query.prepare("SELECT p10 FROM groups "
                  "WHERE p1 == :login OR p2 == :login OR p3 == :login OR p4 == :login OR p5 == :login OR p6 == :login OR p7 == :login OR p8 == :login OR p9 == :login");
    query.bindValue(":login", encrypt(lognow, 318));
    query.exec();
    QSqlRecord rec = query.record();
    qDebug() << rec;
    const int teacherIndex = rec.indexOf("p10");

    while(query.next())
        log_teacher_from_db = query.value(teacherIndex).toString();

    query.prepare("SELECT * FROM User "
                  "WHERE login == :login");
    query.bindValue(":login", encrypt(decrypt(log_teacher_from_db, 318), 1017));
    query.exec();
    QSqlRecord rec1 = query.record();
    qDebug() << rec;
    const int nameIndex = rec1.indexOf("name");
    const int surnameIndex = rec1.indexOf("surname");
    while(query.next())
        teacherName_from_db = query.value(nameIndex).toString(), teacherSurname_from_db = query.value(surnameIndex).toString();
    status += decrypt(teacherName_from_db, 785) + " " + decrypt(teacherSurname_from_db, 996) + "&";
    qDebug() << "get_teacher" << status;
    return status;
}

QString myfunctions::get_group(){
    singleton_db *db = singleton_db::getInstance();
    QString group_from_db;
    QString status = "&i_group&";
    QSqlQuery query;
    query.prepare("SELECT group_num FROM groups "
                  "WHERE p1 == :login OR p2 == :login OR p3 == :login OR p4 == :login OR p5 == :login OR p6 == :login OR p7 == :login OR p8 == :login OR p9 == :login");
    query.bindValue(":login", encrypt(lognow, 318));
    query.exec();
    QSqlRecord rec = query.record();
    qDebug() << rec;
    const int nameIndex = rec.indexOf("group_num");
    while(query.next())
        group_from_db = query.value(nameIndex).toString();
    status += decrypt(group_from_db, 318) + " &";
    qDebug() << "get_group" << status;
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
    data_from_client = decrypt(data_from_client, 562);
    qDebug() << "data client" << data_from_client;
    //QString student_name = "";
    //QString teacher_name = "";

    QStringList list = data_from_client.split("&", QString::SplitBehavior::SkipEmptyParts);
    //2.
    if (list[0] == "auth"){
        /*if (auth(list[1], list[2]) == "Welcome! student"){
            lognow = list[1];
        }
        else if (auth(list[1], list[2]) == "Welcome! teacher"){
            lognow = list[1];
        }*/
        lognow = list[1];
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
    else if(list[0] == "check_access"){
        qDebug() << "check_access";
        return check_access(list[1]);
    }
    else if(list[0] == "get_info"){
        qDebug() << "info";
        return get_info(list[1]);
    }
    else if(list[0] == "get_student"){
        return get_student();
    }
    else if(list[0] == "get_teacher"){
        return get_teacher();
    }
    else if(list[0] == "get_group"){
        return get_group();
    }
    return "Error ";

}


