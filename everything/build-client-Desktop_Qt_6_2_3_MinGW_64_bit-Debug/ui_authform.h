/********************************************************************************
** Form generated from reading UI file 'authform.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHFORM_H
#define UI_AUTHFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthForm
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_1log;
    QLineEdit *lineEdit_4name;
    QLineEdit *lineEdit_2pass;
    QRadioButton *radioButton_student;
    QLineEdit *lineEdit_3email;
    QLineEdit *lineEdit_5surname;
    QRadioButton *radioButton_teacher;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButtonback_to_auth;
    QPushButton *pushButton_reg;
    QPushButton *pushButton_ok;
    QLabel *label_note;

    void setupUi(QWidget *AuthForm)
    {
        if (AuthForm->objectName().isEmpty())
            AuthForm->setObjectName(QString::fromUtf8("AuthForm"));
        AuthForm->resize(418, 366);
        layoutWidget = new QWidget(AuthForm);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 40, 235, 308));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_1log = new QLineEdit(layoutWidget);
        lineEdit_1log->setObjectName(QString::fromUtf8("lineEdit_1log"));

        gridLayout->addWidget(lineEdit_1log, 1, 0, 1, 1);

        lineEdit_4name = new QLineEdit(layoutWidget);
        lineEdit_4name->setObjectName(QString::fromUtf8("lineEdit_4name"));

        gridLayout->addWidget(lineEdit_4name, 4, 0, 1, 1);

        lineEdit_2pass = new QLineEdit(layoutWidget);
        lineEdit_2pass->setObjectName(QString::fromUtf8("lineEdit_2pass"));
        lineEdit_2pass->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_2pass, 2, 0, 1, 1);

        radioButton_student = new QRadioButton(layoutWidget);
        radioButton_student->setObjectName(QString::fromUtf8("radioButton_student"));

        gridLayout->addWidget(radioButton_student, 6, 0, 1, 1);

        lineEdit_3email = new QLineEdit(layoutWidget);
        lineEdit_3email->setObjectName(QString::fromUtf8("lineEdit_3email"));

        gridLayout->addWidget(lineEdit_3email, 3, 0, 1, 1);

        lineEdit_5surname = new QLineEdit(layoutWidget);
        lineEdit_5surname->setObjectName(QString::fromUtf8("lineEdit_5surname"));

        gridLayout->addWidget(lineEdit_5surname, 5, 0, 1, 1);

        radioButton_teacher = new QRadioButton(layoutWidget);
        radioButton_teacher->setObjectName(QString::fromUtf8("radioButton_teacher"));

        gridLayout->addWidget(radioButton_teacher, 7, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolButtonback_to_auth = new QToolButton(layoutWidget);
        toolButtonback_to_auth->setObjectName(QString::fromUtf8("toolButtonback_to_auth"));

        horizontalLayout->addWidget(toolButtonback_to_auth);

        pushButton_reg = new QPushButton(layoutWidget);
        pushButton_reg->setObjectName(QString::fromUtf8("pushButton_reg"));
        pushButton_reg->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(pushButton_reg);

        pushButton_ok = new QPushButton(layoutWidget);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(pushButton_ok);


        gridLayout->addLayout(horizontalLayout, 8, 0, 1, 1);

        label_note = new QLabel(AuthForm);
        label_note->setObjectName(QString::fromUtf8("label_note"));
        label_note->setGeometry(QRect(40, 10, 341, 20));
        QWidget::setTabOrder(lineEdit_2pass, pushButton_ok);
        QWidget::setTabOrder(pushButton_ok, radioButton_student);
        QWidget::setTabOrder(radioButton_student, radioButton_teacher);
        QWidget::setTabOrder(radioButton_teacher, lineEdit_3email);
        QWidget::setTabOrder(lineEdit_3email, toolButtonback_to_auth);
        QWidget::setTabOrder(toolButtonback_to_auth, pushButton_reg);
        QWidget::setTabOrder(pushButton_reg, lineEdit_5surname);
        QWidget::setTabOrder(lineEdit_5surname, lineEdit_4name);
        QWidget::setTabOrder(lineEdit_4name, lineEdit_1log);

        retranslateUi(AuthForm);

        QMetaObject::connectSlotsByName(AuthForm);
    } // setupUi

    void retranslateUi(QWidget *AuthForm)
    {
        AuthForm->setWindowTitle(QCoreApplication::translate("AuthForm", "Form", nullptr));
        lineEdit_1log->setPlaceholderText(QCoreApplication::translate("AuthForm", "login", nullptr));
        lineEdit_4name->setText(QString());
        lineEdit_4name->setPlaceholderText(QCoreApplication::translate("AuthForm", "name", nullptr));
        lineEdit_2pass->setPlaceholderText(QCoreApplication::translate("AuthForm", "password", nullptr));
        radioButton_student->setText(QCoreApplication::translate("AuthForm", "student", nullptr));
        lineEdit_3email->setText(QString());
        lineEdit_3email->setPlaceholderText(QCoreApplication::translate("AuthForm", "email", nullptr));
        lineEdit_5surname->setPlaceholderText(QCoreApplication::translate("AuthForm", "surname", nullptr));
        radioButton_teacher->setText(QCoreApplication::translate("AuthForm", "teacher", nullptr));
        toolButtonback_to_auth->setText(QCoreApplication::translate("AuthForm", "  <-  ", nullptr));
        pushButton_reg->setText(QCoreApplication::translate("AuthForm", "Registration", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("AuthForm", "OK", nullptr));
        label_note->setText(QCoreApplication::translate("AuthForm", "Please, note: every field has a limit - 100 characters!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthForm: public Ui_AuthForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHFORM_H
