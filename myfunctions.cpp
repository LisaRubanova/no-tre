#include "myfunctions.h"
#include <QStringList>
myfunctions::myfunctions()
{

}
QString auth(QString login, QString password){
    QString status = "You are not registered! ";
    if (login == "user" && password == "pass"){
         status = "You are user. ";
    }
    if (login == "admin" && password == "admin123"){
         status = "You are admin. ";
    }
    return status;
}
QString reg(QString login, QString password, QString email){
    QString status = "You registered! ";
    if (login == "user" || login == "admin"){
        status = "You have been already registered! ";
    }
    return status;
}
QString parsing(QString data_from_client){
    //data_from_client = func&param1&param2&param3
    //admin = auth&admin&admin123&-
    //user = auth&user&pass&-
    //reg = reg&newuser&123&mail
    QStringList list = data_from_client.split("&", Qt::SkipEmptyParts);
    if (list[0] == "auth"){
         return auth(list[1], list[2]);
    }
    else if (list[0] == "reg"){
         return reg(list[1], list[2], list[3]);
    }
    return "Error ";
}


