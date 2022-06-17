/********************************************************************************
** Form generated from reading UI file 'form_task.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_TASK_H
#define UI_FORM_TASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_task
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser_task;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QCheckBox *checkBox_000;
    QCheckBox *checkBox_100;
    QCheckBox *checkBox_001;
    QCheckBox *checkBox_101;
    QCheckBox *checkBox_010;
    QCheckBox *checkBox_110;
    QCheckBox *checkBox_011;
    QCheckBox *checkBox_111;
    QPushButton *pushButton_ok;

    void setupUi(QWidget *Form_task)
    {
        if (Form_task->objectName().isEmpty())
            Form_task->setObjectName(QString::fromUtf8("Form_task"));
        Form_task->resize(305, 350);
        verticalLayoutWidget = new QWidget(Form_task);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 258, 301));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser_task = new QTextBrowser(verticalLayoutWidget);
        textBrowser_task->setObjectName(QString::fromUtf8("textBrowser_task"));

        verticalLayout->addWidget(textBrowser_task);

        groupBox = new QGroupBox(verticalLayoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        checkBox_000 = new QCheckBox(groupBox);
        checkBox_000->setObjectName(QString::fromUtf8("checkBox_000"));

        gridLayout->addWidget(checkBox_000, 0, 0, 1, 1);

        checkBox_100 = new QCheckBox(groupBox);
        checkBox_100->setObjectName(QString::fromUtf8("checkBox_100"));

        gridLayout->addWidget(checkBox_100, 0, 1, 1, 1);

        checkBox_001 = new QCheckBox(groupBox);
        checkBox_001->setObjectName(QString::fromUtf8("checkBox_001"));

        gridLayout->addWidget(checkBox_001, 1, 0, 1, 1);

        checkBox_101 = new QCheckBox(groupBox);
        checkBox_101->setObjectName(QString::fromUtf8("checkBox_101"));

        gridLayout->addWidget(checkBox_101, 1, 1, 1, 1);

        checkBox_010 = new QCheckBox(groupBox);
        checkBox_010->setObjectName(QString::fromUtf8("checkBox_010"));

        gridLayout->addWidget(checkBox_010, 2, 0, 1, 1);

        checkBox_110 = new QCheckBox(groupBox);
        checkBox_110->setObjectName(QString::fromUtf8("checkBox_110"));

        gridLayout->addWidget(checkBox_110, 2, 1, 1, 1);

        checkBox_011 = new QCheckBox(groupBox);
        checkBox_011->setObjectName(QString::fromUtf8("checkBox_011"));

        gridLayout->addWidget(checkBox_011, 3, 0, 1, 1);

        checkBox_111 = new QCheckBox(groupBox);
        checkBox_111->setObjectName(QString::fromUtf8("checkBox_111"));

        gridLayout->addWidget(checkBox_111, 3, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        pushButton_ok = new QPushButton(verticalLayoutWidget);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));

        verticalLayout->addWidget(pushButton_ok);


        retranslateUi(Form_task);

        QMetaObject::connectSlotsByName(Form_task);
    } // setupUi

    void retranslateUi(QWidget *Form_task)
    {
        Form_task->setWindowTitle(QCoreApplication::translate("Form_task", "Form", nullptr));
        groupBox->setTitle(QString());
        checkBox_000->setText(QCoreApplication::translate("Form_task", "CheckBox", nullptr));
        checkBox_100->setText(QCoreApplication::translate("Form_task", "CheckBox", nullptr));
        checkBox_001->setText(QCoreApplication::translate("Form_task", "CheckBox", nullptr));
        checkBox_101->setText(QCoreApplication::translate("Form_task", "CheckBox", nullptr));
        checkBox_010->setText(QCoreApplication::translate("Form_task", "CheckBox", nullptr));
        checkBox_110->setText(QCoreApplication::translate("Form_task", "CheckBox", nullptr));
        checkBox_011->setText(QCoreApplication::translate("Form_task", "CheckBox", nullptr));
        checkBox_111->setText(QCoreApplication::translate("Form_task", "CheckBox", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("Form_task", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_task: public Ui_Form_task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_TASK_H
