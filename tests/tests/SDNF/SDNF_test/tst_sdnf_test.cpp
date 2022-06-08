#include <QtTest>

// add necessary includes here
#include "/home/kali/prog/ser/ClientAndWindowsInOne/back_func.h"
//#include "/home/kali/prog/ser/ClientAndWindowsInOne/back_func.cpp"
#include "/home/kali/prog/ser/ClientAndWindowsInOne/client.h"
//#include "/home/kali/prog/ser/ClientAndWindowsInOne/client.cpp"

client *client::p_instance = 0;
clientDestroyer client::destroyer;
QTcpSocket *client::mTcpSocket;

class SDNF_test : public QObject
{
    Q_OBJECT

public:
    SDNF_test();
    ~SDNF_test();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();

};

SDNF_test::SDNF_test()
{

}

SDNF_test::~SDNF_test()
{

}

void SDNF_test::test_case1()
{
    QVector<QString> test = {"x1'x2'x3'", "x1'x2'x3", "x1'x2x3", "x1x2'x3", "x1x2x3'"};
    QCOMPARE(test, solve_task1("11010110"));
}

void SDNF_test::test_case2()
{
    QVector<QString> test = {"x1'x2'x3", "x1'x2x3", "x1x2'x3"};
    QCOMPARE(test, solve_task1("01010100"));
}

void SDNF_test::test_case3()
{
    QVector<QString> test = {"x1'x2'x3'", "x1'x2x3'", "x1x2'x3'", "x1x2x3"};
    QCOMPARE(test, solve_task1("10101001"));
}

QTEST_APPLESS_MAIN(SDNF_test)

#include "tst_sdnf_test.moc"
