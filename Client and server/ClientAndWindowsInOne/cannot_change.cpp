#include "cannot_change.h"
#include "ui_cannot_change.h"

cannot_change::cannot_change(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cannot_change)
{
    ui->setupUi(this);
}

cannot_change::~cannot_change()
{
    delete ui;
}
