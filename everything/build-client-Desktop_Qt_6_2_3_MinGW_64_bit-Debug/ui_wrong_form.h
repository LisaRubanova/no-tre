/********************************************************************************
** Form generated from reading UI file 'wrong_form.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WRONG_FORM_H
#define UI_WRONG_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wrong_form
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *wrong_form)
    {
        if (wrong_form->objectName().isEmpty())
            wrong_form->setObjectName(QString::fromUtf8("wrong_form"));
        wrong_form->resize(394, 293);
        label = new QLabel(wrong_form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 100, 201, 20));
        label_2 = new QLabel(wrong_form);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 150, 281, 20));
        label_3 = new QLabel(wrong_form);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 170, 81, 20));
        pushButton = new QPushButton(wrong_form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 230, 100, 20));
        pushButton_2 = new QPushButton(wrong_form);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 230, 100, 20));

        retranslateUi(wrong_form);

        QMetaObject::connectSlotsByName(wrong_form);
    } // setupUi

    void retranslateUi(QWidget *wrong_form)
    {
        wrong_form->setWindowTitle(QCoreApplication::translate("wrong_form", "Form", nullptr));
        label->setText(QCoreApplication::translate("wrong_form", "Wrong username or password.", nullptr));
        label_2->setText(QCoreApplication::translate("wrong_form", "Please, check for spelling your credentials", nullptr));
        label_3->setText(QCoreApplication::translate("wrong_form", "or register.", nullptr));
        pushButton->setText(QCoreApplication::translate("wrong_form", "OK", nullptr));
        pushButton_2->setText(QCoreApplication::translate("wrong_form", "Registration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class wrong_form: public Ui_wrong_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WRONG_FORM_H
