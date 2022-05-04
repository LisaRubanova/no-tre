#include "mainwindow.h"
#include "client.h"
#include <QApplication>

client * client::p_instance=0;
clientDestroyer client::destroyer;
QTcpSocket * client::mTcpSocket;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /**
     * @brief создание объекта основного окна для последующей работы
     */
    client *cl = client::getInstance();
    //cl->sendToServer("auth&admin&12345&");
    MainWindow w;
    //  w.show();
    return a.exec();
}
