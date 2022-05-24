#include "form_statistic_teacher.h"
#include "ui_form_statistic_teacher.h"

Form_statistic_teacher::Form_statistic_teacher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_statistic_teacher)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("Hello"));
}

Form_statistic_teacher::~Form_statistic_teacher()
{
    delete ui;
}
