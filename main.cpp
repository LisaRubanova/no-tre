#include <QCoreApplication>
#include "mytcpserver.h"
//#include "database.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    /**
     * @brief создание объекта сервера, необходимо для запуска
     */
    MyTcpServer myserv;
    return a.exec();
}
