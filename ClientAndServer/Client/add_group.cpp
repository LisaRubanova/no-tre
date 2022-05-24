#include "add_group.h"
#include "ui_add_group.h"

add_group::add_group(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_group)
{
    ui->setupUi(this);
    ui->lineEdit_groupNum->setFocus(Qt::TabFocusReason);
}

add_group::~add_group()
{
    delete ui;
}

void add_group::on_pushButton_clicked()
{
    QString n1, s1, n2, s2, n3, s3, n4, s4, n5, s5, n6, s6, n7, s7, n8, s8, n9, s9 = " ";

    QString group_num = ui->lineEdit_groupNum->text();

    n1 = ui->lineEdit->text();
    s1 = ui->lineEdit_2->text();
    if (s1 == "" ){
        n1 = s1 = " ";
    }

    n2 = ui->lineEdit_3->text();
    s2 = ui->lineEdit_4->text();
    if (s2 == "" ){
        n2 = s2 = " ";
    }

    n3 = ui->lineEdit_5->text();
    s3 = ui->lineEdit_6->text();
    if (s3 == "" ){
        n3 = s3 = " ";
    }

    n4 = ui->lineEdit_7->text();
    s4 = ui->lineEdit_8->text();
    if (s4 == "" ){
        n4 = s4 = " ";
    }

    n5 = ui->lineEdit_9->text();
    s5 = ui->lineEdit_10->text();
    if (s5 == "" ){
        n5 = s5 = " ";
    }

    n6 = ui->lineEdit_11->text();
    s6 = ui->lineEdit_12->text();
    if (s6 == "" ){
        n6 = s6 = " ";
    }

    n7 = ui->lineEdit_13->text();
    s7 = ui->lineEdit_14->text();
    if (s7 == "" ){
        n7 = s7 = " ";
    }

    n8 = ui->lineEdit_15->text();
    s8 = ui->lineEdit_16->text();
    if (s8 == "" ){
        n8 = s8 = " ";
    }

    n9 = ui->lineEdit_17->text();
    s9 = ui->lineEdit_18->text();
    if (s9 == "" ){
        n9 = s9 = " ";
    }

    new_group(group_num, n1, s1, n2, s2, n3, s3, n4, s4, n5, s5, n6, s6, n7, s7, n8, s8, n9, s9);

    hide();
}

