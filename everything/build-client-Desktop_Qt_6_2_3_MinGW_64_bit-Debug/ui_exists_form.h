/********************************************************************************
** Form generated from reading UI file 'exists_form.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXISTS_FORM_H
#define UI_EXISTS_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_exists_form
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QWidget *exists_form)
    {
        if (exists_form->objectName().isEmpty())
            exists_form->setObjectName(QString::fromUtf8("exists_form"));
        exists_form->resize(400, 300);
        label = new QLabel(exists_form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 110, 211, 20));
        label_2 = new QLabel(exists_form);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 140, 191, 20));
        pushButton = new QPushButton(exists_form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 210, 83, 29));

        retranslateUi(exists_form);

        QMetaObject::connectSlotsByName(exists_form);
    } // setupUi

    void retranslateUi(QWidget *exists_form)
    {
        exists_form->setWindowTitle(QCoreApplication::translate("exists_form", "Form", nullptr));
        label->setText(QCoreApplication::translate("exists_form", "This username is already in use.", nullptr));
        label_2->setText(QCoreApplication::translate("exists_form", "Please, choose another one.", nullptr));
        pushButton->setText(QCoreApplication::translate("exists_form", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class exists_form: public Ui_exists_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXISTS_FORM_H
