/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTask1;
    QAction *actionTask2;
    QAction *actionTask3;
    QAction *actionExit;
    QAction *actionExit_2;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_task1;
    QPushButton *pushButton_task2;
    QPushButton *pushButton_task3;
    QPushButton *pushButton_new_group;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_stat;
    QPushButton *pushButton_exit;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(495, 316);
        actionTask1 = new QAction(MainWindow);
        actionTask1->setObjectName(QString::fromUtf8("actionTask1"));
        actionTask2 = new QAction(MainWindow);
        actionTask2->setObjectName(QString::fromUtf8("actionTask2"));
        actionTask3 = new QAction(MainWindow);
        actionTask3->setObjectName(QString::fromUtf8("actionTask3"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionExit_2 = new QAction(MainWindow);
        actionExit_2->setObjectName(QString::fromUtf8("actionExit_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(110, 80, 258, 143));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_task1 = new QPushButton(verticalLayoutWidget_2);
        pushButton_task1->setObjectName(QString::fromUtf8("pushButton_task1"));

        horizontalLayout->addWidget(pushButton_task1);

        pushButton_task2 = new QPushButton(verticalLayoutWidget_2);
        pushButton_task2->setObjectName(QString::fromUtf8("pushButton_task2"));

        horizontalLayout->addWidget(pushButton_task2);

        pushButton_task3 = new QPushButton(verticalLayoutWidget_2);
        pushButton_task3->setObjectName(QString::fromUtf8("pushButton_task3"));

        horizontalLayout->addWidget(pushButton_task3);


        verticalLayout_3->addLayout(horizontalLayout);

        pushButton_new_group = new QPushButton(verticalLayoutWidget_2);
        pushButton_new_group->setObjectName(QString::fromUtf8("pushButton_new_group"));

        verticalLayout_3->addWidget(pushButton_new_group);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_stat = new QPushButton(verticalLayoutWidget_2);
        pushButton_stat->setObjectName(QString::fromUtf8("pushButton_stat"));

        verticalLayout->addWidget(pushButton_stat);

        pushButton_exit = new QPushButton(verticalLayoutWidget_2);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));

        verticalLayout->addWidget(pushButton_exit);


        verticalLayout_3->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 495, 25));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionTask1);
        menuMenu->addAction(actionTask2);
        menuMenu->addAction(actionTask3);
        menuMenu->addSeparator();
        menuMenu->addAction(actionExit_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionTask1->setText(QCoreApplication::translate("MainWindow", "Task1", nullptr));
        actionTask2->setText(QCoreApplication::translate("MainWindow", "Task2", nullptr));
        actionTask3->setText(QCoreApplication::translate("MainWindow", "Task3", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionExit_2->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        pushButton_task1->setText(QCoreApplication::translate("MainWindow", "Task1", nullptr));
        pushButton_task2->setText(QCoreApplication::translate("MainWindow", "Task2", nullptr));
        pushButton_task3->setText(QCoreApplication::translate("MainWindow", "Task3", nullptr));
        pushButton_new_group->setText(QCoreApplication::translate("MainWindow", "Add new group", nullptr));
        pushButton_stat->setText(QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        pushButton_exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
