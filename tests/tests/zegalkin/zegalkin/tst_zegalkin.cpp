#include <QtTest>

// add necessary includes here
#include "/home/kali/prog/ser/ClientAndWindowsInOne/client.h"
#include "/home/kali/prog/ser/ClientAndWindowsInOne/back_func.h"

client * client::p_instance = 0;
clientDestroyer client::destroyer;
QTcpSocket *client::mTcpSocket;


class zegalkin : public QObject
{
    Q_OBJECT

public:
    zegalkin();
    ~zegalkin();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();

};

zegalkin::zegalkin()
{

}

zegalkin::~zegalkin()
{

}

void zegalkin::test_case1()
{
    QVector<QString> test = {"1", "x2", "x2x3", "x1", "x1x3", "x1x2", "x1x2x3"};
    QCOMPARE (test, solve_task3("11010101"));
}

void zegalkin::test_case2()
{
    QVector<QString> test = {"1", "x2", "x1", "x1x2"};
    QCOMPARE (test, solve_task3("11000000"));
}

void zegalkin::test_case3()
{
    QVector<QString> test = {"1", "x3", "x1x3"};
    QCOMPARE (test, solve_task3("10101111"));
}

QTEST_APPLESS_MAIN(zegalkin)

#include "tst_zegalkin.moc"
