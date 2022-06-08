#include <QtTest>

// add necessary includes here
#include "/home/kali/prog/ser/ClientAndWindowsInOne/client.h"
#include "/home/kali/prog/ser/ClientAndWindowsInOne/back_func.h"

client *client::p_instance = 0;
clientDestroyer client::destroyer;
QTcpSocket *client::mTcpSocket;

class SKNF_test : public QObject
{
    Q_OBJECT

public:
    SKNF_test();
    ~SKNF_test();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();
};

SKNF_test::SKNF_test()
{

}

SKNF_test::~SKNF_test()
{

}

void SKNF_test::test_case1()
{
    QVector<QString> test = {"x1Vx2'Vx3", "x1'Vx2Vx3'"};
    QCOMPARE(test, solve_task2("11011011"));
}

void SKNF_test::test_case2()
{
    QVector<QString> test = {"x1Vx2'Vx3", "x1'Vx2Vx3", "x1'Vx2Vx3'", "x1'Vx2'Vx3'"};
    QCOMPARE(test, solve_task2("11010010"));
}

void SKNF_test::test_case3()
{
    QVector<QString> test = {"x1Vx2Vx3", "x1Vx2Vx3'", "x1'Vx2'Vx3"};
    QCOMPARE(test, solve_task2("00111101"));
}

QTEST_APPLESS_MAIN(SKNF_test)

#include "tst_sknf_test.moc"
