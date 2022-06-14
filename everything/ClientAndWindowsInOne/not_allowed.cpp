#include "not_allowed.h"
#include "ui_not_allowed.h"

not_allowed::not_allowed(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::not_allowed)
{
    ui->setupUi(this);
}

not_allowed::~not_allowed()
{
    delete ui;
}
