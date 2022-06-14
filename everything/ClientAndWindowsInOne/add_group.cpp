#include "add_group.h"
#include "ui_add_group.h"

add_group::add_group(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_group)
{
    changes = new cannot_change;
    ui->setupUi(this);
    ui->lineEdit_groupNum->setFocus(Qt::TabFocusReason);
}

add_group::~add_group()
{
    delete ui;
}

void add_group::no_changes(){
    changes->show();
}

void add_group::clean(){
    ui->lineEdit_groupNum->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
    ui->lineEdit_11->clear();
    ui->lineEdit_12->clear();
    ui->lineEdit_13->clear();
    ui->lineEdit_14->clear();
    ui->lineEdit_15->clear();
    ui->lineEdit_16->clear();
    ui->lineEdit_17->clear();
    ui->lineEdit_18->clear();
}

void add_group::on_pushButton_clicked()
{
    QString group_num = ui->lineEdit_groupNum->text();
    QRegularExpression re("[1-9]{3}-[1-9]{3}");
    QRegularExpressionMatch match = re.match(group_num);
    if(match.hasMatch()){
        QString n1, s1, n2, s2, n3, s3, n4, s4, n5, s5, n6, s6, n7, s7, n8, s8, n9, s9 = " ";

        n1 = ui->lineEdit->text();
        s1 = ui->lineEdit_2->text();
        if (s1 == "" || n1 == ""){
            n1 = s1 = " ";
        }

        n2 = ui->lineEdit_3->text();
        s2 = ui->lineEdit_4->text();
        if (s2 == "" || n2 == ""){
            n2 = s2 = " ";
        }

        n3 = ui->lineEdit_5->text();
        s3 = ui->lineEdit_6->text();
        if (s3 == "" || n3 == ""){
            n3 = s3 = " ";
        }

        n4 = ui->lineEdit_7->text();
        s4 = ui->lineEdit_8->text();
        if (s4 == "" || n4 == ""){
            n4 = s4 = " ";
        }

        n5 = ui->lineEdit_9->text();
        s5 = ui->lineEdit_10->text();
        if (s5 == "" || n5 == ""){
            n5 = s5 = " ";
        }

        n6 = ui->lineEdit_11->text();
        s6 = ui->lineEdit_12->text();
        if (s6 == "" || n6 == ""){
            n6 = s6 = " ";
        }

        n7 = ui->lineEdit_13->text();
        s7 = ui->lineEdit_14->text();
        if (s7 == "" || n7 == ""){
            n7 = s7 = " ";
        }

        n8 = ui->lineEdit_15->text();
        s8 = ui->lineEdit_16->text();
        if (s8 == "" || n8 == ""){
            n8 = s8 = " ";
        }

        n9 = ui->lineEdit_17->text();
        s9 = ui->lineEdit_18->text();
        if (s9 == "" || n9 == ""){
            n9 = s9 = " ";
        }
        QMap<int,QString> names {{1,n1}, {2,n2}, {3,n3}, {4,n4}, {5,n5}, {6,n6}, {7,n7}, {8,n8}, {9,n9}};
        QMap<int,QString> surnames {{1,s1}, {2,s2}, {3,s3}, {4,s4}, {5,s5}, {6,s6}, {7,s7}, {8,s8}, {9,s9}};
        bool flag = true;
        for (int i = 1; i <= 9; ++i){
            for(int j = i+1; j <= 10; ++j){
                //qDebug() << i << "names" << names.value(i) << "and" << names.value(j);
                //qDebug() << "surnames" << surnames.value(i) << "and" << surnames.value(j);
                if (names.value(i) == names.value(j) && surnames.value(i) == surnames.value(j) && names.value(i) != " " && surnames.value(j) != " "){
                    qDebug() << "same thing";
                    flag = false;
                    no_changes();
                }
            }

        }
        if(flag){
            new_group(group_num, n1, s1, n2, s2, n3, s3, n4, s4, n5, s5, n6, s6, n7, s7, n8, s8, n9, s9);
        }

        connect(client::getInstance(),&client::you_cannot,this, &add_group::no_changes);
        connect(client::getInstance(),&client::student_in_group,this, &add_group::no_changes);
        clean();
    }
    else{
        clean();
    }

}

