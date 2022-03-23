#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H
#include <QString>

class myfunctions
{
public:
    myfunctions();
    QString parsing(QString data_from_client);
    QString reg(QString login, QString password, QString email);
    QString auth(QString login, QString password);
};

#endif // MYFUNCTIONS_H
