/********************************************************************************
** Form generated from reading UI file 'not_allowed.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOT_ALLOWED_H
#define UI_NOT_ALLOWED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_not_allowed
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *not_allowed)
    {
        if (not_allowed->objectName().isEmpty())
            not_allowed->setObjectName(QString::fromUtf8("not_allowed"));
        not_allowed->resize(380, 247);
        label = new QLabel(not_allowed);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 70, 501, 21));
        label_2 = new QLabel(not_allowed);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 120, 201, 18));
        label_3 = new QLabel(not_allowed);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 90, 191, 20));

        retranslateUi(not_allowed);

        QMetaObject::connectSlotsByName(not_allowed);
    } // setupUi

    void retranslateUi(QWidget *not_allowed)
    {
        not_allowed->setWindowTitle(QCoreApplication::translate("not_allowed", "Form", nullptr));
        label->setText(QCoreApplication::translate("not_allowed", "You are not allowed to see statistic of this group ", nullptr));
        label_2->setText(QCoreApplication::translate("not_allowed", "Please, check group number.", nullptr));
        label_3->setText(QCoreApplication::translate("not_allowed", "or this group doesn't exist!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class not_allowed: public Ui_not_allowed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOT_ALLOWED_H
