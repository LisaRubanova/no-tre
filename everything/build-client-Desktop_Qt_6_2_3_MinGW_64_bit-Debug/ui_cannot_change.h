/********************************************************************************
** Form generated from reading UI file 'cannot_change.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANNOT_CHANGE_H
#define UI_CANNOT_CHANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cannot_change
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QWidget *cannot_change)
    {
        if (cannot_change->objectName().isEmpty())
            cannot_change->setObjectName(QString::fromUtf8("cannot_change"));
        cannot_change->resize(400, 300);
        label = new QLabel(cannot_change);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 50, 321, 20));
        label_2 = new QLabel(cannot_change);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(190, 80, 66, 18));
        label_3 = new QLabel(cannot_change);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 100, 221, 20));
        label_4 = new QLabel(cannot_change);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(110, 150, 181, 18));
        label_5 = new QLabel(cannot_change);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(15, 200, 381, 20));
        label_5->setTextFormat(Qt::AutoText);
        label_6 = new QLabel(cannot_change);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(90, 220, 231, 20));

        retranslateUi(cannot_change);

        QMetaObject::connectSlotsByName(cannot_change);
    } // setupUi

    void retranslateUi(QWidget *cannot_change)
    {
        cannot_change->setWindowTitle(QCoreApplication::translate("cannot_change", "Form", nullptr));
        label->setText(QCoreApplication::translate("cannot_change", "You cannot change this group, it already exists, ", nullptr));
        label_2->setText(QCoreApplication::translate("cannot_change", "or", nullptr));
        label_3->setText(QCoreApplication::translate("cannot_change", "one of students already in group.", nullptr));
        label_4->setText(QCoreApplication::translate("cannot_change", "Please, check students list!", nullptr));
        label_5->setText(QCoreApplication::translate("cannot_change", "Note: remember, you cannot add students with the same ", nullptr));
        label_6->setText(QCoreApplication::translate("cannot_change", "names and surnames in one group!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cannot_change: public Ui_cannot_change {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANNOT_CHANGE_H
